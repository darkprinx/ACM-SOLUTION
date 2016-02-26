
/* Problem Name: 1417- Forwarding Emails
       Platform: LightOJ
     Algorithom: DFS
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
#define MAX  50002
using namespace std;

typedef vector<int> vi;

vi node[MAX];
bool visit[MAX];

int dfs(int u,int c)
{
    if(visit[u])
        return c;

    visit[u]=1;
    for(int i=0;i<node[u].size();i++)
    {
        int v=node[u][i];
        return dfs(v,c+1);
    }
}

struct vert
{
    int V;
    int indeg;

    bool operator<(const vert & a)const
    {
        if(indeg!=a.indeg)
            return indeg<a.indeg;
        else
            return V<a.V;
    }
};

int main()
{

int test,n,a,b;
s(test);

for(int i=1;i<=test;i++)
{
    s(n);
    vector<vert> info(n+1);
    for(int j=1;j<=n;j++)
     {
         info[j].V=j;
         node[j].clear();
     }

    for(int j=1;j<=n;j++)
    {
        s(a);
        s(b);
        node[a].pb(b);
        info[b].indeg++;
    }
    int ans=0,trav,point;
    memset(visit,false,sizeof(visit));
    sort(all(info));

        for(int j=1; j<=n; j++)
        {
            if(info[j].indeg==0)
                memset(visit,false,sizeof(visit));
            if(!visit[info[j].V])
            {
                trav=dfs(info[j].V,0);
                if(trav>ans)
                {
                    ans=trav;
                    point=info[j].V;
                }
            }
        }

         pf("Case %d: %d\n",i,point);
}

return 0;
}



