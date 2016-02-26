
/* Problem Name: 1026 - CRITICAL LINKS
       Platform: LightOj
     Algorithom: Bridge Finding
   Coder's Name: RC Tushar
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
#define M  10002
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;

template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
        x*=sgn;
    return ~c;
}

int low[M],dft[M],cnt;
vi node[M];
set<pii> brig;
set<pii> ::iterator it;

bool visit[M];
void dfs(int u,int par)
{
    low[u]=dft[u]=++cnt;
    visit[u]=true;
    for(int i=0;i<node[u].size();i++)
    {
        int v=node[u][i];
        if(par==v)
            continue;
        if(visit[v])
            low[u]=min(low[u],dft[v]);
        else
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dft[u])
                {
                    if(u<v)
                    brig.insert(pii(u,v));
                    else
                    brig.insert(pii(v,u));
                }
        }
    }
}

int main()
{

int test,n,m,a,b;
fs(test);
Sfor(test)
{
    fs(n);
    brig.clear();
    for(int j=0;j<n;j++)
    node[j].clear();

    for(int j=0;j<n;j++)
    {
        scanf("%d (%d)",&a,&m);
        for(int k=0;k<m;k++)
        {
            fs(b);
            node[a].pb(b);
            node[b].pb(a);
        }
    }
    cnt=0;
    Mems(visit,false);
    for(int j=0;j<n;j++)
    {
        if(!visit[j])
            dfs(j,j);
    }
    pf("Case %d:\n",i);
    cout<<brig.size()<<" critical links"<<endl;
    for(it=brig.begin();it!=brig.end();it++)
        pf("%d - %d\n",it->F,it->S);

}
    return 0;
}
