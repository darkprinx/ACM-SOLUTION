#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int cond(int number)
{
    if((number-1)%4==0||(number-3)%4==0)
        number=number +1;
    else if((number-2)%4==0)
        number=number+2;

 return number;
}

int main()
{
    int n,i;
    float a,b,sum;
    scanf("%d",&n);
    int x[n];
    for(i=0; i<n; i++)
    {
        scanf("%f%f",&a,&b);
        if((a>1&&b>2)||(a>2&&b>1))
        {
            if(a==2)
            {
                printf("Case %d: %d\n",i+1,cond(b));
            }
            else if(b==2)
            {
                printf("Case %d: %d\n",i+1,cond(a));
            }
            else
            {
            sum=a*(b/2);
            printf("Case %d: %.f\n",i+1,ceil(sum));
            }
        }

        else
            printf("Case %d: %.f\n",i+1,a*b);
    }
    return 0;
}
