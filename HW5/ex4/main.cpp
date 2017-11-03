//
//  main.cpp
//  ex4
//
//  Created by 季星佑 on 2017/11/2.
//  Copyright © 2017年 季星佑. All rights reserved.
//

#include <iostream>

#define P 10
#define R 5

using namespace std;

bool compare(int a[R],int b[R]);

bool stest(int Allocation[P][R],int Need[P][R],int Available[R]);

void rtest(int Allocation[P][R],int Need[P][R],int Available[R],int Request[R],int N);

void arr_copy(int a[R],int b[R]);

int main(int argc, const char * argv[])
{
    int Max[P][R],Allocation[P][R],Need[P][R],Available[R],Request[R];
    cout<<"Max_matrix: "<<endl;
    for(int i=0;i<P;++i)
    {
        for(int j=0;j<R;++j)
        {
            cin>>Max[i][j];
        }
    }
    cout<<"Allocation_matrix: "<<endl;
    for(int i=0;i<P;++i)
    {
        for(int j=0;j<R;++j)
        {
            cin>>Allocation[i][j];
        }
    }
    cout<<"Need_matrix: "<<endl;
    for(int i=0;i<P;++i)
    {
        for(int j=0;j<R;++j)
        {
            cin>>Need[i][j];
        }
    }
    cout<<"Available_matrix: "<<endl;
    for(int i=0;i<R;++i)
    {
        cin>>Available[i];
    }
    cout<<"Request_matrix: "<<endl;
    for(int i=0;i<R;++i)
    {
        cin>>Request[i];
    }
    if(stest(Allocation,Need,Available)==false)
    {
        cout<<"Unsafe state!"<<endl;
    }
    for(int i=0;i<R;++i)
    {
        cin>>Request[i];
    }
    int N;
    cin>>N;
    rtest(Allocation,Need,Available,Request,N);
    return 0;
}
/////////////////////
/////////////////////
bool compare(int a[R],int b[R])
{
    for(int i=0;i<R;++i)
    {
        if(a[i]<b[i])
        {
            return false;
        }
    }
    return true;
}

bool stest(int Allocation[P][R],int Need[P][R],int Available[R])
{
    bool finish[P]={false};
    int Available_copy[R];
    arr_copy(Available_copy,Available);
    int t[R];
    for(int i=0;i<P;++i)
    {
        for(int j=0;j<R;++j)
        {
            if(finish[i]==true)
            {
                continue;
            }
            else
            {
                for(int k=0;k<R;++k)
                {
                    t[k]=Need[j][k];
                }
                if(compare(Available_copy,t)==true)
                {
                    finish[i]=1;
                    for(int l=0;l<R;++l)
                    {
                        Available_copy[l]+=Allocation[j][l];
                    }
                }
            }
        }
    }
    for(int i=0;i<P;++i)
    {
        if(finish[i]==false)
        {
            return false;
        }
    }
    return true;
}

void arr_copy(int a[R],int b[R])
{
    for(int i=0;i<R;++i)
    {
        a[R]=b[R];
    }
}

void rtest(int Allocation[P][R],int Need[P][R],int Available[R],int Request[R],int N)
{
    int t[R];
    N--;
    for(int i=0;i<R;++i)
    {
        t[i]=Need[N][i];
    }
    if(compare(Available,Request)==true&&compare(t,Request)==true)
    {
        for(int i=0;i<R;++i)
        {
            Allocation[N][i]+=Request[i];
            Need[N][i]-=Request[i];
            Available[i]-=Request[i];
        }
        if(stest(Allocation,Need,Available)==false)
        {
            cout<<"Not allowed!"<<endl;
            cout<<"Recovery!"<<endl;
            for(int i=0;i<R;++i)
            {
                Allocation[N][i]-=Request[i];
                Need[N][i]+=Request[i];
                Available[i]+=Request[i];
            }
        }
        else
        {
            cout<<"Allowed!"<<endl;
        }
    }
    else
    {
        cout<<"Error!"<<endl;
    }
}
