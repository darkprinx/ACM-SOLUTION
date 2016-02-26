/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 10140 - Prime Distance
       Platform: Uva
     Algorithom: Number Theory
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
#define llu unsigned long long int
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
#define ubound(d,val)  int (upper_bound (d.begin(), d.end(), val) - d.begin())
#define lbound(d,val)  int (lower_bound (d.begin(), d.end(), val) - d.begin())
#define M 1000000
#define Mc 47000
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction
//freopen("sum.in","r",stdin);
//freopen("sum.out","w",stdout);
typedef vector<int> vi;
typedef pair<int,int> pii;;


//FAST_INPUT
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

bool mark[M+3]={};
int len;
vi num,para;
void siv()
{
    for(int i=2;i*i<=Mc;i++)
        if(!mark[i])
        for(int j=i;i*j<=Mc;j++)
        mark[i*j]=true;

    for(int i=2;i<Mc;i++)
        if(!mark[i])
        num.pb(i);
    len=num.size();
}


void solve(ll a,ll b)
{
    Mems(mark,false);
    int tmp=0;
    if(b==2147483647)
    {
        tmp=b;
        b--;
    }
    int j;
    for(int i=0;(ll)num[i]*(ll)num[i]<=b&&i<len;i++)
    {
        if(a%num[i]==0)
            j=a/num[i];
        else
            j=a/num[i]+1;
        if(j==1)
            j++;
        for(;(ll)num[i]*(ll)j<=b;j++)
        mark[(ll)num[i]*(ll)j-a]=true;
    }

    for(int i=a;i<=b;i++)
        if(!mark[i-a]&&i!=1)
        para.pb(i);
    if(tmp)
        para.pb(tmp);
    int ln=para.size();
    int mx=0,mn=INT_MAX,dif;

    pii x(0,0),y(0,0);
    for(int i=0;i<ln-1;i++)
    {
        dif=para[i+1]-para[i];
        if(dif>mx)
        {
            mx=dif;
            x.F=para[i];
            x.S=para[i+1];
        }

        if(dif<mn)
        {
            mn=dif;
            y.F=para[i];
            y.S=para[i+1];
        }
    }

    if(!y.F&&!x.S)
        pf("There are no adjacent primes.\n");
    else
        pf("%d,%d are closest, %d,%d are most distant.\n",y.F,y.S,x.F,x.S);
    para.clear();
}

int main()
{
    siv();
    ll a,b;
    while(fs(a)&&fs(b))
    {
        solve(a,b);
    }
    return 0;
}
