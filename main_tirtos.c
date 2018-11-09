/*
 * Copyright (c) 2016-2017, Texas Instruments Incorporated
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
 *  ======== main_tirtos.c ========
 */
#include <stdint.h>

/* POSIX Header files */
#include <pthread.h>

/* RTOS header files */
#include <ti/sysbios/BIOS.h>

/* Example/Board Header files */
#include "ADCS_Board.h"

extern void *mainThread(void *arg0);
extern void *pqReceiveThread(void *arg0);
extern void *pqTransmitThread(void *arg0);
extern void *dbgThread(void *arg0);
extern void *pqDetThread(void *arg0);

/* Stack size in bytes */
#define THREADSTACKSIZE    4096

/*
 *  ======== main ========
 */
int main(void)
{
    pthread_t           thread;
    pthread_attr_t      attrs;
    struct sched_param  priParam;
    int                 retc;
    int                 detachState;

    /* Call driver init functions */
    Board_initGeneral();

    /* Set priority and stack size attributes */
    pthread_attr_init(&attrs);
    priParam.sched_priority = 1;

    detachState = PTHREAD_CREATE_DETACHED;
    retc = pthread_attr_setdetachstate(&attrs, detachState);
    if (retc != 0) {
        /* pthread_attr_setdetachstate() failed */
        while (1);
    }

    pthread_attr_setschedparam(&attrs, &priParam);

    retc |= pthread_attr_setstacksize(&attrs, 4096);
    if (retc != 0) {
        /* pthread_attr_setstacksize() failed */
        while (1);
    }

    retc = pthread_create(&thread, &attrs, mainThread, NULL);
    if (retc != 0) {
        /* pthread_create() failed */
        while (1);
    }

    pthread_t           thread_pqReceive;
    pthread_attr_t      attrs2;
    struct sched_param  priParam2;

    /* Set priority and stack size attributes */
    pthread_attr_init(&attrs2);
    priParam.sched_priority = 2;

    detachState = PTHREAD_CREATE_DETACHED;
    retc = pthread_attr_setdetachstate(&attrs2, detachState);
    if (retc != 0) {
        /* pthread_attr_setdetachstate() failed */
        while (1);
    }

    pthread_attr_setschedparam(&attrs2, &priParam2);

    retc |= pthread_attr_setstacksize(&attrs2, 1024);
    if (retc != 0) {
        /* pthread_attr_setstacksize() failed */
        while (1);
    }

    /* Create ecss thread */
    retc = pthread_create(&thread_pqReceive, &attrs2, pqReceiveThread, (void* )0);
    if (retc != 0) {
        /* pthread_create() failed */
        while (1);
     }

     pthread_t           thread_pqTransmit;
     pthread_attr_t      attrs3;
     struct sched_param  priParam3;

     /* Set priority and stack size attributes */
     pthread_attr_init(&attrs3);
     priParam.sched_priority = 3;

     detachState = PTHREAD_CREATE_DETACHED;
     retc = pthread_attr_setdetachstate(&attrs3, detachState);
     if (retc != 0) {
         /* pthread_attr_setdetachstate() failed */
         while (1);
     }

     pthread_attr_setschedparam(&attrs3, &priParam3);

     retc |= pthread_attr_setstacksize(&attrs3, 1024);
     if (retc != 0) {
         /* pthread_attr_setstacksize() failed */
         while (1);
     }

     /* Create ecss thread */
     retc = pthread_create(&thread_pqTransmit, &attrs3, pqTransmitThread, (void* )0);
     if (retc != 0) {
         /* pthread_create() failed */
         while (1);
    }

     pthread_t           thread_pqDet;
     pthread_attr_t      attrs4;
     struct sched_param  priParam4;

     /* Set priority and stack size attributes */
     pthread_attr_init(&attrs4);
     priParam.sched_priority = 3;

     detachState = PTHREAD_CREATE_DETACHED;
     retc = pthread_attr_setdetachstate(&attrs4, detachState);
     if (retc != 0) {
         /* pthread_attr_setdetachstate() failed */
         while (1);
     }

     pthread_attr_setschedparam(&attrs4, &priParam4);

     retc |= pthread_attr_setstacksize(&attrs4, 1024);
     if (retc != 0) {
         /* pthread_attr_setstacksize() failed */
         while (1);
     }

     /* Create ecss thread */
     retc = pthread_create(&thread_pqDet, &attrs4, pqDetThread, (void* )0);
     if (retc != 0) {
         /* pthread_create() failed */
         while (1);
    }

    BIOS_start();

    return (0);
}
