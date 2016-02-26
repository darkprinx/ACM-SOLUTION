#include<stdio.h>
int main()
{
    long long int N[10000],M[10000],W[10000],j,x;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&x);
        if(x%2==0)
        {
            W[i]=x;
        for(j=2;j<W[i];j++)
        {
             if(W[i]%j==0)
            {
                M[i]=j;
                if(M[i]%2==0)
                 {
                   N[i]=W[i]/M[i];
                 }

            }
            if((N[i]%2==1)&&(M[i]!=N[i]))
                 {
                     printf("Case %d: %lld %lld\n",i+1,N[i],M[i]);
                     break;
                 }
        }

        }
        else
        {
            printf("Case %d: Impossible\n",i+1);
        }
    }


    return 0;
}
