
/* Problem Name: 558- Wormholes
       Platform: LightOj
     Algorithom: Bellman ford
   Coder's Name: Rc Tushar
*/

#include<bits/stdc++.h>

#define pi 2*acos(0.0)
#define PS system("pause")
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define Sfor(n) for(int i=1;i<=n;i++)
#define inf (1<<30)
#define pb push_back
#define ppb pop_back
#define mp make_pair
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
#define M  2003
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction

typedef vector<int> vi;

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

//~~~~~~~~~~~~~~~~~CODE STARTING POINT~~~~~~~~~~~~~~~~~~~~~~

struct ed
{
    int u,v,w;
};

ed node[M];
vi rn[M];
int d[M];
bool visit[M];
set<int>st;
set<int>::iterator it;

void dfs(int u)
{
    if(!visit[u])
    {
        visit[u]=true;
        st.insert(u);
        for(int i=0;i<rn[u].size();i++)
            dfs(rn[u][i]);
    }
}

bool belm(int n,int m)
{
    Mems(visit,false);
    d[node[0].u]=0;
    bool neg=false;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            int u=node[j].u,v=node[j].v;
            if(d[u]+node[j].w<d[v])
                d[v]=d[u]+node[j].w;
        }
    }

        for(int j=0;j<m;j++)
        {
            int u=node[j].u,v=node[j].v;
            if(d[u]+node[j].w<d[v])
                {
                    neg=true;
                    dfs(u);
                }
        }

    return neg;
}


int main()
{

int n,m,test,a,b,w;
s(test);
Sfor(test)
{
    s(n);
    s(m);

    for(int j=0;j<n;j++)
    {
        d[j]=inf;
        rn[j].clear();
    }
    st.clear();
    for(int j=0;j<m;j++)
    {
        s(a);
        s(b);
        s(w);
        node[j].u=b;
        node[j].v=a;
        rn[b].pb(a);
        node[j].w=w;
    }

    if(belm(n,m))
       {
           pf("Case %d:",i);
           for(it=st.begin();it!=st.end();it++)
           pf(" %d",*it);
           cout<<endl;
       }
    else
        pf("Case %d: impossible\n",i);
}
return 0;
}



