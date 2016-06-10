/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: A Wedding Party
       Platform: LightOj
     Algorithom: Dijkstra+bitmask DP
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

template<class T>
double dif(T &a,T& b)
{
    double ans=(a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S);
    return sqrt(ans);
}

#define M  100000


// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int shop[501];
int n,m;
vi nod[501],cost[501],chn;
int d[501][501];
int dp1[17][(1<<17)+5],dp2[17][(1<<17)+5];

void bfs(int s)
{
    loop(i,0,n)
    d[s][i]=inf;

    queue<int> q;
    d[s][s]=0;
    q.push(s);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<nod[u].size();i++)
        {
            int v=nod[u][i];
            if(d[s][v]>d[s][u]+cost[u][i])
            {
                d[s][v]=d[s][u]+cost[u][i];
                q.push(v);
            }
        }
    }
}

pii solv(int pos,int mask)
{
    if(pos==chn.size()-1)
        return pii(0,0);

    if((1<<chn.size())-1==mask)
        return pii(-1,0);

     if(dp1[pos][mask]!=-1)
        return pii(dp1[pos][mask],dp2[pos][mask]);

     pii ans(-1,inf);
     pii tmp;

     for(int i=0;i<chn.size();i++)
     {
         int v=chn[i];
         int u=chn[pos];

         if(!cak(mask,i)&&d[u][v]!=inf)
         {
             tmp=solv(i,sat(mask,i));

             if(tmp.F+shop[v]>ans.F&&tmp.F!=-1)
             {
                 ans.F=tmp.F+shop[v];
                 ans.S=tmp.S+d[u][v];
             }
             else if(tmp.F+shop[v]==ans.F&&tmp.F!=-1)
             ans.S=min(tmp.S+d[u][v],ans.S);
         }
     }

     dp1[pos][mask]=ans.F;
     dp2[pos][mask]=ans.S;
     return ans;
}

int main()
{
    int tt,a,b,c,s,x;
    fs(tt);

    for(int kk=1;kk<=tt;kk++)
    {
        fs(n);
        fs(m);
        fs(s);

        loop(i,0,n)
        {
            nod[i].clear();
            cost[i].clear();
        }

        chn.clear();
        Mems(shop,0);

        chn.pb(0);
        loop(i,0,s)
        {
            fs(x);
            shop[x]=1;
            if(x!=0&&x!=n-1)
            chn.pb(x);
        }
        chn.pb(n-1);

        loop(i,0,m)
        {
            fs(a);
            fs(b);
            fs(c);
            nod[a].pb(b);
            cost[a].pb(c);
        }

        loop(i,0,chn.size())
        bfs(chn[i]);

        Mems(dp1,-1);

        pii ans=solv(0,sat(0,0));

        if(ans.F!=-1)
            pf("Case %d: %d %d\n",kk,ans.F+shop[0],ans.S);
        else
            pf("Case %d: Impossible\n",kk);

    }


    return 0;
}




