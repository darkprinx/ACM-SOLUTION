/*

   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~

   Problem Name: 1256 - WORD PUZZLE
       Platform: LightOj
      Algorithm: EULER PATH
  Author's Name: RC Tushar

  ~~~     Never Lose Hope     ~~~
-----------------------------------
____    Show Mercy To Past ______
___   Stay Kind With Present  ___
__  Give Zero Chance In Future  ___

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
int dx[]= {1,1,0,-1,-1,-1,0,1};
int dy[]= {0,1,1,1,0,-1,-1,-1};    //8 direction
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
typedef pair<double,int> pdi;
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

#define M    1000
#define mod  10000019
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))

// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

vector<string> ara;
vi nod[M+5],num;
int indeg[M+4];
int outdeg[M+4];
bool visit[M+5];
int par[M+4];
int n;

int rep(int u)
{
    if(u==par[u])
        return u;
    return par[u]=rep(par[u]);
}

void form(int u,int v)
{
    int ln;
    for(int i=0; i<n; i++)
    {
        ln=ara[i].size();
        if((ara[i][0]-'a')==u&&(ara[i][ln-1]-'a')==v&&!visit[i])
        {
            visit[i]=true;
            num.pb(i);
            return;
        }
    }
}

void dfs(int u)
{
    while(!nod[u].empty())
    {
        int v=*(nod[u].begin());
        nod[u].erase(nod[u].begin());
        dfs(v);
        form(u,v);
    }
}


void clr()
{
    num.clear();
    ara.clear();
    for(int i=0; i<30; i++)
    {
        nod[i].clear();
        par[i]=i;
        indeg[i]=0;
        outdeg[i]=0;
        visit[i]=0;
    }
}

int main()
{
    int tt;
    fs(tt);
    string str;

    for(int kk=1; kk<=tt; kk++)
    {
        fs(n);

        clr();

        int u,v;

        loop(i,0,n)
        {
            cin>>str;
            ara.pb(str);
            u=str[0]-'a';
            v=str[str.size()-1]-'a';

            indeg[u]++;
            outdeg[v]++;
            nod[u].pb(v);
            visit[u]=visit[v]=true;

            u=rep(par[u]);
            v=rep(par[v]);
            if(u!=v)
                par[u]=v;
        }

        bool flag=true;

        for(int i=0; i<=26&&flag; i++)
            for(int j=0; j<=26&&flag; j++)
                if(visit[i]&&visit[j])
                {
                    u=rep(par[i]);
                    v=rep(par[j]);
                    if(u!=v)
                        flag=false;
                }

        bool fg1=true;
        bool in=true;
        bool out=true;

        int src;
        int cnt=0;
        for(int i=0; i<=26; i++)
            if(indeg[i]!=outdeg[i])
            {
                cnt++;
                if(cnt==3)
                    break;
                if(abs(indeg[i]-outdeg[i])!=1)
                    fg1=false;
                else
                {
                    if(indeg[i]>outdeg[i])
                    {
                        in=false;
                        src=i;
                    }
                    else
                        out=false;
                }
            }

        if(!flag||cnt==3||fg1==false)
        {
            pf("Case %d: No\n",kk);
            continue;
        }

        if((!in&&out)||(!out&&in))
        {
            pf("Case %d: No\n",kk);
            continue;
        }

        if(in&&out)
            for(int i=0; i<30; i++)
                if(visit[i])
                {
                    src=i;
                    break;
                }

        Mems(visit,false);
        dfs(src);

        pf("Case %d: Yes\n",kk);
        pf("%s",ara[num[n-1]].c_str());
        for(int i=n-2; i>=0; i--)
            pf(" %s",ara[num[i]].c_str());
        pf("\n");

    }

    return 0;
}
