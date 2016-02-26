#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t,L,W,H;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        cin>>L>>W>>H;
        if(L>20||W>20||H>20)
            printf("Case %d: bad\n",i);
        else
            printf("Case %d: good\n",i);
    }
    return 0;
}
