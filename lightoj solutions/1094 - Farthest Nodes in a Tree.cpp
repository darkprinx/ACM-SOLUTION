
//  -----------------    BISMILLAH-HIR-RAHMANIR-RAHIM   --------------------------
/* Problem Name: 1094 - FARTHEST NODES IN A TREE
       Platform: LightOj
     Algorithom: DFS ( Farthest node )
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
#define M  (int)3e4
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction



//~~~~~~~~~~~~~~~~~CODE STARTING POINT~~~~~~~~~~~~~~~~~~~~~~


typedef vector<int> vi;

vi node[M+2],cost[M+2];

bool visit[M+2];
int FN,F_cost;


void dfs(int u,int c)
{
    if(!visit[u])
    {
        visit[u]=true;
        int len=node[u].size();

        if(c>F_cost)
            {
                F_cost=c;
                FN=u;
            }

        for(int i=0; i<len; i++)
        {
            int v=node[u][i];
            dfs(v,c+cost[u][i]);
        }
    }
    return;
}

int main()
{
    int test,n,a,b,w;
    s(test);
    Sfor(test)
    {
        s(n);
        for(int j=0; j<n; j++)
            {
                node[j].clear();
                cost[j].clear();
            }

        for(int j=0; j<n-1; j++)
        {
            s(a);
            s(b);
            s(w);
            node[a].pb(b);
            node[b].pb(a);
            cost[a].pb(w);
            cost[b].pb(w);
        }

        Mems(visit,false);
        F_cost=0;
        dfs(0,0);

        F_cost=0;
        Mems(visit,false);
        dfs(FN,0);
        pf("Case %d: %d\n",i,F_cost);
    }

    return 0;
}



