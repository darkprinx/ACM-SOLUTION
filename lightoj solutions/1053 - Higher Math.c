#include<stdio.h>
#include <math.h>
int main()
{
    long int n,a[200],b[200],c[200],i,j,A[200],C[200],B[200],A1,B1,C1;
    scanf("%d",&n);
    for(i=0,j=1;i<n;i++,j++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        A[i]=c[i]*c[i]+b[i]*b[i];
        A1=a[i]*a[i];
        B[i]=a[i]*a[i]+c[i]*c[i];
        B1=b[i]*b[i];
        C[i]=a[i]*a[i]+b[i]*b[i];
        C1=c[i]*c[i];
        if(A[i]==A1||B[i]==B1||C[i]==C1)
        {
          printf("Case %d: yes\n",j);
        }
        else
        {
            printf("Case %d: no\n",j);
        }
    }
    return 0;
}


