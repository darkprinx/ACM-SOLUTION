
/* Problem Name: 11747 - Heavy Cycle Edges
       Platform: UVa
     Algorithom: MST
   Coder's Name: RC Tushar
*/

#include<bits/stdc++.h>

#define pi 2*acos(0.0)
#define PS system("pause")
#define siter(n)  for(set<int>::iterator it=n.begin();it!=n.end();it++)
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
#define M  1002
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

struct st
{
    int u,v,w;
    st (int a,int b,int c)
    {
        u=a;
        v=b;
        w=c;
    }
    bool operator <(const st &p)const
    {
        return w<p.w;
    }
};
vector<st> node;
set<int> q;
int par[M];

int rep(int n)
{
    if(par[n]==n)
        return n;
    else
        return par[n]=rep(par[n]);
}

int mst(int n,int m)
{
    int cnt=0,u,v,MX=0;
    sort(all(node));

    loop(i,0,n)
    par[i]=i;
    for(int i=0;i<m;i++)
    {
        u=rep(node[i].u);
        v=rep(node[i].v);
        MX=max(MX,node[i].w);
        if(u!=v)
            par[u]=v;
        else
          {
              q.insert(MX);
              cnt++;
          }
    }
    if(!cnt)
        pf("forest");
    return cnt;
}

int main()
{
int n,m,a,b,c;
while(s(n)==1&&s(m)==1)
{
    if(n==0&&m==0)
        break;

    node.clear();
    q.clear();
    loop(i,0,m)
    {
        s(a);
        s(b);
        s(c);
        node.pb(st(a,b,c));
    }
    int cnt=mst(n,m),j=0;

    siter(q)
    {
     cout<<*it;
     if(j+1<cnt)
        pf(" ");
     j++;
    }
    pf("\n");
}

return 0;
}




