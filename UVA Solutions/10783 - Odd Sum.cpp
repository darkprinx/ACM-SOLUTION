#include<stdio.h>
#include<math.h>
#define loop1(a,b) for(int i=int(a);i<=int(b);i++)
#define loop2(a,b) for(int j=int(a);j<=int(b);j++)
int main()
{
    int n,a,b,sum;
    scanf("%d",&n);
    loop1(1,n)
    {
        sum=0;
        scanf("%d%d",&a,&b);
        loop2(a,b)
        {
            if(j%2==1)
                sum+=j;
        }
        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}

