/* Problem Name: 1040 - Donation
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
#define M 10003
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
        return w>p.w;
    }
};
int par[52];
int cnt;
int rep(int n)
{
    if(par[n]==n)
        return n;
    else
        return par[n]=rep(par[n]);
}

int mst(int n,priority_queue<st> q)
{
    int sum=0;
    loop(i,0,n)
    par[i]=i;
    cnt=0;
    while(!q.empty())
    {
        st top=q.top();
        q.pop();
        int u,v;
        u=rep(top.u);
        v=rep(top.v);
        if(u!=v)
        {
            cnt++;
            sum+=top.w;
            par[u]=v;
            if(cnt==n-1)
                break;
        }
    }
    return sum;
}

int main()
{
    int test,n,sum,a,b,c;
    s(test);
    Sfor(test)
    {
        priority_queue<st> node;
        s(n);
        sum=0;
        loop(j,0,n)
        loop(k,0,n)
        {
            s(c);
            sum+=c;
            if(c!=0 and j!=k)
                node.push(st(j,k,c));
        }
        int ans=mst(n,node);
        if(cnt==n-1)
            pf("Case %d: %d\n",i,sum-ans);
        else
            pf("Case %d: -1\n",i);
    }
    return 0;
}
