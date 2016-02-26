#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int t,n,ara[20],sum;
    double x,y;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        sum=0;
        cin>>n;
        for(int j=0;j<n;j++)
            cin>>ara[j];
        x=ceil((ara[0]-2)/5.0);
        for(int j=n-1,k=n-2;j>=1;j--,k--)
        {
             y=ceil((ara[j]-ara[k])/5.0);
             sum=sum+y;
        }
        sum=x+sum;

     printf("Case %d: %d\n",i+1,sum);
    }


    return 0;
}
