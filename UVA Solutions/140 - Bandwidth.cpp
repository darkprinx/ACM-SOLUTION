/**

   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~

   Problem Name: 140 - Bandwidth
       Platform: UVa
      Algorithm: Backtracking
  Author's Name: RC Tushar

----------------------------------------------------
                Be Kind & Show Mercy
----------------------------------------------------

**/


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
#define eps 1e-17
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
#define inf (1<<30)
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
int ddx[]= {1,1,0,-1,-1,-1,0,1};
int ddy[]= {0,1,1,1,0,-1,-1,-1};    //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef pair<ll,bool> pib;
typedef pair<double,double> pdd;
typedef pair<char,char> pcc;
typedef pair<double,int> pdi;
typedef pair< int, pii> ipii;
typedef pair< int, string> pis;
typedef pair< string,int> psi;

typedef vector< stack<int> > vsi;

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

#define M    100000

#define mod  1000000007
#define INT(c)  ((int)((c) - '0'))
#define rc(c)  ((int)((c) - 'A'))
#define CHAR(i) ((char)(i + int('0')))


/*****************************  Code Starting Point  *****************************/

vi nod[200];
int main()
{
    string str;
    while(cin>>str&&str!="#")
    {
        set<char> st;
        for(int i=0; str[i]; i++)
        {
            if(str[i]==';')
                str[i] =' ';

            if('A'<=str[i]&&str[i]<='Z')
                st.insert(str[i]);
        }

        vi ara;
        siter(st,char)
        ara.pb(*it);

        stringstream ss(str);
        string xx;

        for(int i='A'; i<='Z'; i++)
            nod[i].clear();

        while(ss>>xx)
            for(int i=2; xx[i]; i++)
            {
                nod[xx[0]].pb(xx[i]);
                nod[xx[i]].pb(xx[0]);
            }

        int mn = inf;
        int pos[200] = {};
        string ans;

        do
        {
            for(int i=0; i<ara.size(); i++)
                pos[ara[i]] = i;

            int mx,mmx=0;
            for(int i='A'; i<='Z'; i++)
            {
                mx = 0;
                for(int j=0; j<nod[i].size(); j++)
                    mx = max(mx,abs(pos[i]-pos[nod[i][j]]));

                mmx = max(mmx,mx);
            }


            if(mn>mmx)
            {
                mn = mmx;
                ans.clear();
                for(int i = 0; i<ara.size(); i++)
                    ans.pb((char)ara[i]);
            }

        }
        while(next_permutation(all(ara)));

        for(int i=0; ans[i]; i++)
            cout<<ans[i]<<' ';
        pf("-> %d\n",mn);

    }

    return 0;
}











