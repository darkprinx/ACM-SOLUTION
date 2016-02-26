#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int SET[10005],money[10005];
int REP(int i)
{
    return i==SET[i]?i:SET[i]=REP(SET[i]);
}

int main()
{


    int T,t,N,n,M,m,i,j,ri,rj;
    scanf(" %d",&T);
    for(t=0; t<T; t++)
    {
        scanf(" %d %d",&N,&M);
        for(n=0; n<N; n++)
        {
            scanf(" %d",&money[n]);
            SET[n]=n;
        }
        for(m=0; m<M; m++)
        {
            scanf(" %d %d",&i,&j);
            ri = REP(i);
            rj = REP(j);
            if(ri!=rj)
            {
                SET[ri]=rj;
                money[rj]+=money[ri];
                money[ri]=0;
            }
        }
        bool flag=true;
        for(n=0; n<N; n++)
        {
            if(money[n]!=0)
                flag=false;

        }
        if(!flag)
            printf("IMPOSSIBLE\n");
        else
            printf("POSSIBLE\n");
    }
}
