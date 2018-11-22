/*
 * Copyright (c) 2015-2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== uartecho.c ========
 */
#include <stdint.h>
#include <stddef.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>
#include <ti/drivers/I2C.h>
#include <ti/drivers/SPI.h>
#include <ti/drivers/Watchdog.h>
#include <ti/drivers/Timer.h>
#include <ti/drivers/ADC.h>
#include <ti/sysbios/knl/Clock.h>

/* Example/Board Header files */
#include "ADCS_Board.h"

#include "satellite.h"
#include "devices.h"

#include "INA226.h"
#include "TMP100.h"

#include "parameters.h"
#include "detumble_algo.h"
#include "osal.h"

extern UART_Handle uart_dbg_bus;
extern UART_Handle uart_pq9_bus;

bool start_flag = false;
//extern vector_t mag1Data = {34.3, 43, 54};
int16_t magData = {0,0,0};
extern int32_t loop_time = 0;

int len;
char uartTxBuffer[100];
/*
 *  ======== mainThread ========
 */
void *mainThread(void *arg0)
{
    /* Call driver init functions */
    GPIO_init();
    UART_init();
    I2C_init();
    SPI_init();
    Timer_init();
    ADC_init();
    Watchdog_init();

    uint32_t wdg_time = OSAL_sys_GetTick();
    uint32_t now_time;

    GPIO_write(EXT_WDG, 1);
    usleep(100);
    GPIO_write(EXT_WDG, 0);

    /* Turn on user LED */
    GPIO_write(PQ9_EN, 0);

    /*ECSS services start*/
    pkt_pool_INIT();
    device_init();
    init_parameters();
    OSAL_init();

    len = sprintf(uartTxBuffer, "[BMX]: Calibration mode\n");
    UART_write(uart_dbg_bus, uartTxBuffer, len);

    if(bmxMag_init()){
        len = sprintf(uartTxBuffer, "[BMX]: Calibrated and in Startup\n");
        UART_write(uart_dbg_bus, uartTxBuffer, len);
    }

    uint16_t boot_counter=0, size;
    uint8_t buf[4];

    //get_parameter(ADCS_boot_counter_param_id, &boot_counter, buf, &size);
    //boot_counter=0;
    //set_parameter(ADCS_boot_counter_param_id, boot_counter);

    get_parameter(ADCS_boot_counter_param_id, &boot_counter, buf, &size);
    boot_counter++;
    set_parameter(ADCS_boot_counter_param_id, boot_counter);


    start_flag = true;

    uint32_t sen_loop = 100000;

    /* Loop forever echoing */
    while (1) {
        now_time = OSAL_sys_GetTick();

        if(now_time - wdg_time > 15500) {
            GPIO_write(EXT_WDG, 1);
            usleep(34800);
            GPIO_write(EXT_WDG, 0);
            wdg_time = now_time;
        }

        set_parameter(SBSYS_reset_clr_int_wdg_param_id, NULL);

        update_device(ADCS_1_MON_DEV_ID);
        usleep(1);
        update_device(ADCS_2_MON_DEV_ID);
        usleep(1);
        update_device(ADCS_3_MON_DEV_ID);
        usleep(1);
        update_device(ADCS_4_MON_DEV_ID);
        usleep(1);

        update_device(ADCS_TEMP_DEV_ID);
        usleep(1);

        get_parameter(SBSYS_sensor_loop_param_id, &sen_loop, buf, &size);
        usleep(sen_loop);
    }
}

/*  ======== ecssThread ========
 *  This thread runs on a higher priority, since wdg pin
 *  has to be ready for master.
 */
void *pqReceiveThread(void *arg0)
{

    while(!start_flag) {
        usleep(1000);
    }

    /* Loop forever */
    while (1) {
         import_pkt();
         usleep(1);
    }

    return (NULL);
}

void *pqTransmitThread(void *arg0)
{

    while(!start_flag) {
        usleep(1000);
    }

    /* Loop forever */
    while (1) {
         export_pkt();
         usleep(1);
    }

    return (NULL);
}

char msg[100];


/*  ======== senThread ========
 *  This a dbg thread for outputing sensor readings
 */
void *pqDetThread(void *arg0)
{

    while(!start_flag) {
        usleep(1000);
    }
    uint32_t start_time = 0;
    uint32_t stop_time = 0;

    while (1) {
        start_time = Clock_getTicks();
        bmxMag_read_calib_data(magData);
        /*
        // make sure to leave counts below static, they aren't remembered by controlLoop,
        // they are just incremented by controlLoop
        static unsigned int c_tumb = 0;
        static unsigned int c_detumb = 0;
        vector_t b1_raw = {34.3, 43, 54};
        vector_t b2_raw = {31.3, 41, 51};
        vector_t s_on     = {0,0,0};
        vector_t t_on     = {0,0,0};
        vector_t p_tumb   = {0,0,0};

        controlLoop(b1_raw, b2_raw, &s_on, &t_on, &p_tumb, &c_tumb, &c_detumb);
        usleep(1000);

        */
        stop_time = Clock_getTicks();
        loop_time = stop_time - start_time;
    }

    return (NULL);
}
