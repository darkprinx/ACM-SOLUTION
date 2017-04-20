/*

   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~

   Problem Name: 1073 - DNA SEQUENCE ( খুব বেয়াদ্দপ প্রবলেম... জঘন্য প্যারা সহ্য করতে হইসে )
       Platform: LightOj
      Algorithm: String matching + Bitmask Dp
  Author's Name: RC Tushar


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

#define M   10
#define mod  1000000007


// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


pis ara[16][16];
string str[16];
int n;
int dp[16][(1<<16)+4];


int c[15];
int _next[201] ;

void failure(string s)
{
    int q = 0 ;
    _next[q] = 0 ;
    for( int i = 1 ; i < (int)s.size() ; i++ )
    {
        while( q > 0 && s[i] != s[q] )q = _next[q-1] ;
        if( s[i] == s[q] )q++ ;
        _next[i] = q ;
    }
}

bool kmp( string T , string P )
{
    failure(P) ;
    int q = 0 ;
    for( int i = 0 ; i < T.size() ; i++ )
    {
        while( q > 0 && P[q] != T[i] )q=_next[q-1] ;
        if( P[q] == T[i] )q++ ;
        if( q == P.size() )
        {
            return true ;
        }
    }
    return false ;
}
int calc( string s1 , string s2 )
{
    if( s2.size() <= s1.size() )
    {
        if( kmp(s1,s2) )return -1 ;
    }
    failure(s2+"$"+s1) ;
    return _next[s2.size()+s1.size()+1-1] ;
}


int solve(int pos,int mask)
{
    if(mask==(1<<n)-1)
        return dp[pos][mask]=0;
    if(dp[pos][mask]!=-1)
        return dp[pos][mask];

    int mx=inf,nx;

    for(int i=0; i<n; i++)
        if(!cak(mask,i))
        {
            if(!ara[pos][i].F)
                mx=min(mx,solve(pos,sat(mask,i)));
            else
              mx=min(mx,solve(i,sat(mask,i))+ara[pos][i].F);
        }
    return dp[pos][mask]=mx;
}


void path(int pos,int mask)
{
    if(mask==(1<<n)-1)
        return;

    int idx,jdx,tmp,ret=inf;
    string xx="z";

    for(int i=0; i<n; i++)
    {
        if(!cak(mask,i))
        {
            if(!ara[pos][i].F)
            {
                tmp=dp[pos][sat(mask,i)];
                if(ret>=tmp)
                {
                    ret=tmp;
                    idx=pos;
                    jdx=i;
                    xx="";
                }
            }
            else
            {
                tmp=dp[i][sat(mask,i)]+ara[pos][i].F;
                if(ret>tmp)
                {
                    ret=tmp;
                    idx=jdx=i;
                    xx=ara[pos][i].S;
                }
                if(tmp==ret&&ara[pos][i].S<xx)
                {
                    xx=ara[pos][i].S;
                    idx=jdx=i;
                }
            }
        }
    }

    pf("%s",xx.c_str());
    path(idx,sat(mask,jdx));

}


int main()
{
//    freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
    int tt;
    fs(tt);

    for(int kk=1; kk<=tt; kk++)
    {
        fs(n);
        loop(i,0,n)
        cin>>str[i];

        Mems(dp,-1);

        loop(i,0,n)
        loop(j,0,n)
        {
            if(str[i].find(str[j])<200)
            {
                ara[i][j]=pis(0,"");
                continue;
            }
            ara[i][j].F=calc(str[i],str[j]);
            string xx="";
            for(int kj=ara[i][j].F; kj<str[j].size(); kj++)
                xx+=str[j][kj];
            ara[i][j].F=str[j].size()-ara[i][j].F;
            ara[i][j].S=xx;
        }

        int mx=inf,nx,tp;
        string xx="z";
        for(int i=0; i<n; i++)
        {
            tp=solve(i,sat(0,i))+(int)str[i].size();
            if(mx>tp)
            {
                mx=tp;
                nx=i;
                xx=str[i];
            }
            if(mx==tp&&xx>str[i])
            {
                xx=str[i];
                nx=i;
            }
        }

        pf("Case %d: ",kk);
        pf("%s",str[nx].c_str());
        path(nx,sat(0,nx));
        pf("\n");
    }
    return 0;
}
