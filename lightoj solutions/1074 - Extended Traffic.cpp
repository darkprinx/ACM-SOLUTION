
/* Problem Name:
       Platform:
     Algorithom:
   Coder's Name:
*/

#include<bits/stdc++.h>

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
#define makeint(n,s)  istringstream(s)>>n
#define BOUNDARY(i,j,Row,Col) ((i >= 0 && i < Row) && (j >= 0 && j < Col))
#define M  202
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction

typedef vector<int> vi;

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

//~~~~~~~~~~~~~~~~~CODE STARTING POINT~~~~~~~~~~~~~~~~~~~~~~

struct st
{
    int u,v,w;
    st(int a,int b,int c)
    {
        u=a;
        v=b;
        w=c;
    }
};

vector<st> node;
vi graph[M];
int d[M];
int cost[M];
bool visit [M];

void dfs(int u)
{
    if(!visit[u])
    {
        visit[u]=true;
        int sz=graph[u].size();
        for(int i=0; i<sz; i++)
            dfs(graph[u][i]);
    }
}
void belm(int n,int m)
{
    d[1]=0;
    bool neg=false;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int u=node[j].u,v=node[j].v;
            if(d[u]+node[j].w<d[v])
                d[v]=d[u]+node[j].w;
        }
    }
}

int main()
{
    int test,n,m,a,b,c,busy;
    s(test);

    Sfor(test)
    {
        s(n);
        for(int j=1; j<=n; j++)
        {
            cin>>cost[j];
            d[j]=inf;
            graph[j].clear();
        }
        node.clear();
        s(m);
        for(int j=0; j<m; j++)
        {
            s(a);
            s(b);
            c=cube(cost[b]-cost[a]);
            graph[a].pb(b);
            node.pb(st(a,b,c));
        }
        Mems(visit,false);
        dfs(1);
        belm(n,m);
        s(n);
        for(int j=0; j<n; j++)
            cin>>cost[j];
        pf("Case %d:\n",i);
        for(int j=0; j<n; j++)
        {
            int amount=d[cost[j]];
            if(amount<3||!visit[cost[j]])
                cout<<"?"<<endl;
            else
                cout<<amount<<endl;
        }
    }
    return 0;
}



