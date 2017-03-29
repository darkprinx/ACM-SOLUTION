
/*

   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~

   Problem Name: 11512 - GATTACA
       Platform: Uva
      Algorithm: Suffix Array + KMP
  Author's Name: RC Tushar

----------------------------------------------------
let the light of the Shelley moon die tonight
let the sky cover herself with dark shroud, tonight
but not the hope that promised to live
Just say her, dear, don't sleep tonight
die another day, die another night
----------------------------------------------------

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
#define eps 1e-15
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

#define M    10000
#define mod  1000000007
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))

// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct st
{
    int idx;
    int f,s;

    bool operator <(const st &op)const
    {
        if(op.f==f)
            return s<op.s;
        return f<op.f;
    }
} ara[M+5];

int rnk[15][M+4];
string str;
int LCP[M+5];

void build_LCP_array(int step)
{
    LCP[0] = 0;
    int n = str.size(), i, j, id1, id2;
    for(i = 1; i < n; i++)
    {
        id1 = ara[i - 1].idx;
        id2 = ara[i].idx;
        LCP[i] = 0;
        for(j = step - 1; j >= 0&&id1<n&&id2<n; j--)
            if(rnk[j][id1] == rnk[j][id2] )
            {
                LCP[i] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
    }
}


int pre[M+5];
int kmp(string xx,int ln)
{
    pre[0]=pre[1]=0;
    int n=xx.size(),k=0;
    int cnt=0;

    for(int i=2; i<=n; i++)
    {
        while(k>0&&xx[i-1]!=xx[k])
            k=pre[k];

        if(xx[i-1]==xx[k])
            k++;
        pre[i]=k;

        if(i>ln)
            cnt+=(pre[i]==ln);
    }
    return cnt;
}

int main()
{
    int tt;
    fs(tt);

    while(tt--)
    {

        int n,m;

        cin>>str;
        n=str.size();

        for(int i=0; i<n; i++)
            rnk[0][i]=str[i];

        int jump,i;
        for(i=1,jump=1; jump<=n; i++,jump*=2)
        {
            for(int j=0; j<n; j++)
            {
                ara[j].idx=j;
                ara[j].f=rnk[i-1][j];
                ara[j].s=j+jump<n?rnk[i-1][j+jump]:-1;
            }

            sort(ara,ara+n);

            rnk[i][ara[0].idx]=0;
            for(int j=1; j<n; j++)
                if(ara[j-1].f==ara[j].f&&ara[j-1].s==ara[j].s)
                    rnk[i][ara[j].idx]=rnk[i][ara[j-1].idx];
                else
                    rnk[i][ara[j].idx]=j;
        }


        int tot=i-1;

        build_LCP_array(tot+1);

        int mx=0;
        string ans;
        for(int i=1; i<n; i++)
        {
            if(LCP[i]>mx)
            {
                mx=LCP[i];
                ans=str.substr(ara[i-1].idx,LCP[i]);
            }
            else if(LCP[i]==mx)
                ans=min(ans,str.substr(ara[i-1].idx,LCP[i]));
        }


        if(!ans.size())
            pf("No repetitions found!\n");
        else
            pf("%s %d\n",ans.c_str(),kmp(ans+"$"+str,ans.size()));

    }
    return 0;
}








