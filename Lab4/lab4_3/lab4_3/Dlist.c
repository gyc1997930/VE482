//
//  Dlist.c
//  lab4_3
//
//  Created by 季星佑 on 2017/10/25.
//  Copyright © 2017年 季星佑. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dlist.h"

dlist createDlist(dlistValueType type)
{
    dlist** l=0;
    dlistValue v;
    switch (type) {
        case 0x01:
            *l=malloc(sizeof(v.intValue));
            break;
        case 0x02:
            *l=malloc(sizeof(v.strValue));
            break;
        case 0x03:
            *l=malloc(sizeof(v.doubleValue));
            break;
        case 0x04:
            *l=malloc(sizeof(v));
            break;
        default:
            break;
    }
    return *l;
}

int dlistIsEmpty(dlist_const this)
{
    if(!this)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void dlistAppend(dlist this, const char* key, dlistValue value)
{
    ////
}

void dlistSort(dlist_const this, dlist listDst, dlistSortMethod method)
{
    if(!this)
    {
        return;
    }
    else
    {
        //qsort(listDst,method);
    }
}

void dlistPrint(dlist_const this)
{
    if(!this)
    {
        return;
    }
    else
    {
        printf("%s",this);
    }
}

void dlistFree(dlist this)
{
    if(!this)
    {
        return;
    }
    else
    {
        free(this);
    }
}
