//
//  main.c
//  lab4_2
//
//  Created by 季星佑 on 2017/10/25.
//  Copyright © 2017年 季星佑. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.h"
#include "readName.h"
#include "writeFile.h"

char *Data_name[3]={"int.txt","double.txt","string.txt"};

char *Type_name[3]={"inc","dec","rand"};

void (* print_mode[3])(FILE *file,void *)={INT_print,DOUBLE_print,STRING_print};//select the printing mode

int (* mode[3][3])(void *,void *)={{INT_INC,INT_DEC,Random},{DOUBLE_INC,DOUBLE_DEC,Random},{STRING_INC,STRING_DEC,Random}};//select the parameter for the qsort function

int main(int argc, const char * argv[])
{
    printf("Welcome, my lord!\n");
    printf("Please input file name: ");
    char *filename_buffer;
    filename_buffer=(char *)malloc(20);
    gets(filename_buffer);
    printf("Please input sorting mode: ");
    char *mode_buffer;
    mode_buffer=(char *)malloc(20);
    gets(mode_buffer);
    char *buf;
    ssize_t size=50;
    buf=(char *)(malloc(size));
    Data D;
    Type T;
    int d=0;
    int t=0;
    for(D.d=0;D.d<3;++D.d)
    {
        file(buf,Data_name[D.d],Type_name[T.t=2]);
        if(strcmp(buf,filename_buffer)==0)
        {
            d=D.d;
            setData(D,d);
            break;
        }
    }
    for (T.t=0;T.t<3;++T.t)
    {
        if(strcmp(Type_name[T.t],mode_buffer)==0)
        {
            t=T.t;
            setType(T,t);
            break;
        }
    }
    free(filename_buffer);
    free(mode_buffer);
    char *filename;
    filename=(char *)(malloc(20));
    FILE *IN=NULL;
    IN=fopen(filename_buffer,"r");
    if(IN==NULL)
    {
        printf("Can not open file!\n");
        exit(0);
    }
    else
    {
        printf("reading %s\n",filename_buffer);
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
        if(strcmp(Type_name[T.t],mode_buffer)==0)
        {
            t=T.t;
            setType(T,t);
            break;
        }
    }
    lsort(l,mode[D.d][T.t]);
    file(filename,Data_name[D.d],Type_name[T.t]);
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

