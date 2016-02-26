/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: Ghajini -1093
       Platform: LightOj
     Algorithom: Segment Tree
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
#define M 100000
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction
//freopen("sum.in","r",stdin);
//freopen("sum.out","w",stdout);
typedef vector<int> vi;
typedef pair<int,int> pii;


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

pii tree[M*3];

int n,d,ara[M+3],i,j;


void bosho(int nod,int b,int e)
{
    int left=nod*2;
    int right=nod*2+1;
    int mid=(e+b)/2;

    if(b==e)
        {
            tree[nod].F=ara[b];
            tree[nod].S=ara[b];
            return;
        }

    bosho(left,b,mid);
    bosho(right,mid+1,e);

    tree[nod].F=max(tree[left].F,tree[right].F);
    tree[nod].S=min(tree[left].S,tree[right].S);
}

pii query(int nod,int b,int e)
{
    int left=nod*2;
    int right=nod*2+1;
    int mid=(e+b)/2;

    if(b>j||i>e)
        return pii(INT_MIN,INT_MAX);
    if(b>=i&&e<=j)
       return pii(tree[nod].F,tree[nod].S);

    pii p1=query(left,b,mid);
    pii p2=query(right,mid+1,e);

    pii ans;
    ans.F=max(p1.F,p2.F);
    ans.S=min(p1.S,p2.S);
    return ans;
}

int main()
{
    int test;
    fs(test);

    for(int k=1;k<=test;k++)
    {
        fs(n);
        fs(d);

        loop(l,0,n)
        fs(ara[l]);

        Mems(tree,0);
        bosho(1,0,n-1);
        pii ans;
        int mx=0;
        for(int l=0;l+d<=n;l++)
        {
            i=l;
            j=l+d-1;
            ans=query(1,0,n-1);
            mx=max(mx,ans.F-ans.S);
        }
        pf("Case %d: %d\n",k,mx);
    }
    return 0;
}
