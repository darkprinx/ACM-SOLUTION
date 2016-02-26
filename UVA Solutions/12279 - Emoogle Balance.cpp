#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int N,x,c,i=1;
    while(scanf("%d",&N)==1&&N!=0)
    {
        c=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&x);
            if(x==0)
                c++;
        }
        printf("Case %d: %d\n",i,N-c*2);
        i++;
    }
}
