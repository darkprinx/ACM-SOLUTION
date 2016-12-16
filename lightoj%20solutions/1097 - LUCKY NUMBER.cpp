/*

   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~

   Problem Name: 1097 - LUCKY NUMBER
       Platform: LightOj
      Algorithm: Segment tree (Kth value)
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

#define M    2000000
#define mod  1000000007
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))

// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int tree[M*4];
int ara[100005];

void init(int nod,int b,int e)
{
    if(b==e)
    {
        if(b%2==0)
            tree[nod]=0;
        else
            tree[nod]=1;
        return;
    }

    int left,right,mid;
    left=nod*2;
    right=nod*2+1;
    mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);
    tree[nod]=tree[left]+tree[right];
}

void dilit(int nod,int b,int e,int v)
{
    if(b==e)
    {
        tree[nod]=0;
        return;
    }

    int left,right,mid;
    left=nod*2;
    right=nod*2+1;
    mid=(b+e)/2;
    if(tree[left]>=v)
    dilit(left,b,mid,v);
    else
    dilit(right,mid+1,e,v-tree[left]);
    tree[nod]=tree[left]+tree[right];
}

int xx;
void qury(int nod,int b,int e,int v)
{
    if(b==e)
    {
        xx=e;
        return;
    }

    int left,right,mid;
    left=nod*2;
    right=nod*2+1;
    mid=(b+e)/2;

    if(tree[left]>=v)
    qury(left,b,mid,v);
    else
    qury(right,mid+1,e,v-tree[left]);
    tree[nod]=tree[left]+tree[right];
}



int main()
{
    ara[1]=1;
    init(1,1,M);
    for(int i=2;i<=100000;i++)
    {
        qury(1,1,M,i);
        ara[i]=xx;
        for(int j=1;(ll)j*(ll)xx<=tree[1];j++)
                dilit(1,1,M,(ll)j*(ll)xx-(ll)j+1);
    }

    int n,tt;
    fs(tt);

    for(int i=1;i<=tt;i++)
    {
        fs(n);
        pf("Case %d: %d\n",i,ara[n]);
    }


    return 0;
}






