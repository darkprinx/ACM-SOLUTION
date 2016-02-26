/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 11709 - Trust groups
       Platform: Uva
     Algorithom: SCC
  Author's Name: RC Tushar

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
#define ull unsigned long long int
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
#define M 1000005
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
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
typedef pair<double,int> pdi;


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


//|                    Never Let Anyone Know What You Are Thinking
//|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//|                                                                ,-===========.
//|                           /,| ___________((____________\\_                _
//|        ,========.________//_|/===========._#############D_X_....-----====//
//|       (#######(==========\__/__DARKPRINX__\=======.______ --############((
//|        `=======`"        ` ===============|::::.___|[ )] ################\\
//|                                           |####|     ""\###|   :##########\\
//|                                          /####/         \##\     ```"""=,,,))
//|                                         /####/           \##\
//|                                        '===='             `=`
//~~~~~~~~~~~~CODE STARTING POINT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

map<string,vector<string> > nod,bod;

map<string,bool> mark;
stack<string> st;
vector<string> colig;
void dfs(string u)
{
    if(mark[u])
       return;
    mark[u]=true;

    for(int i=0;i<nod[u].size();i++)
        dfs(nod[u][i]);
    st.push(u);
}

void nfs(string u)
{
    if(mark[u])
       return;
    mark[u]=true;

    for(int i=0;i<bod[u].size();i++)
        nfs(bod[u][i]);
}

int main()
{
    string x,y;
    int n,m;

    while(fs(n)&&fs(m))
    {
        if(!m&&!n)
            break;
        colig.clear();
        loop(i,0,n)
        {
            getline(cin,x);
            colig.pb(x);
        }

        nod.clear();
        bod.clear();

        loop(i,0,m)
        {
            getline(cin,x);
            getline(cin,y);
            nod[x].pb(y);
            bod[y].pb(x);
        }

        mark.clear();

        for(int i=0;i<colig.size();i++)
        {
            if(!mark[colig[i]])
                dfs(colig[i]);
        }

        mark.clear();
        int cnt=0;
        while(!st.empty())
        {
            x=st.top();
            st.pop();

            if(!mark[x])
            {
                nfs(x);
                cnt++;
            }
        }
        pf("%d\n",cnt);
    }
    return 0;
}


