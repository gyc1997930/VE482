//
//  main.c
//  hw3
//
//  Created by 季星佑 on 2017/10/17.
//  Copyright © 2017年 季星佑. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/////////////////////////////
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
/////////////////////////////
void INT_print(FILE *f,void *a)
{
    fprintf(f,"%d",*(int *)(a));
}

void DOUBLE_print(FILE *f,void *a)
{
    fprintf(f,"%f",*(double *)(a));
}

void STRING_print(FILE *f,void *a)
{
    fprintf(f,"%s",(char *)(a));
}

void (* print_mode[3])(FILE *file,void *)={INT_print,DOUBLE_print,STRING_print};//select the printing mode
/////////////////////////////
int INT_INC( void *a, void *b)
{
    int a_v=*(int *)(((Node *) a)->v);
    int b_v=*(int *)(((Node *) b)->v);
    if(a_v>=b_v)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int INT_DEC(void *a,void *b)
{
    int a_v=*(int *)(((Node *) a)->v);
    int b_v=*(int *)(((Node *) b)->v);
    if(a_v<=b_v)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int DOUBLE_INC(void *a,void *b)
{
    double a_v=*(double *)(((Node *) a)->v);
    double b_v=*(double *)(((Node *) b)->v);
    if(a_v>=b_v)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int DOUBLE_DEC(void *a,void *b)
{
    double a_v=*(double *)(((Node *) a)->v);
    double b_v=*(double *)(((Node *) b)->v);
    if(a_v<=b_v)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int STRING_INC(void *a,void *b)
{
    char *a_v=(char *)(((Node *) a)->v);
    char *b_v=(char *)(((Node *) b)->v);
    if(a_v>=b_v)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int STRING_DEC(void *a,void *b)
{
    char *a_v=(char *)(((Node *) a)->v);
    char *b_v=(char *)(((Node *) b)->v);
    if(a_v<=b_v)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Random(void *a,void *b)
{
    srand(time(0));
    return rand()%2;
}

int (* mode[3][3])(void *,void *)={{INT_INC,INT_DEC,Random},{DOUBLE_INC,DOUBLE_DEC,Random},{STRING_INC,STRING_DEC,Random}};//select the parameter for the qsort function
/////////////////////////////
typedef struct data
{
    int d;
    /*
     0 for int
     1 for double
     2 for char*
     */
}Data;

typedef struct type
{
    int t;
    /*
     0 for inc
     1 for dec
     2 for rand
     */
}Type;

void setData(Data D,int d)
{
    D.d=d;
}

void setType(Type T,int t)
{
    T.t=t;
}

char *Data_name[3]={"int.txt","double.txt","string.txt"};

char *Type_name[3]={"inc","dec","rand"};
/////////////////////////////
void file(char *buf,int d,int t)//create filename
{
    strcpy(buf,Type_name[t]);
    size_t len=strlen(buf);
    buf[len]='_';
    strcpy(buf+len+1,Data_name[d]);
}
/////////////////////////////
int main(int argc,char* argv[])
{
    char *buf;
    ssize_t size=50;
    buf=(char *)(malloc(size));
    Data D;
    Type T;
    int d=0;
    int t=0;
    for(D.d=0;D.d<3;++D.d)
    {
        file(buf,D.d,T.t=2);
        if(strcmp(buf,argv[1])==0)
        {
            d=D.d;
            setData(D,d);
            break;
        }
    }
    for (T.t=0;T.t<3;++T.t)
    {
        if(strcmp(Type_name[T.t],argv[2])==0)
        {
            t=T.t;
            setType(T,t);
            break;
        }
    }
    char *filename;
    filename=(char *)(malloc(20));
    file(filename,D.d,T.t=2);
    FILE *IN=NULL;
    IN=fopen(filename,"r");
    if(IN==NULL)
    {
        printf("Can not open file!\n");
        exit(0);
    }
    else
    {
        printf("reading %s\n",filename);
    }
    char buff[200]={0};
    List *l;
    init(&l);
    while(!feof(IN))
    {
        fgets(buff,200,IN);
        char *index;
        for(index=buff;index<buff+20;++index)
        {
            if(*index=='=')
            {
                break;
            }
        }
        *index='\0';
        char *str;
        str=(char *) malloc(sizeof(char)* (index-buff+1));
        strcpy(str,buff);
        void *v=NULL;
        switch(D.d)
        {
            case 0:
                v=malloc(sizeof(int));
                *((int *) v)=atoi(index+1);
                break;
            case 1:
                v=malloc(sizeof(double));
                *((double *) v)=strtod(index+1,NULL);
                break;
            case 2:
                strcpy(v,index+1);
            default:
                break;
        }
        insert(l,str,v);
    }
    fclose(IN);
    printf("sorting elements\n");
    for(T.t=0;T.t<3;++T.t)
    {
        if(strcmp(Type_name[T.t],argv[2])==0)
        {
            t=T.t;
            setType(T,t);
            break;
        }
    }
    lsort(l,mode[D.d][T.t]);
    file(filename,D.d,T.t);
    printf("writing %s\n",filename);
    FILE *OUT=NULL;
    OUT=fopen(filename,"w");
    lprint(l,OUT,print_mode[D.d]);
    fclose(OUT);
    list_free(l);
    free(filename);
    free(buf);
    return 0;
}
