/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 1281 - New Traffic System
       Platform: LightOj
     Algorithom: Dijkstra
  Author's Name: RC Tushar


                 শুনেছি তোমার ভীষণ রাগ ?
                              সে কি রাগ , নাকি
                                     মগজ কোণে পচন ধরা
                 পুরনো কোডের বাগ ?


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
#define inf (1<<29)
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

#define M 10000


// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


int n,m,k,lim;
vi nod1[M+5],cost1[M+6],path1[M+5];
vi nod2[M+5],cost2[M+6],path2[M+5];
ll d1[M+6],pr1[M+5];
ll d2[M+6],pr2[M+5];

ll bfs(int s,vi * nod,vi *cost,vi *path,ll *d,ll* pr)
{
    queue<int> q;
    loop(i,0,n+1)
    d[i]=INT_MAX;

    d[s]=0;
    pr[s]=0;
    q.push(s);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0; i<nod[u].size(); i++)
        {
            int v=nod[u][i];
            if(d[v]>d[u]+cost[u][i]&&lim>=pr[u]+path[u][i])
            {
                d[v]=d[u]+cost[u][i];
                pr[v]=pr[u]+path[u][i];
                q.push(v);
            }
        }
    }
}

int main()
{
    int tt,a,b,c;
    fs(tt);

    for(int kk=1; kk<=tt; kk++)
    {
        fs(n);
        fs(m);
        fs(k);
        fs(lim);

        loop(i,0,n)
        {
            nod1[i].clear();
            nod2[i].clear();
            cost1[i].clear();
            cost2[i].clear();
            path1[i].clear();
            path2[i].clear();
        }

        loop(i,0,m)
        {
            fs(a);
            fs(b);
            fs(c);

            nod1[a].pb(b);
            cost1[a].pb(c);
            path1[a].pb(0);

            nod2[b].pb(a);
            cost2[b].pb(c);
            path2[b].pb(0);
        }

        loop(i,0,k)
        {
            fs(a);
            fs(b);
            fs(c);

            nod1[a].pb(b);
            cost1[a].pb(c);
            path1[a].pb(1);

            nod2[b].pb(a);
            cost2[b].pb(c);
            path2[b].pb(1);
        }

        bfs(0,nod1,cost1,path1,d1,pr1);
        bfs(n-1,nod2,cost2,path2,d2,pr2);

        ll mx=INT_MAX;

        loop(i,0,n)
        if(pr1[i]+pr2[i]<=lim)
            mx=min(mx,d1[i]+d2[i]);

        if(mx==INT_MAX)
            pf("Case %d: Impossible\n",kk);
        else
            pf("Case %d: %lld\n",kk,mx);
    }

    return 0;
}





