/* Problem Name: 1123 - Trail Maintenance
       Platform: LightOj
     Algorithom: MST
   Coder's Name: RC Tushar
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
#define M 6003
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
    bool operator<(const st & p)const
    {
        return w<p.w;
    }
};
int par[M];
bool flag;
vector<st> node,fode;
int rep(int n)
{
    if(par[n]==n)
        return n;
    else
        return par[n]=rep(par[n]);
}

int mst(int n)
{
    int sum=0,cnt=0;
    loop(i,1,n+1)
    par[i]=i;
    sort(all(node));
    int len=node.size();

    for(int i=0;i<len;i++)
    {
        int u,v;
        u=rep(node[i].u);
        v=rep(node[i].v);
        if(u!=v)
        {
            cnt++;
            sum+=node[i].w;
            fode.pb(st(u,v,node[i].w));
            par[u]=v;
            if(cnt==n-1)
                break;
        }
    }
    if(cnt!=n-1)
        return -1;
    return sum;
}

int main()
{
    int test,n,a,b,c,ara[M],w;
    s(test);
    Sfor(test)
    {
        int cnt=0;
        bool flag=false;
        node.clear();
        s(n);
        s(w);
        loop(j,1,n+1)
        par[j]=j;

        loop(j,1,w+1)
        {
            s(a);
            s(b);
            s(c);
            node.pb(st(a,b,c));
            if(!flag)
            {
            if(rep(a)!=rep(b))
                {
                    cnt++;
                    par[a]=b;
                }
            if(cnt==n-1)
                {
                    flag=true;
                    ara[j]=mst(n);
                    node=fode;
                }
            else
            ara[j]=-1;
            }
            else
                {
                    ara[j]=mst(n);
                    node=fode;
                }
            fode.clear();
        }
        pf("Case %d:\n",i);
        loop(j,1,w+1)
        pf("%d\n",ara[j]);
    }
    return 0;
}
