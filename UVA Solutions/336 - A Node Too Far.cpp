
/* Problem Name: 336- A Node too Far
       Platform: UVA
     Algorithom: BFS
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
#define MAX   100000
using namespace std;

typedef vector<int> vi;

vi line[MAX];
set<int> X;
set<int> ::iterator it;

int BFS(int s,int tl)
{

    bool mark[MAX]={false};
    int TTL[MAX]={};
    int u,v,cnt=0;
    queue<int>q;
    if(line[s].size()!=0)
        cnt=1;
    q.push(s);
    mark[s]=true;
    while(!q.empty())
    {
        u=q.front();
        for(int i=0;i<line[u].size();i++)
        {
            v=line[u][i];
            if(mark[v]==false)
            {
                TTL[v]=1+TTL[u];
                mark[v]=true;
                if(TTL[v]<=tl)
                   {
                     q.push(v);
                     cnt++;
                   }
            }
        }
        q.pop();
    }
    int SZ=X.size();
    if(SZ<=cnt)
    return 0;
    return SZ-cnt;
}

int main()
{
int n,E,u,v,src,ttl;
int cnt=0;
while(s(E)==1&&E!=0)
{
    loop(i,0,E)
    {
        s(u);
        s(v);
        X.insert(u);
        X.insert(v);
        line[u].pb(v);
        line[v].pb(u);
    }
    while(cin>>src>>ttl)
    {
        if(src==0&&ttl==0)
            break;
        pf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++cnt,BFS(src,ttl),src,ttl);
    }


    loop(i,0,MAX)
        line[i].clear();
    X.clear();
}

return 0;
}



