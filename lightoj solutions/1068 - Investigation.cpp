/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 1068 - Investigation
       Platform: LightOj
     Algorithom: Digit DP
  Author's Name: RC Tushar

 ** Comment - This is the only problem i have tried since 7 months and at 4th attempt i was able to solve.
              Special thanks to Sohel hafiz vaiya to give me clear concept of the states of this problem.



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

#define M 100000

// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

vi ara;
int n,k;
int dp[12][92][92][3];

void bosh(int num)
{
    ara.clear();
    while(num)
    {
        ara.pb(num%10);
        num/=10;
    }
    reverse(all(ara));
}

int solve(int pos,int rem,int sum,int flag)
{
    if(pos==n)
    {
        if(!rem&&!sum)
            return 1;
        return 0;
    }

    if(dp[pos][rem][sum][flag]!=-1)
        return dp[pos][rem][sum][flag];

    int tot=0;

    if(!flag)
        for(int i=0; i<=9; i++)
            tot+=solve(pos+1,(rem+i)%k,(sum*10+i)%k,flag);
    else
        for(int i=0; i<=ara[pos]; i++)
            tot+=solve(pos+1,(rem+i)%k,(sum*10+i)%k,(flag&&(i==ara[pos])));

    return dp[pos][rem][sum][flag]=tot;
}

int main()
{
    int test,a,b;
    fs(test);

    for(int cc=1; cc<=test; cc++)
    {

        fs(a);
        fs(b);
        fs(k);

        bosh(a-1);
        n=ara.size();
        Mems(dp,-1);
        int ans2=solve(0,0,0,1);

        bosh(b);
        n=ara.size();
        Mems(dp,-1);
        int ans1=solve(0,0,0,1);

        pf("Case %d: %d\n",cc,ans1-ans2);
    }
    return 0;
}




