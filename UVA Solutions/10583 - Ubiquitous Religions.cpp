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
#include <cmath>
#include <cstring>
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
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
#define on(x,w)  x=x|(1<<w)
#define check(x,w) (x&(1<<w))==(1<<w)?true:false
#define all(x) (x).begin(),(x).end()
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pf printf
#define ll long long int
#define MOD 1000000007
#define sqr(x) (( (x)* (x))%MOD)
#define cube(x)   ( (sqr(x)*(x))%MOD)
#define bit_cnt(x)   __builtint_popcount(x)
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))

using namespace std;

map<int,int> num;
set<int> X;

int REP(int a)
{
    if(num[a]==a)
        return a;
    return num[a]=REP(num[a]);
}
void UN(int a,int b)
{
    a=REP(num[a]);
    b=REP(num[b]);
    if(a!=b)
        num[a]=b;
}


int main()
{
 int n,m,a,b,l=1;
 while(s(n)==1&&s(m)==1)
 {
     if((n&&m)==0)
        break;
     for(int i=1;i<=n;i++)
        num[i]=i;
     for(int i=1;i<=m;i++)
        {
            s(a);
            s(b);
            UN(a,b);
        }
    for(int i=1;i<=n;i++)
        {
            a=REP(num[i]);
            X.insert(a);
        }
   pf("Case %d: %d\n",l,X.size());
   l++;
   X.clear();
   num.clear();
 }

return 0;
}
