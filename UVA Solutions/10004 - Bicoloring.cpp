
/* Problem Name: 10004 - Bicoloring
       Platform: UVA
     Algorithom: BFS (BIPERTITE CHECKING)
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
using namespace std;

vector<int> G[202];

  int color[203];
  int mark[203]={};
bool is_bipart(int src)
{
    int u,v;
    queue<int> q;
    q.push(src);
    color[src]=1;
    mark[src]=1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            v=G[u][i];
            if(color[u]==color[v])
                    return false;
            if(mark[v]==0)
            {
                q.push(v);
                color[v]=1-color[u];
                mark[v]=1;
            }

        }
    }

    return true;
}

int main()
{

int V,E,a,b;
while(s(V)==1&&V!=0)
{
    s(E);
    loop(i,0,E)
    {
        s(a);
        s(b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    loop(i,0,V)
    {
        mark[i]=0;
        color[i]=-1;
    }
   if(is_bipart(0))
   pf("BICOLORABLE.\n");
   else
   pf("NOT BICOLORABLE.\n");
   loop(i,0,V)
   G[i].clear();
}
return 0;
}




