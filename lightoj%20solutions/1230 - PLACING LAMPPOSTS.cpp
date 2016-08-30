/*

   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~

   Problem Name: 1230 - PLACING LAMPPOSTS
       Platform: LightOj
      Algorithm: Minimum Vertex Cover
  Author's Name: RC Tushar


      ~~~    Never Lose Hope     ~~~
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
#define eps 1e-11
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


ll sat(ll n,ll pos)
{
    return n=n | (1LL<<pos);
}
ll reset(ll N,ll pos)
{
    return N= N & ~(1LL<<pos);
}
bool cak(ll n,ll pos)
{
    return (bool)(n&(1LL<<pos));
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

#define M    100000
#define mod  1000000007


// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct st
{
    int F,S;
    st() {}
    st(int a,int b)
    {
        F=a,S=b;
    }
    bool operator < (const st& op)const
    {
        if(op.F==F)
            return S>op.S;
        return F<op.F;
    }
};

int n,m;
pii dp[1005][3];
vi nod[1005];
bool mark[1006][3];
bool chk[1005];

void dfs(int u)
{
    if(chk[u])
        return;
    chk[u]=true;
    for(int i=0; i<nod[u].size(); i++)
        dfs(nod[u][i]);
}

pii solv(int u,int par,int flag)
{
    if(nod[u].size()<2&&par!=-1)
        return pii(flag,0);
    if(mark[u][flag])
        return dp[u][flag];
    mark[u][flag]=true;
    pii ret(0,0),tmp,dmp;
    st tp,kp;
    for(int i=0; i<nod[u].size(); i++)
    {
        int v=nod[u][i];
        if(v==par)
            continue;
        if(!flag)
        {
            tmp=solv(v,u,1);
            ret.F+=tmp.F;
            ret.S+=tmp.S;
        }
        else
        {
            tmp=solv(v,u,1);
            tp.F=tmp.F;
            tp.S=tmp.S+1;
            dmp=solv(v,u,0);
            kp.F=dmp.F;
            kp.S=dmp.S;
            tp=min(tp,kp);
            ret.F+=tp.F;
            ret.S+=tp.S;
        }
    }
    return dp[u][flag]=pii(ret.F+flag,ret.S);
}

int main()
{
    int tt,a,b;
    fs(tt);

    for(int kk=1; kk<=tt; kk++)
    {
        fs(n);
        fs(m);

        loop(i,0,n)
        nod[i].clear();

        loop(i,0,m)
        {
            fs(a);
            fs(b);
            nod[a].pb(b);
            nod[b].pb(a);
        }

        Mems(mark,false);
        Mems(chk,false);

        st tmp,dmp;
        pii ret,ans(0,0);

        loop(i,0,n)
        if(!chk[i])
        {
            dfs(i);
            ret=solv(i,-1,1);
            tmp.F=ret.F;
            tmp.S=ret.S;

            ret=solv(i,-1,0);
            dmp.F=ret.F;
            dmp.S=ret.S;

            tmp=min(tmp,dmp);
            ans.F+=tmp.F;
            ans.S+=tmp.S;
        }
        pf("Case %d: %d %d %d\n",kk,ans.F,ans.S,m-ans.S);
    }

    return 0;
}

