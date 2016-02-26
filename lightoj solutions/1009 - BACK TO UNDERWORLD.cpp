/* Problem Name: 1009 - BACK TO UNDERWORLD
       Platform: LightOj
     Algorithom: BFS (bipartite max/min Compare)
   Coder's Name:
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
#define BOUNDARY(i,j,Row,Col) ((i >= 0 && i <= Row) && (j >= 0 && j <= Col))
#define M  int(1e5)
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction

typedef vector<int> vi;


//~~~~~~~~~~~~~~~~~CODE STARTING POINT~~~~~~~~~~~~~~~~~~~~~~



vi node[M+2];
int cost[M+2];
bool visit[M+2];
int total[2];

void bfs(int u)
{
    queue<int> q;
    cost[u]=0;
    total[cost[u]]++;
    visit[u]=true;
    q.push(u);

    while(!q.empty())
    {
        int u,v;
        u=q.front();
        q.pop();
        for(int i=0;i<node[u].size();i++)
        {
            v=node[u][i];
            if(!visit[v])
            {
                cost[v]=1-cost[u];
                visit[v]=true;
                total[cost[v]]++;
                q.push(v);
            }
        }
    }

}
int main()
{
    int test,n,a,b;
    set<int> ST;
    set<int> ::iterator it;
    s(test);
    Sfor(test)
    {
        s(n);
        for(int j=0;j<n;j++)
        {
            s(a);
            s(b);
            node[a].pb(b);
            node[b].pb(a);
            ST.insert(a);
            ST.insert(b);
        }

        int x1=0,y1=0;
        Mems(visit,false);
        for(it=ST.begin();it!=ST.end();it++)
        {
            if(!visit[*it])
            {
                total[0]=total[1]=0;
                bfs(*it);
                x1=min(x1+total[0],x1+total[1]);
                y1=max(y1+total[0],y1+total[1]);
            }
        }
        pf("Case %d: %d\n",i,max(x1,y1));

        for(it=ST.begin();it!=ST.end();it++)
            node[*it].clear();
        ST.clear();
    }

    return 0;
}





