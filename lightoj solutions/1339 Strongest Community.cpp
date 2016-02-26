

/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 11235 - Frequent values
       Platform: Uva
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
#define ubound(d,val)  int (upper_bound (d.begin(), d.end(), val) - d.begin())
#define lbound(d,val)  int (lower_bound (d.begin(), d.end(), val) - d.begin())
#define M 100100
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

int tree[M*3],ara[M],mara[M],x,y;

void bosho(int nod,int b,int e)
{
    if(b==e)
    {
        tree[nod]=ara[b];
        return;
    }
    int left,right,mid;

    left=2*nod;
    right=left+1;
    mid=(e+b)/2;
    bosho(left,b,mid);
    bosho(right,mid+1,e);
    tree[nod]=max(tree[left],tree[right]);
}

int qury(int nod,int b,int e)
{
    if(x>e||y<b)
        return 0;
    if(b>=x&&e<=y)
    return tree[nod];

    int left,right,mid;

    left=nod*2;
    right=left+1;
    mid=(e+b)/2;

    int p1=qury(left,b,mid);
    int p2=qury(right,mid+1,e);
    return max(p1,p2);
}

int main()
{
    int test,c,n,q;
    map<int,int> num;

    fs(test);

    for(int k=1;k<=test;k++)
    {
        fs(n);
        fs(c);
        fs(q);
        loop(i,1,n+1)
        {
            fs(mara[i]);
            ara[i]=++num[mara[i]];
        }

        bosho(1,1,n);

        pf("Case %d:\n",k);
        loop(i,0,q)
        {
            fs(x);
            fs(y);
            if(mara[x]!=mara[y])
            {
            int dif=num[mara[x]]-ara[x]+1;
            x+=dif;
            printf("%d\n",max(dif,qury(1,1,n)));
            }
            else
            printf("%d\n",y-x+1);

        }
        num.clear();
    }

    return 0;
}
