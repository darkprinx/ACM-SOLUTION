#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<assert.h>


#define PS system("pause")
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define inf 1<<30
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)x.size())
#define sqr(x) ( (x)* (x) )
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
#define on(x,w)  x=x|(1<<w)
#define check(x,w) (x&(1<<w))==(1<<w)?true:false
#define all(x) (x).begin(),(x).end()
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pf printf

using namespace std;

int ara[10];

void incr(int n)
{
    stringstream ss;
    string x;
    ss<<n;
    x=ss.str();
    for(int i=0; i<x.length(); i++)
    {
        ara[x[i]-48]++;
    }
}

int main()
{
    int test,n;
    s(test);
    while(test--)
    {
        for(int i=0;i<10;i++)
            ara[i]=0;
        s(n);
        for(int i=1; i<=n; i++)
        {
            incr(i);
        }
        for(int i=0; i<10; i++)
           {
             pf("%d",ara[i]);
               if(i+1<10)
                pf(" ");
           }
        pf("\n");
    }


    return 0;
}



