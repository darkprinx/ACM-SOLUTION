#include<stdio.h>
int main()
{
    int n,i,T,a,b,sum;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        a=n/2;
        b=n-a;
        printf("%d %d\n",a,b);
    }
    return 0;

}
