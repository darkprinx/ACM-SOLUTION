/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 1412 - Visiting Islands
       Platform: LightOj
     Algorithom: Graph (DFS/TREE)
  Author's Name: RC Tushar



                 শুনেছি তোমার ভীষণ রাগ ?
                              সে কি রাগ , নাকি
                                     মগজ কোণে পচন ধরা
                 পুরনো কোডের বাগ ?


 ~~~     Never Lost Hope     ~~~
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
#define rall(x) (x).rbegin(),(x).rend()
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pf printf
#define ll long long int
#define ull unsigned long long int
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
#define ubound(d,val)  int (upper_bound (d.begin(), d.end(), val) - d.begin())
#define lbound(d,val)  int (lower_bound (d.begin(), d.end(), val) - d.begin())
#define M 100000
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
typedef pair<int,char> pic;
typedef pair< int, pii> ipii;


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


int st(int n,int pos)
{
    return n=n | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool ck(int n,int pos)
{
    return (bool)(n&(1<<pos));
}

ll binPow(ll a, ll q, ll mud)
{
    a %= mud;
    if (q == 0) return 1;
    return ((q % 2 == 1 ? a : 1) * binPow(a * a, q / 2, mud)) % mud;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

vi nod[M+5];
vector<pii> chain;
bool mark[M+5];
int mx,pmx,lmx,tot;

bool cmp(pii a,pii b)
{
    if(a.S==b.S)
        return a.F>b.F;
    return a.S>b.S;
}

void dfs(int u,int par,int cnt)
{
    if(mx<cnt)
    {
        mx=cnt;
        pmx=u;
    }
    mark[u]=true;
    for(int i=0;i<nod[u].size();i++)
    {
        int v=nod[u][i];
        if(v!=par)
        dfs(v,u,cnt+1);
    }
}

void dfs_x(int u,int par,int cnt)
{
    if(mx<cnt)
        mx=cnt;

    tot++;
    for(int i=0;i<nod[u].size();i++)
    {
        int v=nod[u][i];
        if(v!=par)
        dfs_x(v,u,cnt+1);
    }
}


int main()
{
    int n,t,q,a,b,xx;
    fs(t);

    for(int k=1;k<=t;k++)
    {
        fs(n);
        fs(q);
        chain.clear();
        for(int i=1;i<=n;i++)
        {
            nod[i].clear();
            mark[i]=false;
        }

        loop(i,0,q)
        {
            fs(a);
            fs(b);
            nod[a].pb(b);
            nod[b].pb(a);
        }

        lmx=0;
        for(int i=1;i<=n;i++)
        if(!mark[i])
        {
            mx=0;
            dfs(i,-1,1);
            mx=0;
            tot=0;
            dfs_x(pmx,-1,1);
            chain.pb(pii(mx,tot));
            lmx=max(lmx,mx);
        }

        sort(all(chain),cmp);
        int sum,ans;

        fs(q);
        pf("Case %d:\n",k);
        loop(i,0,q)
        {
            fs(xx);
            sum=INT_MAX;
            if(xx<=lmx)
                pf("%d\n",xx-1);
            else if(xx>chain[0].S)
                pf("impossible\n");
            else
            {
                for(int j=0; j<chain.size(); j++)
                {
                    if(xx>chain[j].S)
                        break;
                    ans=chain[j].F+(xx-chain[j].F)*2-1;
                    sum=min(sum,ans);
                }
                pf("%d\n",sum);
            }
        }
    }
    return 0;
}
