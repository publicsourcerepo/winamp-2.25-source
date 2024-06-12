//
//  nxonce.c
//  nx
//
//  Created by Ben Allison on 1/5/12.
//  Copyright (c) 2012 Nullsoft, Inc. All rights reserved.
//
#ifdef __amd64__
#include "nxonce.h"

/* this ONLY works because of the strict(ish) memory ordering of the AMD64/x86 processors. 
 Don't use this implementation for a processor that has loose memory ordering restriction (e.g. ARM, PowerPC)
 see http://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf
 */
void NXOnce(nx_once_t once, int (NX_ONCE_API *init_fn)(nx_once_t, void *, void **), void *param)
{
    if (once->status)
        return;
    
    pthread_mutex_lock(&once->mutex);
    if (once->status)
    {
        pthread_mutex_unlock(&once->mutex);
        return;
    }
    
    init_fn(once, param, 0);
    // benski> not important for the AMD64, but on processors with weak memory-order on stores, once->status might set to 1 BEFORE all stores from init_fn complete!
    once->status = 1;
    pthread_mutex_unlock(&once->mutex);
}
#endif