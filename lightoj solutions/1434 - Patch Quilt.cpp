/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 1434 - Patch Quilt
       Platform: LightOj
     Algorithom: DFS
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

#define M  1000000


// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int r,c;
char ara[35][35];
bool mark[32][32][32];
int dp[32][32][32];

string str;
int ln;


bool dfs(int i,int j,int pos)
{
    if(pos==ln-1)
        return true;

    bool chk=false,tmp;

    if(BOUNDARY(i,j,r,c)&&ara[i][j]==str[pos+1]&&!mark[i][j][pos+1])
    {
        mark[i][j][pos+1]=true;
        tmp=dfs(i,j,pos+1);
        if(tmp)
            dp[i][j][pos]=1;
        chk|=tmp;

    }
    if(BOUNDARY(i+1,j,r,c)&&ara[i+1][j]==str[pos+1]&&!mark[i+1][j][pos+1])
    {
        mark[i+1][j][pos+1]=true;
        tmp=dfs(i+1,j,pos+1);
        if(tmp)
            dp[i][j][pos]=2;
        chk|=tmp;
    }
    if(BOUNDARY(i-1,j,r,c)&&ara[i-1][j]==str[pos+1]&&!mark[i-1][j][pos+1])
    {
        mark[i-1][j][pos+1]=true;
        tmp=dfs(i-1,j,pos+1);
        if(tmp)
            dp[i][j][pos]=3;
        chk|=tmp;
    }
    if(BOUNDARY(i,j+1,r,c)&&ara[i][j+1]==str[pos+1]&&!mark[i][j+1][pos+1])
    {
        mark[i][j+1][pos+1]=true;
        tmp=dfs(i,j+1,pos+1);
        if(tmp)
            dp[i][j][pos]=4;
        chk|=tmp;
    }
    if(BOUNDARY(i,j-1,r,c)&&ara[i][j-1]==str[pos+1]&&!mark[i][j-1][pos+1])
    {
        mark[i][j-1][pos+1]=true;
        tmp=dfs(i,j-1,pos+1);
        if(tmp)
            dp[i][j][pos]=5;
        chk|=tmp;
    }
    if(BOUNDARY(i+1,j+1,r,c)&&ara[i+1][j+1]==str[pos+1]&&!mark[i+1][j+1][pos+1])
    {
        mark[i+1][j+1][pos+1]=true;
        tmp=dfs(i+1,j+1,pos+1);
        if(tmp)
            dp[i][j][pos]=6;
        chk|=tmp;
    }
    if(BOUNDARY(i+1,j-1,r,c)&&ara[i+1][j-1]==str[pos+1]&&!mark[i+1][j-1][pos+1])
    {
        mark[i+1][j-1][pos+1]=true;
        tmp=dfs(i+1,j-1,pos+1);
        if(tmp)
            dp[i][j][pos]=7;
        chk|=tmp;
    }
    if(BOUNDARY(i-1,j+1,r,c)&&ara[i-1][j+1]==str[pos+1]&&!mark[i-1][j+1][pos+1])
    {
        mark[i-1][j+1][pos+1]=true;
        tmp=dfs(i-1,j+1,pos+1);
        if(tmp)
            dp[i][j][pos]=8;
        chk|=tmp;
    }
    if(BOUNDARY(i-1,j-1,r,c)&&ara[i-1][j-1]==str[pos+1]&&!mark[i-1][j-1][pos+1])
    {
        mark[i-1][j-1][pos+1]=true;
        tmp=dfs(i-1,j-1,pos+1);
        if(tmp)
            dp[i][j][pos]=9;
        chk|=tmp;
    }
    return chk;
}

void path_print(int i,int j,int pos)
{

    switch(dp[i][j][pos])
    {
    case 1:
        pf(" *");
        if(pos<ln-2)
            pf(",");
        path_print(i,j,pos+1);
        break;
    case 2:
        pf(" D");
        if(pos<ln-2)
            pf(",");
        path_print(i+1,j,pos+1);
        break;
    case 3:
        pf(" U");
        if(pos<ln-2)
            pf(",");
        path_print(i-1,j,pos+1);
        break;
    case 4:
        pf(" R");
        if(pos<ln-2)
            pf(",");
        path_print(i,j+1,pos+1);
        break;
    case 5:
        pf(" L");
        if(pos<ln-2)
            pf(",");
        path_print(i,j-1,pos+1);
        break;
    case 6:
        pf(" DR");
        if(pos<ln-2)
            pf(",");
        path_print(i+1,j+1,pos+1);
        break;
    case 7:
        pf(" DL");
        if(pos<ln-2)
            pf(",");
        path_print(i+1,j-1,pos+1);
        break;
    case 8:
        pf(" UR");
        if(pos<ln-2)
            pf(",");
        path_print(i-1,j+1,pos+1);
        break;
    case 9:
        pf(" UL");
        if(pos<ln-2)
            pf(",");
        path_print(i-1,j-1,pos+1);
        break;
    }
}


int main()
{
    int tt,n;
    fs(tt);
    string xx;
    for(int kk=1; kk<=tt; kk++)
    {
        fs(r);
        fs(c);

        loop(i,0,r)
        loop(j,0,c)
        cin>>ara[i][j];

        fs(n);
        pf("Case %d:\n",kk);
        loop(k,0,n)
        {
            cin>>str;
            ln=str.size();

            bool flag=false;
            Mems(mark,false);
            Mems(dp,-1);
            for(int i=0; i<r&&!flag; i++)
                for(int j=0; j<c&&!flag; j++)
                {
                    if(ara[i][j]==str[0])
                    {
                        flag|=dfs(i,j,0);
                        if(flag)
                        {
                            pf("%s found:",str.c_str());
                            pf(" (%d,%d),",i+1,j+1);
                            path_print(i,j,0);
                            pf("\n");
                        }
                    }
                }
            if(!flag)
                pf("%s not found\n",str.c_str());
        }

    }
    return 0;
}








