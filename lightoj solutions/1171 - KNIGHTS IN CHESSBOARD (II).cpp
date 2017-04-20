/*

   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~

   Problem Name: 1171 - KNIGHTS IN CHESSBOARD (II)
       Platform: LightOj
      Algorithm: Hopcroft–Karp Bipartite Matching
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
int dx[]= {2,1,-1,-2,-2,-1,1,2};
int dy[]= {1,2,2,1,-1,-2,-2,-1};  //Knight Direction
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

#define M    204*204
//#define mod  (ull)pow(2,64)


// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int ara[205][205];
vi bip[M];
int mark[M],lef[M],rit[M];
int n,m,rt,lt;

bool bfs(int n)
{
    queue<int> q;
    for(int i=1; i<=n; i++)
        if(!lef[i])
        {
            mark[i]=0;
            q.push(i);
        }
        else
            mark[i]=inf;

    mark[0]=inf;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<bip[u].size(); i++)
        {
            int v=bip[u][i];
            if(mark[rit[v]]==inf)
            {
                mark[rit[v]]=mark[u]+1;
                q.push(rit[v]);
            }
        }
    }
    return (mark[0]!=inf);
}

bool dfs(int u)
{
    if(u)
    {
        for(int i=0; i<bip[u].size(); i++)
        {
            int v=bip[u][i];
            if(mark[rit[v]]==mark[u]+1)
            {
                if(dfs(rit[v]))
                {
                    lef[u]=v;
                    rit[v]=u;
                    return true;
                }
            }
        }
        mark[u]=inf;
        return false;
    }
    return true;
}

int solv(int n)
{
    Mems(lef,0);
    Mems(rit,0);
    int tot=0;
    while(bfs(n))
    {
        for(int i=1; i<=n; i++)
            if(!lef[i]&&dfs(i))
                tot++;
    }
    for(int i=0;i<=n;i++)
        bip[i].clear();
    return tot;
}

void visit(int r, int c, int d)
{
    int i, r1, c1;
    if(d & 1)
        ara[r][c] = ++rt;
    else
        ara[r][c] = ++lt;

    for(i = 0; i < 8; i++)
    {
        r1 = r + dx[i];
        c1 = c + dy[i];
        if(BOUNDARY(r1, c1,n,m) && ara[r1][c1])
        {
            if(ara[r1][c1] == -1)
                visit(r1, c1, d + 1);
            if(!(d & 1))
                bip[ara[r][c]].push_back(ara[r1][c1]);
        }
    }
}

void init()
{
    int i, j;
    lt = rt = 0;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(ara[i][j]==-1)
                visit(i, j, 0);
}

int main()
{

    int tt,k,a,b;
    fs(tt);

    for(int kk=1; kk<=tt; kk++)
    {

        fs(n);
        fs(m);
        fs(k);
        int cnt=1;

        Mems(ara,-1);
        loop(i,0,k)
        {
            fs(a);
            fs(b);
            ara[a][b]=0;
        }

        init();
        pf("Case %d: %d\n",kk,(n*m)-k-solv(lt));


    }
    return 0;
}




