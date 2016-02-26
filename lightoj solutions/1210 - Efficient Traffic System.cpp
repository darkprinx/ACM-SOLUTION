
/* Problem Name: 1210-Efficient Trafic System
       Platform: Lightoj
     Algorithom: SCC-DFS (minimum connection to make full graph SCC)
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
#define Mems(p,n) memset(p, n, sizeof(p))
#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))
#define M  20002
using namespace std;

typedef vector<int> vi;

vi A[M],B[M];
stack<int> st;
bool visit[M];
int out[M],in[M],comp[M],cnt;


void dfs1(int u)
{
    for(int i=0; i<A[u].size(); i++)
    {
        int v=A[u][i];
        if(!visit[v])
        {
            visit[v]=true;
            dfs1(v);
        }
    }

    st.push(u);
}

void dfs2(int u)
{
    for(int i=0; i<B[u].size(); i++)
    {
        int v=B[u][i];
        if(!visit[v])
        {
            visit[v]=true;
            dfs2(v);
        }
    }
    comp[u]=cnt;
}



int main()
{
    int test,n,m,a,b;
    s(test);
    for(int i=1; i<=test; i++)
    {
        s(n);
        s(m);
        for(int j=0; j<n; j++)
        {
            A[j].clear();
            B[j].clear();
        }
        for(int j=0; j<m; j++)
        {
            s(a);
            s(b);
            a--,b--;
            A[a].pb(b);
            B[b].pb(a);
        }
        Mems(visit,false);
        for(int j=0; j<n; j++)
        {
            if(!visit[j])
            {
                visit[j]=true;
                dfs1(j);
            }
        }
        Mems(visit,false);
        cnt=0;
        while(!st.empty())
        {
            int u=st.top();
            if(!visit[u])
            {
                visit[u]=true;
                dfs2(u);
                cnt++;
            }
            st.pop();
        }

        Mems(in,0);
        Mems(out,0);

        if(cnt==1)
            pf("Case %d: 0\n",i);
        else
        {
            for(int j=0; j<n; j++)
                for(int k=0; k<A[j].size(); k++)
                {
                    int v=A[j][k];
                    if(comp[j]!=comp[v])
                    {
                        out[comp[j]]++;
                        in[comp[v]]++;
                    }
                }

            int c=0,d=0;
            for(int j=0; j<cnt; j++)
            {
                if(in[j]==0)
                    c++;
                if(out[j]==0)
                    d++;
            }
            pf("Case %d: %d\n",i,max(c,d));
        }

    }

    return 0;
}



