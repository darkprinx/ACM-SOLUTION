/*

   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~

   Problem Name: 1368 - TRUCHET TILING ( এটার ইমপ্লিমেন্টেশনটা খুব প্যারার ছিল, কিন্তু জোস একটা প্রবলেম :D )
       Platform: LightOj
      Algorithm: DFS
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

int dx[]= {1,0,-1,0};
int dy[]= {0,1,0,-1};                        //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]= {2,1,-1,-2,-2,-1,1,2};
//int dy[]= {1,2,2,1,-1,-2,-2,-1};  //Knight Direction
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

#define M    1000000
//#define mod  (ull)pow(2,64)


// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

char ara[103][105];
double dp[103][105][4];
bool mark[105][106][4];
double sum;
int n,m;
bool flag;

struct st
{
    int x,y,tile;
    st(){};
    st(int X,int Y,int Tile)
    {
        x=X;
        y=Y;
        tile=Tile;
    }
};

vector<st> pp;

double clc(int x)
{
    if(x==0||x==2)
        return pi/4.0;
    else
        return 4-(pi/2.0);
}

void dfs(int x,int y,int tile)
{
    if(flag)
        return;
    if(dp[x][y][tile]>0)
    {
        sum=dp[x][y][tile];
        flag=true;
        return;
    }
    if(mark[x][y][tile])
        return;
    mark[x][y][tile]=true;
    pp.pb(st(x,y,tile));
    sum+=clc(tile);
    int nx,ny;

    if(ara[x][y]=='0')
    {
        if(tile==2)
        {
            nx=x;
            ny=y+1;
            if(BOUNDARY(nx,ny,n,m))
            {
                if(ara[nx][ny]=='0')
                    dfs(nx,ny,1);
                else
                    dfs(nx,ny,2);
            }
            nx=x+1;
            ny=y;
            if(BOUNDARY(nx,ny,n,m))
            {
                if(ara[nx][ny]=='0')
                    dfs(nx,ny,1);
                else
                    dfs(nx,ny,0);
            }
        }
        else if(tile==1)
        {
            nx=x;
            ny=y+1;
            if(BOUNDARY(nx,ny,n,m))
            {
                if(ara[nx][ny]=='0')
                    dfs(nx,ny,0);
                else
                    dfs(nx,ny,1);
            }
            nx=x+1;
            ny=y;
            if(BOUNDARY(nx,ny,n,m))
            {
                if(ara[nx][ny]=='0')
                    dfs(nx,ny,0);
                else
                    dfs(nx,ny,1);
            }

            nx=x;
            ny=y-1;
            if(BOUNDARY(nx,ny,n,m))
            {
                if(ara[nx][ny]=='0')
                    dfs(nx,ny,2);
                else
                    dfs(nx,ny,1);
            }
            nx=x-1;
            ny=y;
            if(BOUNDARY(nx,ny,n,m))
            {
                if(ara[nx][ny]=='0')
                    dfs(nx,ny,2);
                else
                    dfs(nx,ny,1);
            }
        }
        else
        {
            nx=x;
            ny=y-1;
            if(BOUNDARY(nx,ny,n,m))
            {
                if(ara[nx][ny]=='0')
                    dfs(nx,ny,1);
                else
                    dfs(nx,ny,0);
            }
            nx=x-1;
            ny=y;
            if(BOUNDARY(nx,ny,n,m))
            {
                if(ara[nx][ny]=='0')
                    dfs(nx,ny,1);
                else
                    dfs(nx,ny,2);
            }
        }
    }
    else
    {
        if(tile==0)
        {
            nx=x;
            ny=y+1;
            if(BOUNDARY(nx,ny,n,m))
            {
                if(ara[nx][ny]=='1')
                    dfs(nx,ny,1);
                else
                    dfs(nx,ny,0);
            }
            nx=x-1;
            ny=y;
            if(BOUNDARY(nx,ny,n,m))
            {
                if(ara[nx][ny]=='1')
                    dfs(nx,ny,1);
                else
                    dfs(nx,ny,2);
            }
        }
        else if(tile==1)
        {
            nx=x;
            ny=y+1;
            if(BOUNDARY(nx,ny,n,m))
            {
                if(ara[nx][ny]=='1')
                    dfs(nx,ny,2);
                else
                    dfs(nx,ny,1);
            }
            nx=x+1;
            ny=y;
            if(BOUNDARY(nx,ny,n,m))
            {
                if(ara[nx][ny]=='1')
                    dfs(nx,ny,0);
                else
                    dfs(nx,ny,1);
            }

            nx=x;
            ny=y-1;
            if(BOUNDARY(nx,ny,n,m))
            {
                if(ara[nx][ny]=='1')
                    dfs(nx,ny,0);
                else
                    dfs(nx,ny,1);
            }
            nx=x-1;
            ny=y;
            if(BOUNDARY(nx,ny,n,m))
            {
                if(ara[nx][ny]=='1')
                    dfs(nx,ny,2);
                else
                    dfs(nx,ny,1);
            }

        }
        else
        {
            nx=x;
            ny=y-1;
            if(BOUNDARY(nx,ny,n,m))
            {
                if(ara[nx][ny]=='1')
                    dfs(nx,ny,1);
                else
                    dfs(nx,ny,2);
            }
            nx=x+1;
            ny=y;
            if(BOUNDARY(nx,ny,n,m))
            {
                if(ara[nx][ny]=='1')
                    dfs(nx,ny,1);
                else
                    dfs(nx,ny,0);
            }

        }
    }

}

double solv(int x,int y)
{
    int nx,ny;

    if((x+y)%2)
        return 0;

    sum=0;
    nx=x/2;
    ny=y/2;
    flag=false;

    if(x%2)
        dfs(nx,ny,1);
    else
    {
        if(BOUNDARY(nx,ny,n,m))
        {
            if(ara[nx][ny]=='0')
                dfs(nx,ny,0);
            else
                dfs(nx,ny,1);
        }
        if(BOUNDARY(nx-1,ny,n,m))
        {
            if(ara[nx-1][ny]=='0')
                dfs(nx-1,ny,1);
            else
                dfs(nx-1,ny,2);
        }
        if(BOUNDARY(nx,ny-1,n,m))
        {
            if(ara[nx][ny-1]=='0')
                dfs(nx,ny-1,1);
            else
                dfs(nx,ny-1,0);
        }
        if(BOUNDARY(nx-1,ny-1,n,m))
        {
            if(ara[nx-1][ny-1]=='0')
                dfs(nx-1,ny-1,2);
            else
                dfs(nx-1,ny-1,1);
        }
    }
    for(int i=0;i<pp.size();i++)
        dp[pp[i].x][pp[i].y][pp[i].tile]=sum;
    pp.clear();
    return sum;
}



int main()
{

    int tt,q,a,b;
    fs(tt);

    for(int kk=1; kk<=tt; kk++)
    {
        fs(n);
        fs(m);

        loop(i,0,n)
        loop(j,0,m)
        {
            cin>>ara[i][j];
            dp[i][j][0]=0;
            dp[i][j][1]=0;
            dp[i][j][2]=0;
        }

        Mems(mark,false);
        fs(q);
        pf("Case %d:\n",kk);
        loop(i,0,q)
        {
            fs(a);
            fs(b);
            pf("%.8f\n",solv(a,b));
        }
    }
    return 0;
}
