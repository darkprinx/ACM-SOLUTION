
#include<bits/stdc++.h>

#define pi 2*acos(0.0)
#define PS system("pause")
#define siter(n,T1)  for(set<T1>::iterator it=n.begin();it!=n.end();it++)
#define miter(n,T1,T2)  for(map<T1,T2>::iterator it=n.begin();it!=n.end();it++)
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define Sfor(n) for(int i=1;i<=n;i++)
#define inf (1<<30)
#define pb push_back
#define ppb pop_back
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
#define M 100005
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction

typedef vector<int> vi;
typedef pair<int,int> pii;

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
    st (int a, int b, int c)
    {
        u=a;
        v=b;
        w=c;
    }
    bool operator <(const st & p)const
    {
        return w<p.w;
    }
};

vector<st> node;
vector<pii> rode[M];

int par[M],L[M];
int pars[M][17];
int mxd[M][17],mx;
bool ara[M];
int khujo(int n)
{
    if(par[n]==n)
        return n;
    else
    {
        par[n]=khujo(par[n]);
        return par[n];
    }
}

void mst(int n)
{
    int i,j,u,v,len=node.size();
    sort(all(node));

    for(i=j=0;i<len&&j<n-1;i++)
    {
        u=khujo(node[i].u);
        v=khujo(node[i].v);
        if(u!=v)
        {
            j++;
            par[u]=v;
            rode[u].pb(pii(v,node[i].w));
            rode[v].pb(pii(u,node[i].w));
        }
    }
}

int lev;
void dfs(int par,int u,int dep)
{
    int len=rode[u].size();
    L[u]=dep;
    lev=max(lev,dep);
    ara[u]=true;
    for(int i=0;i<len;i++)
    {
        if(!ara[rode[u][i].F])
        {
        mxd[rode[u][i].F][0]=rode[u][i].S;
        pars[rode[u][i].F][0]=u;
        dfs(u,rode[u][i].F,dep+1);
        }
    }
}

void bosho(int n)
{
    for(int j=1;(1<<j)<=lev;j++)
    for(int i=1;i<=n;i++)
        if(pars[i][j-1]!=-1)
        {
            pars[i][j]=pars[pars[i][j-1]][j-1];
            mxd[i][j]=max(mxd[i][j-1],mxd[pars[i][j-1]][j-1]);
        }
}

void khujo(int n,int a,int b)
{
    if(L[a]<L[b])
        swap(a,b);
     mx=0;

    int log=1;
    for(;(1<<log)<=L[a];log++);
    log--;

    for(int i=log;i>=0;i--)
        if(L[a]-(1<<i) >=L[b])
    {
        mx=max(mx,mxd[a][i]);
        a=pars[a][i];
    }
    if(a==b)
        return;

    for(int i=log;i>=0;i--)
        if(pars[a][i]!=-1 && pars[a][i]!=pars[b][i])
        {
            mx=max3(mx,mxd[a][i],mxd[b][i]);
            a=pars[a][i];
            b=pars[b][i];
        }
    mx=max3(mx,mxd[a][0],mxd[b][0]);
}

int main() {

int test,n,m,a,b,c,q;
fs(test);
Sfor(test)
{
    fs(n);
    fs(m);
    loop(j,0,m)
    {
        fs(a);
        fs(b);
        fs(c);
        node.pb(st(a,b,c));
    }
     loop(j,1,n+1)
    {
        par[j]=j;
        rode[j].clear();
    }
    mst(n);
    node.clear();
    Mems(ara,false);
    Mems(pars,-1);
    Mems(mxd,0);
    lev=0;
    dfs(-1,1,0);
    bosho(n);
    fs(q);
    pf("Case %d:\n",i);
    loop(j,0,q)
    {
        fs(a);
        fs(b);
        khujo(n,a,b);
        pf("%d\n",mx);
    }
}
    return 0;
}
