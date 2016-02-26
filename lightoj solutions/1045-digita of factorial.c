#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    double sum;
    double *store;
    store=new double[1000000];
    sum=0;
    for(int i=1;i<=1000000;i++)
    {
        sum=sum+log(i);
        store[i]=sum;
    }
    int n,r,cases;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    cin>>r>>cases;
    sum=ceil(store[r]/log(cases));
    if(sum==0)
    sum=1;
    printf("Case %d: %d\n",i+1,(int)sum);
    }
    return 0;
}


