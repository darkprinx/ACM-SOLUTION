/* Problem Name: 11989-Pick up sticks
       Platform: UVA
     Algorithom: DFS Topsort
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
#define BOUNDARY(i,j,Row,Col) ((i >= 0 && i < Row) && (j >= 0 && j < Col))
#define M  1000002
using namespace std;

typedef vector<int> vi;
bool indeg[M];
vi node[M],path;
int cyc,visit[M];

void dfs(int u)
{

    if(visit[u]==2||cyc)
        return;
    if(visit[u])
    {
        cyc=1;
        return;
    }
    visit[u]=1;
    for(int i=0;i<node[u].size();i++)
    {
        int v=node[u][i];
        if(visit[v]==0)
        {
            dfs(v);
        }
    }
    path.pb(u);
    visit[u]=2;
}


int main()
{

int n,m,a,b;
while(cin>>n>>m)
{
    if(n==0&&m==0)
        break;
    Mems(indeg,false);
    Mems(visit,0);
    Sfor(n)
        node[i].clear();
    Sfor(m)
    {
        s(a);
        s(b);
        node[a].pb(b);
        indeg[b]=true;
    }
    cyc=0;
    bool flag=true;
    Sfor(n)
    {
        if(!indeg[i])
            {
                dfs(i);
                flag=false;
            }
    }
    int sx=path.size();
    if(cyc||flag)
        cout<<"IMPOSSIBLE"<<endl;
    else
    {
        for(int i=sx-1;i>=0;i--)
        cout<<path[i]<<endl;
    }
    path.clear();
}
return 0;
}



