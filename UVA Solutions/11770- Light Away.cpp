


/* Problem Name: 1034- Hit The Light Switches
       Platform: LightOJ
     Algorithom: Strongly Connected Component, DFS
   Coder's Name: R C Tushar
*/

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
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include<assert.h>


#define pi 2*acos(0.0)
#define PS system("pause")
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define Sfor(n) for(int i=1;i<=n;i++)
#define inf 1<<30
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)x.size())
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
#define lcm(a,b) (a*(b/gcd(a,b)))
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
#define bit_cnt(x)   __builtin_popcount(x)
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define btz(a)   __builtin_ctz(a)
#define MAX  10002
using namespace std;

map<int,int> visit;
vector<int>  node[MAX];

void dfs(int u)
{
    if(visit[u])
        return;
    visit[u]=1;
    for(int i=0; i<node[u].size(); i++)
    {
        int v=node[u][i];
        dfs(v);
    }
}

struct st
{
    int V,outdeg,indeg;
    bool operator < (const st & a)const
    {
        if(indeg!=a.indeg)
            return indeg<a.indeg;
        else
            return outdeg>a.outdeg;
    }
};
int main()
{

    int test,n,m,a,b,ans;

    s(test);
    for(int i=1; i<=test; i++)
    {
        ans=0;
        s(n);
        s(m);
        vector<st> X(n+1);
        for(int j=1; j<=n; j++)
            X[j].V=j;
        for(int j=1; j<=m; j++)
        {
            s(a);
            s(b);
            node[a].pb(b);
            X[a].outdeg++;
            X[b].indeg++;
        }
        sort(all(X));

        for(int j=0;j<=n;j++)
        {
            if(visit[X[j].V]==0&&X[j].V!=0)
            {
                dfs(X[j].V);
                ans++;
            }
        }

        pf("Case %d: %d\n",i,ans);
        for(int j=1; j<=n; j++)
        node[j].clear();
        visit.clear();
    }

    return 0;
}
