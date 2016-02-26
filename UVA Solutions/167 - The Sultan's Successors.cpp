/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name:
       Platform:
     Algorithom:
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


int tree[5*M],x,y,lazy[5*M];
pii seg[M*2];
    int qu[M*2];
void update(int nod,int b,int e)
{
    if(x>e||y<b)
        return ;
    if(b>=x&&e<=y)
    {
        tree[nod]+=(e-b+1);
        lazy[nod]+=1;
        return;
    }

    int left,mid,right;

    mid=(b+e)/2;
    left=nod*2;
    right=left+1;

    if(lazy[nod])
    {
        tree[left]+=(lazy[nod]*(mid-b+1));
        tree[right]+=(lazy[nod]*(e-mid));
        lazy[left]+=lazy[nod];
        lazy[right]+=lazy[nod];
        lazy[nod]=0;
    }

    update(left,b,mid);
    update(right,mid+1,e);

    tree[nod]=tree[left]+tree[right];
}

int qury(int nod,int b,int e)
{
    if(x>e||x<b)
        return 0 ;
    if(b>=x&&e<=x)
    return tree[nod];

    int left,mid,right;

    mid=(b+e)/2;
    left=nod*2;
    right=left+1;

    if(lazy[nod])
    {
        tree[left]+=(lazy[nod]*(mid-b+1));
        tree[right]+=(lazy[nod]*(e-mid));
        lazy[left]+=lazy[nod];
        lazy[right]+=lazy[nod];
        lazy[nod]=0;
    }

    int p1=qury(left,b,mid);
    int p2=qury(right,mid+1,e);

    return p1+p2;
}

int main()
{
    int tt,n,q,a,b;
    map<int,int> num;

    fs(tt);

    Sfor(tt)
    {
        Mems(tree,0);
        Mems(lazy,0);
        num.clear();

        fs(n);
        fs(q);

        loop(j,0,n)
        {
            fs(seg[j].F);
            fs(seg[j].S);
            num[seg[j].F]=0;
            num[seg[j].S]=0;
        }

        loop(j,0,q)
            {
                fs(qu[j]);
                num[qu[j]]=1;
            }

        int cnt=0;

        miter(num,int,int)
            num[it->F]=cnt++;

        loop(j,0,n)
        {
            x=num[seg[j].F];
            y=num[seg[j].S];
            update(1,0,cnt-1);
        }

        printf("Case %d:\n",i);
        loop(j,0,q)
        {
            x=num[qu[j]];
            pf("%d\n",qury(1,0,cnt-1));
        }
    }
    return 0;
}
