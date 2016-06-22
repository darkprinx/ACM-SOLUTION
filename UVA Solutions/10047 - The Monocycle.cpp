
/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 10047 - The Monocycle
       Platform: Uva
     Algorithom: BFS
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

#define M  10000000


// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct st
{
    int x,y,dr,cl;
    st();
    st(int a,int b,int c,int d)
    {
        x=a;
        y=b;
        dr=c;
        cl=d;
    }
};

char ara[30][30];
int r,c;


int bfs(pii src)
{
    bool mark[30][30][6][7]={};
    int dp[30][30][6][7]= {};

    queue<st> q;
    q.push(st(src.F,src.S,2,0));
    mark[src.F][src.S][2][0]=true;
    dp[src.F][src.S][2][0]=0;

    while(!q.empty())
    {
        st u=q.front();
        q.pop();
        int nx,ny,cc,dir1,dir2;

        dir1=(u.dr+1)%4;
        dir2=((u.dr-1)%4+4)%4;
        cc=(u.cl+1)%5;

        nx=dx[u.dr]+u.x;
        ny=dy[u.dr]+u.y;

        if(BOUNDARY(nx,ny,r,c)&&ara[nx][ny]!='#'&&!mark[nx][ny][u.dr][cc])
        {
            q.push(st(nx,ny,u.dr,cc));
            mark[nx][ny][u.dr][cc]=true;
            dp[nx][ny][u.dr][cc]=dp[u.x][u.y][u.dr][u.cl]+1;
            if(ara[nx][ny]=='T'&&cc==0)
                return dp[nx][ny][u.dr][cc];

        }

        if(!mark[u.x][u.y][dir1][u.cl])
        {
            mark[u.x][u.y][dir1][u.cl]=true;
            dp[u.x][u.y][dir1][u.cl]=dp[u.x][u.y][u.dr][u.cl]+1;
            q.push(st(u.x,u.y,dir1,u.cl));
        }

        if(!mark[u.x][u.y][dir2][u.cl])
        {
            mark[u.x][u.y][dir2][u.cl]=true;
            dp[u.x][u.y][dir2][u.cl]=dp[u.x][u.y][u.dr][u.cl]+1;
            q.push(st(u.x,u.y,dir2,u.cl));
        }
    }
    return -1;
}

int main()
{

    int cnt=1;
    while(fs(r)&&fs(c)&&r&&c)
    {
        pii ss;
        loop(i,0,r)
        {
            loop(j,0,c)
            {
                cin>>ara[i][j];
                if(ara[i][j]=='S')
                    ss=pii(i,j);
            }
        }

        if(cnt!=1)
            pf("\n");
        int ans=bfs(ss);
        pf("Case #%d\n",cnt++);
        if(ans==-1)
            pf("destination not reachable\n");
        else
            pf("minimum time = %d sec\n",ans);
    }
    return 0;
}









