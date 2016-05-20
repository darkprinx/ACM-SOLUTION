/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 10187 - From Dusk Till Dawn
       Platform: Uva
     Algorithom: Dijkstra
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
#define inf (1<<28)
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

int n;
map<string,vector<string> > nod;
map<string,vector<pii> > cost;
map<string,int> d;


int cmp(int x, int y)
{
    if (x==-1||x==y)
        return 0;

    if (x >= 1 && x <= 6)
        return !(y >= x && y < 6);

    if (x >= 18 && x <= 24)
        return !((y >= x && y <= 24) || y < 6);
}

int bfs(string s,string des)
{
    d[s]=0;
    queue<psi>q;
    q.push(psi(s,-1));

    while(!q.empty())
    {
        psi u=q.front();
        q.pop();


        for(int i=0; i<nod[u.F].size(); i++)
        {
            string v=nod[u.F][i];
            pii cc=cost[u.F][i];
            int xx=cmp(u.S,cc.F);
            if(d[v]>d[u.F]+xx)
            {
                d[v]=d[u.F]+xx;
                q.push(psi(v,cc.S));
            }
        }
    }
    return d[des];
}

int main()
{
    int tt,c,dd;
    string a,b;

    fs(tt);

    for(int k=1; k<=tt; k++)
    {
        nod.clear();
        cost.clear();
        d.clear();

        fs(n);
        loop(i,0,n)
        {
            cin>>a>>b>>c>>dd;
            if(dd>12)
                continue;
            dd=(c+dd);

            if(dd>24)
                dd-=24;

            if((6<=c&&c<18)||(6<dd&&dd<=18))
            continue;

            nod[a].pb(b);
            cost[a].pb(pii(c,dd));
            d[a]=inf;
            d[b]=inf;
        }

        cin>>a>>b;
        d[a]=d[b]=inf;
        pf("Test Case %d.\n",k);

        int ans=bfs(a,b);
        if(ans!=inf)
            pf("Vladimir needs %d litre(s) of blood.\n",ans);
        else
            pf("There is no route Vladimir can take.\n");

    }

    return 0;
}



