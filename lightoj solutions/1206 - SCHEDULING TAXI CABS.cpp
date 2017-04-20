/*

   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~

   Problem Name: 1206 - SCHEDULING TAXI CABS
       Platform: LightOj
      Algorithm: Bipartite Matching
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
#define BOUNDARY(i,j,Row,Col) ((i >= 1 && i <= Row) && (j >= 1 && j <= Col))
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
typedef pair< string,string> pss;

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

#define M    504
//#define mod  (ull)pow(2,64)


// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct st
{
    string str;
    int Ax,Ay,Bx,By;
} ara[505];

int tmdst(string a,string b)
{
    int ahh=(a[0]-48)*10+(a[1]-48);
    int bhh=(b[0]-48)*10+(b[1]-48);
    int amm=(a[3]-48)*10+(a[4]-48);
    int bmm=(b[3]-48)*10+(b[4]-48);

    if(ahh==bhh)
        return abs(amm-bmm);
    else
    return (60-amm)+bmm+(bhh-ahh-1)*60;
}

int cor_dst(pii a,pii b)
{
    return abs(a.F-b.F)+abs(a.S-b.S);
}

bool cmp(st xx,st yy)
{
    int dst1=tmdst(xx.str,yy.str);
    int dst2=cor_dst(pii(xx.Ax,xx.Ay),pii(xx.Bx,xx.By))+cor_dst(pii(yy.Ax,yy.Ay),pii(xx.Bx,xx.By));
    return (dst1>dst2);
}

vi nod[M];
int par[M*M];
bool mark[M*M];
int n;

bool dfs(int u)
{
    for(int i=0; i<nod[u].size(); i++)
    {
        int v=nod[u][i];
        if(mark[v])
            continue;
        mark[v]=true;

        if(par[v]==-1)
        {
            par[v]=u;
            return true;
        }
        if(dfs(par[v]))
        {
            par[v]=u;
            return true;
        }
    }
    return false;
}

int mch()
{
    int tot=0;
    Mems(par,-1);
    for(int i=0; i<n; i++)
    {
        Mems(mark,false);
        tot+=dfs(i);
    }
    return tot;
}
int main()
{
    int tt;
    fs(tt);

    for(int kk=1; kk<=tt; kk++)
    {
        fs(n);
        loop(i,0,n)
        {
            nod[i].clear();
            cin>>ara[i].str;
            fs(ara[i].Ax);
            fs(ara[i].Ay);
            fs(ara[i].Bx);
            fs(ara[i].By);
        }

        int dst;

        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        if(cmp(ara[i],ara[j]))
            nod[i].pb(j);
        pf("Case %d: %d\n",kk,n-mch());
    }
    return 0;
}
