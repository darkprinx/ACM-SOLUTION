/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 11695 - Flight Planning
       Platform: Uva
     Algorithom: Tree/bfs (Harder)
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
#define MOD 1000007
#define sqr(x) (( (x)* (x))%MOD)
#define cube(x)   ( (sqr(x)*(x))%MOD)
#define bit_cnt(x)   __builtin_popcount(x)
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define btz(a)   __builtin_ctz(a)
#define Mems(p,n) memset(p, n, sizeof(p))
#define BOUNDARY(i,j,Row,Col) ((i >=0 && i <= Row) && (j >=0 && j <= Col))
#define ubound(d,val)  int (upper_bound (d.begin(), d.end(), val) - d.begin())
#define lbound(d,val)  int (lower_bound (d.begin(), d.end(), val) - d.begin())

using namespace std;

//int dx[]= {1,0,-1,0};int dy[]= {0,1,0,-1};                        //4 Direction
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
typedef pair< vi, int> vis;


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

#define M (int)1e6


// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


vi nod[2555];

vi bfs(int s,pii del,pii add)
{
    bool mark[2555]= {};
    int d[2555]= {};
    int par[2555]={};
    queue<int>q;
    q.push(s);

    d[s]=0;
    mark[s]=true;

    if(add.F>0&&add.S>0)
    {
        nod[add.F].pb(add.S);
        nod[add.S].pb(add.F);
    }
    int mx=0,id=-1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<nod[u].size(); i++)
        {
            int v=nod[u][i];

            if(add!=del)
            {
                if(del.F==u&&del.S==v)
                    continue;
                if(del.F==v&&del.S==u)
                    continue;
            }

            if(!mark[v])
            {
                mark[v]=true;
                q.push(v);
                d[v]=d[u]+1;
                par[v]=u;
                if(mx<d[v])
                {
                    mx=d[v];
                    id=v;
                }
            }
        }
    }
    if(add.F>0&&add.S>0)
    {
        nod[add.F].pop_back();
        nod[add.S].pop_back();
    }

    vi ara;
    for(int i=id; i!=-1&&i!=s; i=par[i])
        ara.pb(i);
    ara.pb(s);
    return ara;
}

vi gethim(int s,pii del,pii add)
{
    vi a=bfs(s,del,add);
    a=bfs(a[0],del,add);
    return a;
}

int main()
{
//    freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
    int tt,n,a,b;
    fs(tt);

    while(tt--)
    {
        fs(n);

        loop(i,0,n+1)
        nod[i].clear();

        loop(i,0,n-1)
        {
            fs(a);
            fs(b);
            nod[a].pb(b);
            nod[b].pb(a);
        }

        vi ara=gethim(1,pii(-1,-1),pii(-1,-1));

        int ln=ara.size();
        int mn=INT_MAX;
        pii del,add;

        for(int i=0;i<ln-1;i++)
        {
            vi x1=gethim(ara[i],pii(ara[i],ara[i+1]),pii(-1,-1));
            vi x2=gethim(ara[i+1],pii(ara[i],ara[i+1]),pii(-1,-1));

            int ln1=x1.size();
            int ln2=x2.size();

            vi x3=gethim(ara[i],pii(ara[i],ara[i+1]),pii(x1[ln1/2],x2[ln2/2]));

            int ln3=x3.size();
            if(ln3<mn)
            {
                mn=ln3;
                del=pii(ara[i],ara[i+1]);
                add=pii(x1[ln1/2],x2[ln2/2]);
            }
        }

        pf("%d\n",mn-1);
        pf("%d %d\n",del.F,del.S);
        pf("%d %d\n",add.F,add.S);
    }

    return 0;
}



