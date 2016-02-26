#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int T=0,N,j=0,K,sum;
    scanf("%d",&T);
    while(T--)
    {
        N=0,sum=0;
        string line;
       scanf("%d",&N);
       printf("Case %d:\n",j+1);
       while(N--)
       {
           cin>>line;
           if(line=="donate")
           {
               scanf("%d",&K);
               sum=sum+K;
           }
           else if(line=="report")
            printf("%d\n",sum);
       }
       j++;
    }
    return 0;
}




