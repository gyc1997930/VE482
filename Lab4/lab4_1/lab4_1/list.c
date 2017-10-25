//
//  list.c
//  lab4_1
//
//  Created by 季星佑 on 2017/10/25.
//  Copyright © 2017年 季星佑. All rights reserved.
//

#include "list.h"

void init(List **l)
{
    *l=malloc(sizeof(List));
    (*l)->first=NULL;
    (*l)->len=0;
}

void list_free(List *l)
{
    Node *n=l->first;
    for(int i=0;i<l->len;++i)
    {
        n=n->next;
        free(l->first->c);
        free(l->first->v);
        free(l->first);
        l->first=n;
    }
    free(l);
}

Node *insert(List *l,char *c,void *v)
{
    Node *N;
    N=malloc(sizeof(Node));
    N->c=c;
    N->v=v;
    if(l->first==NULL)
    {
        N->next=NULL;
    }
    else
    {
        N->next=l->first;
    }
    l->first=N;
    l->len++;
    return N;
}

void lsort(List *l,int (*f)(void *, void *))
{
    if(l->len==0)
    {
        return;
    }
    Node *arr=malloc(sizeof(Node)* l->len);
    Node *temp=l->first;
    for(int i=0;i<l->len;++i)
    {
        memcpy(arr+i,temp,sizeof(Node));
        temp=temp->next;
    }
    qsort(arr,l->len,sizeof(Node),f);
    temp=l->first;
    for(int i=0;i<l->len;++i)
    {
        temp->c=arr[i].c;
        temp->v=arr[i].v;
        temp=temp->next;
    }
    free(arr);
}

void lprint(List *l,FILE *f,void(*print_mode)(FILE* f, void *))
{
    Node *N;
    N=l->first;
    for(int i=0;i<l->len;++i)
    {
        fprintf(f,"%s=",N->c);
        print_mode(f,N->v);
        fprintf(f,"\n");
        N=N->next;
    }
}
