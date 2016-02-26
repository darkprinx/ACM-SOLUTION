/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 1257 - FARTHEST NODES IN A TREE (II)
       Platform: LightOj
     Algorithom: DFS/BFS
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
#define ubound(d,val)  int (upper_bound (d.begin(), d.end(), val) - d.begin())
#define lbound(d,val)  int (lower_bound (d.begin(), d.end(), val) - d.begin())
#define M 30000
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction
//freopen("sum.in","r",stdin);
//freopen("sum.out","w",stdout);
typedef vector<int> vi;


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


vi nod[M+2],cost[M+2];
int dis_a[M+2], dis_b[M+2],d[M+2],point,mx,cnt;
bool mark[M+2];

void dfs(int u)
{

    mark[u]=true;

    for(int i=0; i<nod[u].size(); i++)
    {
        int v=nod[u][i];
        int vcost=cost[u][i];
        if(!mark[v])
        {
            if(!cnt)
            {
                if(d[u]+vcost>d[v])
                {
                    d[v]=d[u]+vcost;
                    if(d[v]>mx)
                    {
                        mx=d[v];
                        point=v;
                    }
                    dfs(v);
                }
            }
            if(cnt==1)
            {
                if(dis_a[u]+vcost>dis_a[v])
                {
                    dis_a[v]=dis_a[u]+vcost;
                    if(dis_a[v]>mx)
                    {
                        mx=dis_a[v];
                        point=v;
                    }
                    dfs(v);
                }
            }
            if(cnt==2)
            {
                if(dis_b[u]+vcost>dis_b[v])
                {
                    dis_b[v]=dis_b[u]+vcost;
                    dfs(v);
                }
            }
        }
    }
}

int main()
{

    int tt,a,b,c,n;
    fs(tt);
    Sfor(tt)
    {
        fs(n);
        loop(j,0,n)
        {
            nod[j].clear();
            cost[j].clear();
            dis_a[j]=0;
            dis_b[j]=0;
            d[j]=0;
            mark[j]=false;
        }

        loop(j,0,n-1)
        {
            fs(a);
            fs(b);
            fs(c);
            nod[a].pb(b);
            nod[b].pb(a);
            cost[a].pb(c);
            cost[b].pb(c);
        }

        mx=0;
        cnt=0;
        dfs(0);
        loop(j,0,n)
        mark[j]=false;
        cnt++;
        mx=0;
        dfs(point);
        loop(j,0,n)
        mark[j]=false;
        cnt++;
        dfs(point);

        pf("Case %d:\n",i);
        loop(j,0,n)
        pf("%d\n",max(dis_a[j],dis_b[j]));

    }
    return 0;
}





