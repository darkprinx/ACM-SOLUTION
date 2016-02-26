#include<stdio.h>
int main()
{
    int x,ara[1000],i,n,j,sum;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        sum=0;
        for(j=0;j<x;j++)
        {
            scanf(" %d",&ara[j]);
            if(ara[j]>0)
            {
               sum=sum+ara[j];
            }
        }
        printf("Case %d: %d\n",i,sum);
    }
 return 0;
}

