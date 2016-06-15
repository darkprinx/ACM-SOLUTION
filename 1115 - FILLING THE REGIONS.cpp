
/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 1115 - FILLING THE REGIONS
       Platform: LightOj
     Algorithom: 2D BFS
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
#define bit_cnt(x)   __builtin_popcount(x)
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define btz(a)   __builtin_ctz(a)
#define Mems(p,n) memset(p, n, sizeof(p))
#define BOUNDARY(i,j,Row,Col) ((i >= 0 && i < Row) && (j >= 0 && j < Col))
#define ubound(d,val)  int (upper_bound (d.begin(), d.end(), val) - d.begin())
#define lbound(d,val)  int (lower_bound (d.begin(), d.end(), val) - d.begin())

using namespace std;

int dx[]= {1,0,-1,0};
int dy[]= {0,1,0,-1};                        //4 Direction
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

template<class T>
double dif(T &a,T& b)
{
    double ans=(a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S);
    return sqrt(ans);
}

#define M  10000019


// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


int tt,r,c;
char ara[55][55];

void bfs(char ch)
{
    bool mark[55][55]= {};

    queue<pii> q;
    loop(i,0,r)
    {
        if(ara[i][0]!=ch)
        {
            mark[i][0]=true;
            q.push(pii(i,0));
        }

        if(ara[i][c-1]!=ch)
        {
            mark[i][c-1]=true;
            q.push(pii(i,c-1));
        }
    }

    loop(i,0,c)
    {
        if(ara[0][i]!=ch)
        {
            mark[0][i]=true;
            q.push(pii(0,i));
        }
        if(ara[r-1][i]!=ch)
        {
            mark[r-1][i]=true;
            q.push(pii(r-1,i));
        }
    }

    while(!q.empty())
    {
        pii u=q.front();
        int nx,ny;
        q.pop();

        for(int i=0; i<4; i++)
        {
            nx=u.F+dx[i];
            ny=u.S+dy[i];

            if(BOUNDARY(nx,ny,r,c)&&!mark[nx][ny]&&ara[nx][ny]!=ch)
            {
                mark[nx][ny]=true;
                q.push(pii(nx,ny));
            }
        }
    }

    loop(i,0,r)
    {
        loop(j,0,c)
        if(!mark[i][j])
            ara[i][j]=ch;
    }
}

int main()
{

    fs(tt);

    for(int kk=1; kk<=tt; kk++)
    {
        fs(r);
        fs(c);


        loop(i,0,r)
        loop(j,0,c)
        cin>>ara[i][j];

        bool alph[200]={};

        loop(i,0,r)
        loop(j,0,c)
        if(ara[i][j]!='.'&&!alph[ara[i][j]])
        {
            alph[ara[i][j]]=true;
            bfs(ara[i][j]);
        }

        pf("Case %d:\n",kk);
        loop(i,0,r)
        {
            loop(j,0,c)
            pf("%c",ara[i][j]);
            pf("\n");
        }

    }

    return 0;
}
