/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 1429 - ASSASSIN`S CREED (II)
       Platform: LightOj
      Algorithm: SCC + MAXIMUM MATCHING
  Author's Name: RC Tushar



         ~~~~~ MY DEDICATION TO SOME FRIENDS ~~~~~
   Kim: Whenever you start to believe  yourself, people also start to believe in you.
  Oshy: Every programming contest is like a new life.To do better in every life you must dedicate your real life.
 Elise: Keep studying and the improvement will come. it's a slow process but each step is rewarding.


 ~~~     Never Lose Hope     ~~~
*/


#include<bits/stdc++.h>
#define pi 2*acos(0.0)
#define PS system("pause")
#define siter(n,T1)  for(set<T1>::iterator it=n.begin();it!=n.end();it++)
#define miter(n,T1,T2)  for(map<T1,T2>::iterator it=n.begin();it!=n.end();it++)
#define meter(n,T1,T2)  for(map<T1,T2>::iterator it=n.end();it!=n.begin();it--)
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define Sfor(n) for(int i=1;i<=n;i++)
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
#define rall(x) (x).rbegin(),(x).rend()
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pf printf
#define ll long long int
#define ull unsigned long long int
#define MOD 1000000007
#define inf (1<<29)
#define sqr(x) (( (x)* (x))%MOD)
#define cube(x)   ( (sqr(x)*(x))%MOD)
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define bit_cnt(x)   __builtin_popcount(x)
#define btz(a)   __builtin_ctz(a)
#define Mems(p,n) memset(p, n, sizeof(p))
#define BOUNDARY(i,j,Row,Col) ((i >= 0 && i < Row) && (j >= 0 && j < Col))
#define ubound(d,val)  int (upper_bound (d.begin(), d.end(), val) - d.begin())
#define lbound(d,val)  int (lower_bound (d.begin(), d.end(), val) - d.begin())

using namespace std;

//int dx[]= {1,0,-1,0};
//int dy[]= {0,1,0,-1};                        //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,bool> pib;
typedef pair<double,double> pdd;
typedef pair<int,double> pid;
typedef pair< int, pii> ipii;
typedef pair< int, string> pis;
typedef pair< string,int> psi;

//TEMPLATES
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


int sat(int n,int pos)
{
    return n=n | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool cak(int n,int pos)
{
    return (bool)(n&(1<<pos));
}

ll binPow(ll a, ll q, ll mud)
{
    a %= mud;
    if (q == 0) return 1;
    return ((q % 2 == 1 ? a : 1) * binPow(a * a, q / 2, mud)) % mud;
}

pll ex_clid(ll a,ll b)
{
    if(b==0)
        return pll(1,0);
    pll d=ex_clid(b,a%b);
    return pll(d.S,d.F-d.S*(a/b));
}

ll mod_inv(ll n,ll md)
{
    pll d=ex_clid(n,md);
    return ((d.F%md)+md)%md;
}

template<class T>
double dif(T &a,T& b)
{
    double ans=(a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S);
    return sqrt(ans);
}

#define M  1000


// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool mark[M+5];
vi nod[M+5],bod[M+5],rod[M+5],gp[M+5];
stack<int> st;
int par[M+5];
int mar[M+5];

void dfs1(int u)
{
    if(mark[u])
        return;
    mark[u]=true;
    for(int i=0; i<nod[u].size(); i++)
        dfs1(nod[u][i]);
    st.push(u);
}

void dfs2(int u,int boss)
{
    if(mark[u])
        return;
    mark[u]=true;
    par[u]=boss;
    for(int i=0; i<bod[u].size(); i++)
        dfs2(bod[u][i],boss);
}


void bfs(int x)
{
    queue<int> q;
    Mems(mark,false);
    mark[x]=true;
    q.push(x);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0; i<rod[u].size(); i++)
        {
            int v=rod[u][i];
            if(!mark[v])
            {
                mark[v]=true;
                q.push(v);
                gp[x].pb(v);
            }
        }
    }
}


bool dfs3(int u)
{
    for(int i=0;i<gp[u].size();i++)
    {
        int v=gp[u][i];
        if(mark[v])
            continue;
        mark[v]=true;
        if(par[v]==-1)
        {
            par[v]=u;
            mar[u]=v;
            return true;
        }
        if(dfs3(par[v]))
        {
            par[v]=u;
            mar[u]=v;
            return true;
        }
    }
    return false;
}


int main()
{
    int tt,n,m,a,b;
    fs(tt);

    for(int kk=1; kk<=tt; kk++)
    {
        fs(n);
        fs(m);

        Mems(par,-1);
        for(int i=1; i<=n; i++)
        {
            nod[i].clear();
            bod[i].clear();
            rod[i].clear();
            gp[i].clear();
        }

        for(int i=1; i<=m; i++)
        {
            fs(a);
            fs(b);
            nod[a].pb(b);
            bod[b].pb(a);
        }

        Mems(mark,false);
        for(int i=1; i<=n; i++)
            dfs1(i);

        Mems(mark,false);
        vi num;
        int ln=0;
        while(!st.empty())
        {
            int u=st.top();
            st.pop();
            if(!mark[u])
            {
                num.pb(u);
                dfs2(u,u);
                ln++;
            }
        }

        for(int i=1; i<=n; i++)
            for(int j=0; j<nod[i].size(); j++)
            {
                int vv=nod[i][j];
                if(par[i]!=par[vv])
                    rod[par[i]].pb(par[vv]);
            }

        for(int i=0; i<ln; i++)
            bfs(num[i]);

        int tot=0;

        Mems(par,-1);
        Mems(mar,-1);

        for(int i=0; i<ln; i++)
            {
                Mems(mark,false);
                if(dfs3(num[i]))
                    tot++;
            }

        pf("Case %d: %d\n",kk,ln-tot);

    }
    return 0;
}
