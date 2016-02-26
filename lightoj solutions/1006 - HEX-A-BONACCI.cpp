#include <iostream>
#include <cstdio>
#include <algorithm>
#define mod 10000007
using namespace std;

long long int *dp;

int a, b, c, d, e, f;
int fn( int n )
{
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if(dp[n]!=-1)return dp[n];
    else
    {
        dp[n]= fn(n-1)%mod + fn(n-2)%mod + fn(n-3)%mod+ fn(n-4)%mod + fn(n-5)%mod+ fn(n-6)%mod;
        return dp[n];
    }

}
int main()
{
    dp=new long long int[10000];
    int n, caseno = 0, cases;
    scanf("%d", &cases);

    while( cases-- )
    {
        for(int l=0; l<=10000; l++)
        dp[l]=-1;
        cin>>a>>b>>c>>d>>e>>f>>n;
        printf("Case %d: %lld\n", ++caseno, fn(n) % mod);
    }
    return 0;
}

