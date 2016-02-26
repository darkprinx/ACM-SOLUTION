
/* Problem Name: 280 – Vertex
       Platform: UVA
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
#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))
using namespace std;

bool visit[102];
vector<int>node[102];
int total;
void dfs(int u)
{
    int v;
    for(int i=0;i<node[u].size();i++)
        {
          v=node[u][i];
          if(!visit[v])
            {
                visit[v]=true;
                dfs(v);
                total--;
            }
        }
}

int main()
{

    int vert,a,b,n,v;

    while(s(vert)==1&&vert!=0)
    {
        while(s(a)==1&&a!=0)
        {
            while(s(b)==1&&b!=0)
                node[a].pb(b);
        }

        s(n);
        for(int i=0; i<n; i++)
        {
            total=vert;
            memset(visit,false,sizeof(visit));
            s(v);
            dfs(v);
            cout<<total;
            for(int j=1;j<=vert;j++)
                if(!visit[j])
                cout<<' '<<j;
            cout<<endl;
        }
        for(int i=1;i<=vert;i++)
            node[i].clear();
    }


    return 0;
}



