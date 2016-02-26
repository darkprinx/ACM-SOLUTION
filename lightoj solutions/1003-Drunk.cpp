

/* Problem Name: 1003- Drunk
       Platform: LightOJ
     Algorithom: DFS (cycle finding)
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
#define MAX 102
using namespace std;

#define MAX 10002
map<int ,vector<int> > node;
map<string,int> vert;

int visit[MAX];
bool indeg[MAX];

bool cyc;

void dfs(int u)
{
    if(visit[u]==2||cyc)
        return;
    if(visit[u])
    {
        cyc=true;
        return;
    }
    visit[u]=1;
    for(int i=0; i<node[u].size(); i++)
    {
        int v=node[u][i];
        dfs(v);
    }
    visit[u]=2;
}

int main()
{
    int test,n;
    s(test);
    for(int i=1; i<=test; i++)
    {
        string a,b;
        int c,inc=1;
        memset(visit,0,sizeof(visit));
        memset(indeg,false,sizeof(indeg));
        cyc=false;
        s(n);
        while(n--)
        {
            cin>>a>>b;
            if(vert[a]==0)
            {
                vert[a]=inc;
                inc++;
            }
            if(vert[b]==0)
            {
                vert[b]=inc;
                indeg[inc]=true;
                inc++;
            }
            node[vert[a]].pb(vert[b]);
        }
        int sz=node.size();
        for(int j=1; j<=sz; j++)
        {
            if(indeg[j]==false)
                dfs(j);
        }
        if(cyc)
            pf("Case %d: No\n",i);
        else
            pf("Case %d: Yes\n",i);
        for(int j=1; j<=sz; j++)
            node[j].clear();
        vert.clear();
    }

    return 0;
}



