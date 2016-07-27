

/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name:
       Platform: LightOj
      Algorithm:
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

#define M  1000000


// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct st
{
    double a,b,c;
} e1,e2,e3,e4;

double x1,yy1,x2,y2,r,c,px,py;

st banao(double x1,double yy1,double x2,double y2)
{
    st xx;
    xx.a=y2-yy1;
    xx.b=x1-x2;
    xx.c=xx.a*x1+xx.b*yy1;
    return xx;
}

st sect(st aa,st bb)
{
    st ans;
    ans.c=0;
    double det=aa.a*bb.b-aa.b*bb.a;

    if(det==0)
    {
        ans.c=-1;
        return ans;
    }
    ans.a=(aa.c*bb.b-bb.c*aa.b)/det;
    ans.b=(bb.c*aa.a-aa.c*bb.a)/det;
    return ans;
}


bool dcx(pdd aa,pdd bb,pdd cc)
{
    double m1=(bb.S-aa.S)/(bb.F-aa.F);
    double m2=(cc.S-aa.S)/(cc.F-aa.F);

    return m1<m2;
}

int main()
{
    int tt;
    fs(tt);

    for(int kk=1; kk<=tt; kk++)
    {
        scanf("%lf",&x1);
        scanf("%lf",&yy1);
        scanf("%lf",&r);
        scanf("%lf",&c);
        scanf("%lf",&px);
        scanf("%lf",&py);

        e1=banao(x1,yy1,x1,yy1+r);
        e2=banao(x1,yy1,x1+c,yy1);
        e3=banao(px,py,(x1+c)/2.0,(yy1+r)/2.0);


        st a1=sect(e1,e3);
        st b1=sect(e2,e3);

//        cout<<e1.a<<' '<<e1.b<<' '<<e1.c<<endl;
//        cout<<e2.a<<' '<<e2.b<<' '<<e2.c<<endl;
//        cout<<e3.a<<' '<<e3.b<<' '<<e3.c<<endl;

//        cout<<a1.a<<' '<<a1.b<<' '<<a1.c<<endl;
//        cout<<b1.a<<' '<<b1.b<<' '<<b1.c<<endl;
        vector<pdd> ara;
//PS;

        int dcc=-1;

        if((yy1>=py&&x1>=px&&px<=x1+c)||(yy1<=py&&x1>=px&&px<=x1+c))
            dcc=1;
        else if((x1>=px&&yy1>=py&&py<=yy1+r)||(x1<=px&&yy1>=py&&py<=yy1+r))
            dcc=2;
        else if(px<x1&&py<yy1)
        {
            if(dcx(pdd(x1,yy1),pdd(x1+c,yy1+r),pdd(px,py)))
                dcc=1;
            else
                dcc=2;
        }
        else if(px<x1&&py>yy1+r)
        {

        }
        else if(px>x1+c&&py>yy1+r)
        {

        }
        else if(px>x1+c&&py<yy1)
        {

        }

        if(dcc==1)
        {
            e4.a=a1.a-x1;
            e4.b=a1.b-yy1;
            e4.a=x1+c-e4.a;
            e4.b=yy1+r-e4.b;
            if(e4.a==-0)
                e4.a=0;
            if(e4.b==-0)
                e4.b=0;
            if(a1.a==-0)
                a1.a=0;
            if(a1.b==0)
                a1.b=0;

            ara.pb(pdd(a1.a,a1.b));
            ara.pb(pdd(e4.a,e4.b));
            sort(all(ara));
        }
        else
        {
            e4.a=b1.a-x1;
            e4.b=b1.b-yy1;
            e4.a=x1+c-e4.a;
            e4.b=yy1+r-e4.b;

            if(e4.a==-0)
                e4.a=0;
            if(e4.b==-0)
                e4.b=0;
            if(b1.a==-0)
                b1.a=0;
            if(b1.b==0)
                b1.b=0;

            ara.pb(pdd(b1.a,b1.b));
            ara.pb(pdd(e4.a,e4.b));
            sort(all(ara));
        }
        pf("%.8f %.8f\n",ara[0].F,ara[0].S);
        pf("%.8f %.8f\n",ara[1].F,ara[1].S);

    }
    return 0;
}




