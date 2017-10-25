//
//  list.h
//  lab4_1
//
//  Created by 季星佑 on 2017/10/25.
//  Copyright © 2017年 季星佑. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct tagNode
{
    char *c;
    void *v;
    struct tagNode *next;
}Node;

typedef struct tagList
{
    Node *first;
    int len;
}List;

void init(List **l);

void list_free(List *l);

Node *insert(List *l,char *c,void *v);

void lsort(List *l,int (*f)(void *, void *));

void lprint(List *l,FILE *f,void(*print_mode)(FILE* f, void *));

#endif /* list_h */
