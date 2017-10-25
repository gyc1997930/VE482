//
//  dlist.c
//  Lab4
//
//  Created by 季星佑 on 2017/10/17.
//  Copyright © 2017年 季星佑. All rights reserved.
//

#include "dlist.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct tagnode
{
    char *c;
    void *v;
    struct tagnode node;
}Node;

typedef struct tagdlist
{
    Node *first;
    Node *last;
    
}Dlist;
dlist createDlist(dlistValueType type)
{
    
}
