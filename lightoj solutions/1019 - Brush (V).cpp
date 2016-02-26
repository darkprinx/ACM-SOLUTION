/* Problem Name: 1019-Brush(V)
       Platform: LightOj
     Algorithom: Dijkstra Shortest path
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
#define inf (1<<30)
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
#define Mems(p,n) memset(p, n, sizeof(p))
#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))
#define M  102
using namespace std;

typedef vector<int> vi;

vi node[M],cost[M];
int d[M];


struct st
{
    int u,w;
    st(int x,int y)
    {
        u=x;
        w=y;
    }
    bool operator<(const st &p)const
    {
        return w>p.w;
    }
};

int bfs(int n)
{
    for(int i=1;i<=100;i++)
        d[i]=100000000;
    priority_queue<st> q;
    q.push(st(1,0));
    d[1]=0;

    while(!q.empty())
    {
    st X=q.top();
    q.pop();

    int u=X.u;
    if(u==n)
        return d[n];
    for(int i=0; i<node[u].size(); i++)
    {
        int v=node[u][i],vcost;
        vcost=cost[u][i]+d[u];
        if(vcost<d[v])
        {
            d[v]=vcost;
            q.push(st(v,d[v]));
        }
    }
    }
    return -1;
}

void input(int n,int m)
{
    int a,b,w;
    for(int i=1; i<=n; i++)
        {
            node[i].clear();
            cost[i].clear();
        }
    for(int i=1; i<=m; i++)
    {
        s(a);
        s(b);
        s(w);
        node[a].pb(b);
        node[b].pb(a);
        cost[a].pb(w);
        cost[b].pb(w);
    }
}

int main()
{
    int test,n,m,ans;
    s(test);
    for(int i=1; i<=test; i++)
    {
        s(n);
        s(m);
        input(n,m);
        ans=bfs(n);
        if(ans!=-1)
            pf("Case %d: %d\n",i,ans);
        else
            pf("Case %d: Impossible\n",i);
    }

    return 0;
}



