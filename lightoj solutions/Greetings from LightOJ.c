#include<stdio.h>
int main()
{
    int T;
    int a[125],b[125],n,sum[125];
    scanf("%d",&n);
    for(T=1;T<=n;T++)
    {
        scanf("%d%d",&a[T],&b[T]);
        sum[T]=a[T]+b[T];
        printf("Case %d: %d\n",T,sum[T]);
    }
    return 0;
}
