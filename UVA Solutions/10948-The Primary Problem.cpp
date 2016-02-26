#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#define MAX 1000000
using namespace std;
vector<bool>  ara(MAX+7,false);
vector<int> prime;

void sieve()
{
    ara[0]=ara[1]=true;
    for(int i=2; i<=sqrt(MAX); i++)
    {
        if(!ara[i])
        {
            for(int j=2; i*j<=MAX; j++)
                ara[i*j]=true;
        }
    }
}

int main()
{
    sieve();
    for(int i=2; i<MAX; i++)
    {
        if(!ara[i])
            prime.push_back(i);
    }
    int num;
    while(scanf("%d",&num)==1&&num!=0)
    {
        bool flag=false;
        printf("%d:\n",num);
        for(int K=0;prime[K]<=num&&K<prime.size();K++)
        {
            if(!ara[num-prime[K]])
                {
                    printf("%d+%d\n",prime[K],num-prime[K]);
                    flag=true;
                    break;
                }
        }
        if(!flag)
            printf("NO WAY!\n");

    }

    return 0;
}
