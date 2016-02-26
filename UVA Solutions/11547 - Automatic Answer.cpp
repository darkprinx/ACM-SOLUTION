#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    int n,sum,x,i;
    while(scanf("%d",&n)==1&&(n>=1&&n<=100))
    {
        for(i=0;i<n;i++)
        {
        cin>>x;
        sum=((((x*567)/9+7492)*235)/47-498);
        sum=abs((sum%100)/10);
        cout<<sum<<endl;
        }
    }
}

