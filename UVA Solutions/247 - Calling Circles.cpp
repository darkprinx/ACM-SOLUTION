/* Problem Name: 247-Calling Circles
       Platform: UVA
     Algorithom: SCC  Kosharaju's Algo
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
#define BOUNDARY(i,j,Row,Col) ((i >= 0 && i < Row) && (j >= 0 && j < Col))
#define M  27
using namespace std;

typedef vector<int> vi;

vi A[M],B[M];
vector<string> cir[M];
map<string,int> name;
string order[M];
bool visit[M];
int circle[M],cnt;
stack<int> st;
bool flag=false;

void dfs1(int u)
{
    for(int i=0;i<A[u].size();i++)
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
    for(int i=0;i<B[u].size();i++)
    {
        int v=B[u][i];
        if(!visit[v])
        {
            visit[v]=true;
            dfs2(v);
        }
    }
    circle[u]=cnt;
}

int main()
{

int n,m,g=0;
string a,b;
while(cin>>n>>m)
{
    int roll=1;
    if(n==0&&m==0)
        break;
    Sfor(n)
    {
        A[i].clear();
        B[i].clear();
        cir[i].clear();
    }
    name.clear();
    Sfor(m)
    {
        cin>>a>>b;
        if(name[a]==0)
            {
                name[a]=roll;
                order[roll]=a;
                roll++;
            }
        if(name[b]==0)
            {
                name[b]=roll;
                order[roll]=b;
                roll++;
            }
            A[name[a]].pb(name[b]);
            B[name[b]].pb(name[a]);
    }

    Mems(visit,false);
    Sfor(n)
    {
        if(!visit[i])
        {
          visit[i]=true;
          dfs1(i);
        }
    }
    Mems(visit,false);
    cnt=1;
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        if(!visit[u])
        {
            visit[u]=true;
            dfs2(u);
            cnt++;
        }
    }

    for(int i=1;i<=n;i++)
        cir[circle[i]].pb(order[i]);


     if(flag)pf("\n");
     flag=true;

     pf("Calling circles for data set %d:\n",++g);
     for(int i=1; i<cnt; i++)
       {
           int sx=cir[i].size();
            for(int j=0; j<sx; j++)
           {
               cout<<cir[i][j];
                if(j+1<sx)
                    cout<<", ";
           }
            cout<<endl;
        }
}

return 0;
}






