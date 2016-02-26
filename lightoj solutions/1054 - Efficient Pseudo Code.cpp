
/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 647- Coin Change
       Platform: Uva
     Algorithom: Coin Change DP
   Coder's Name: RC Tushar

~~~ Never Show Your Arrogance.Keep In Mind,You Were Born From A Drop Of Impure Liquid ~~~

*/

#include<bits/stdc++.h>

#define pi 2*acos(0.0)
#define PS system("pause")
#define siter(n,T1)  for(set<T1>::iterator it=n.begin();it!=n.end();it++)
#define miter(n,T1,T2)  for(map<T1,T2>::iterator it=n.begin();it!=n.end();it++)
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
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pf printf
#define ll long long int
#define MOD 1000000007
#define sqr(x) (( (x)* (x))%MOD)
#define cube(x)   ( (sqr(x)*(x))%MOD)
#define bit_cnt(x)   __builtin_popcount(x)
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define btz(a)   __builtin_ctz(a)
#define Mems(p,n) memset(p, n, sizeof(p))
#define makeint(n,s)  istringstream(s)>>n
#define BOUNDARY(i,j,Row,Col) ((i >= 0 && i < Row) && (j >= 0 && j < Col))
#define MAX    1000000


using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction

typedef vector<int> vi;
typedef pair<ll,ll> pii;

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

// ~~~~~~~~~~~~~~~ CODE STARTING POINT ~~~~~~~~~~~~~~~~



bool prim[MAX+10];
vector<ll> p;

void siv()
{
    for(int i=2;i*i<=MAX;i++)
    {
        if(!prim[i])
        for(int j=i;j*i<=MAX;j++)
        prim[i*j]=true;
    }

    for(int i=2;i<MAX;i++)
        if(!prim[i])
        p.push_back(i);
}

pii exclid(ll a,ll b)
{
    pii d;

    if(b==0)
        return (pii(1,0));
    else
    {
        d=exclid(b,a%b);
        return pii(d.S,d.F-d.S*(a/b));
    }
}

ll modin(ll a,ll m)
{
    pii d=exclid(a,m);
    return(((d.F%m)+m)%m);
}


ll fast_pow(ll n,ll p)
{
    if(p==0)
        return 1;
    if(p==1)
        return n%MOD;
    ll ans;
    if(p%2)
    {
        ans=(n*fast_pow(n,p-1)%MOD)%MOD;
        return ans;
    }
    else
    {
        ans=fast_pow(n,p/2)%MOD;
        ans=(ans*ans)%MOD;
        return ans;
    }
}



ll solve(ll n,ll m)
{
    ll ans=1,calc,cnt;
    for(int i=0;p[i]*p[i]<=n;i++)
    {
        cnt=0;
        while(n%p[i]==0)
        {
            n/=p[i];
            cnt++;
        }
        calc=((fast_pow(p[i],cnt*m+1)-1)*modin(p[i]-1,MOD))%MOD;
        ans=(ans*calc)%MOD;
    }
    if(n>1)
    {
        calc=((fast_pow(n,1*m+1)-1)*modin(n-1,MOD))%MOD;
        ans=(ans*calc)%MOD;
    }
    return ans;
}

int main()
{

siv();


ll test,n,m,ans;
fs(test);

Sfor(test)
{
  fs(n);
  fs(m);
  ans=solve(n,m);
  if(ans<0)
  ans=MOD+ans;
  pf("Case %d: %lld\n",i,ans);
}
return 0;
}
