/* Problem Name: 1002 - Country Roads
       Platform: lightoj
     Algorithom: Modified Dujkstra
   Coder's Name: Rc Tushar
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
#define M  502
using namespace std;

typedef vector<int> vi;

vi node[M],cost[M];
int d[M];

struct st
{
    int u,w;
    st(int x,int y){u=x;w=y;}
    bool operator<(const st&p)const
    {
        return w>p.w;
    }
};

void bfs(int s)
{
    d[s]=0;
    queue<st> q;
    q.push(st(s,0));
    while(!q.empty())
    {
        st top=q.front();
        q.pop();
        int u=top.u;
        for(int i=0;i<node[u].size();i++)
        {
            int v=node[u][i],MX=max(cost[u][i],d[u]);
            if(d[v]>MX)
            {
                d[v]=MX;
                q.push(st(v,d[v]));
            }
        }
    }
}

void input(int n,int m)
{
  int a,b,w;
  for(int i=0;i<n;i++)
  {
      node[i].clear();
      cost[i].clear();
      d[i]=MOD;
  }
  for(int i=0;i<m;i++)
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

int test,m,n,t;
s(test);
Sfor(test)
{
    s(n);
    s(m);
    input(n,m);
    s(t);
    bfs(t);
    pf("Case %d:\n",i);
    for(int j=0;j<n;j++)
       {
           if(d[j]==MOD)
           pf("Impossible\n");
           else
           pf("%d\n",d[j]);
       }

}

return 0;
}



