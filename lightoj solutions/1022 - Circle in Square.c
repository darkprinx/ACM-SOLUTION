#include<stdio.h>
#define PI 3.1415926535897
int main()
{
    int i,n,j=1;
    double r[1000],sh,a; // to avoid precision problem we used DOUBLE
    scanf("%d",&n);
    for(i=0;i<n;i++,j++)
    {
        scanf("%lf",&r[i]);
        a=r[i]*2;
        sh=(a*a)-PI*(r[i]*r[i]);
        printf("Case %d: %.02lf\n",j,sh);
    }
    return 0;

}

