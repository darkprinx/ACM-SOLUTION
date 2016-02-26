#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
    int i,j=0;
    float num;

    while(cin>>num)
    {
        if(num<0)
        break;
        for(i=0;num!=1;i++)
            num=ceil(num)/2;
    j++;
     printf("Case %d: %d\n",j,i);
    }
    return 0;
}
