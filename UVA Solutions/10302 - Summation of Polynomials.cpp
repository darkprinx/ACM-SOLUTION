#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
    long long n, sum;
    while(scanf("%lld",&n)==1)
    {
        sum=(n*n*(n+1)*(n+1))/4;
        printf("%lld",sum);
    }
    return 0;
}


