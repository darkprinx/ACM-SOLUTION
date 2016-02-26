#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,*x,b,sum,j=1;
    scanf("%d",&n);
    x=new int[n];
    for(int i=0; i<n; i++)
    {
        sum=0;
        scanf("%d",&x[i]);
        while(x[i]!=0)
        {
            b=x[i]%2;
            if(b==1)
                sum++;
            x[i]=x[i]/2;
        }
        if(sum%2==0)
            printf("Case %d: even\n",j);
        else
            printf("Case %d: odd\n",j);
        j++;
    }
}
