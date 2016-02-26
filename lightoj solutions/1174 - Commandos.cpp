
/* Problem Name: 1174- Commandos
      P_latform: LightOJ
      Algorithm: BFS
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

vector<int>edge[MAX];
bool mark[MAX];
int cost1[MAX];
int cost2[MAX];

void BFS(int src,int *cost)
{
    int u,v;
    memset(mark,true,sizeof(mark));
    memset(cost,0,sizeof(cost));
    mark[src]=false;
    cost[src]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int i=0;i<edge[u].size();i++)
        {
            v=edge[u][i];
            if(mark[v]==true)
            {
            mark[v]=false;
            cost[v]=cost[u]+1;
            q.push(v);
            }
        }
    }
}

int main()
{
    int test,n,r,a,b,j,src,des;
    s(test);
    for(int i=1;i<=test;i++)
    {

        s(n);
        loop(j,0,n)
        edge[j].clear();
        s(r);
        loop(j,0,r)
        {
            s(a);
            s(b);
            edge[a].pb(b);
            edge[b].pb(a);
        }
        s(src);
        s(des);
        BFS(src,cost1);
        BFS(des,cost2);
        int mx=0;
        loop(j,0,n)
            mx=max(mx,cost1[j]+cost2[j]);

        pf("Case %d: %d\n",i,mx);
    }
    return 0;
}








