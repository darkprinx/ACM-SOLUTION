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
#define MAX 30003
using namespace std;

typedef pair<int,int>pii;
typedef vector<int>vi;
map<int,int> stor;

vi num(MAX,0);

int REP(int a)
{
    if(num[a]==a)
            return a;
    else
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
    int i,j,n,m,test,a,b,c;
    s(test);
    loop(j,0,test)
    {
        s(n);
        s(m);
        int cnt=0;
        loop(i,1,n+1)
            num[i]=i;

        loop(i,0,m)
        {
            s(a);
            s(b);
            UN(a,b);
        }
        for(int k=1;k<=n;k++)
        {
            c=REP(num[k]);
            stor[c]++;
            if(stor[c]>cnt)
                cnt=stor[c];
        }
      cout<<cnt<<endl;
      num.clear();
      stor.clear();

    }

    return 0;
}







