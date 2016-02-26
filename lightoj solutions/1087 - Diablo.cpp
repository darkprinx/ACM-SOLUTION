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
#define M 150000
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

int ara[M];

struct st
{
    int tot,id;
}tree[M*4];



void init(int nod,int b,int e)
{
    if(b==e)
    {
        tree[nod].id=ara[b];
        tree[nod].tot=1;
        return;
    }

    int mid=(b+e)/2;
    int left=nod*2;;
    int right=left+1;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[nod].id=-1;
    tree[nod].tot=tree[left].tot+tree[right].tot;
}

void update(int nod,int b,int e,int i,int x)
{
    if(i>e||i<b)
        return;

    if(b==e)
    {
        tree[nod].id=x;
        tree[nod].tot=1;
        return;
    }

    int mid=(b+e)/2;
    int left=nod*2;;
    int right=left+1;

    update(left,b,mid,i,x);
    update(right,mid+1,e,i,x);

    tree[nod].tot=tree[left].tot+tree[right].tot;
}

void qury(int nod,int b,int e,int i)
{
    int mid=(b+e)/2;
    int left=nod*2;;
    int right=left+1;

    if(tree[nod].id!=-1)
    {
        pf("%d\n",tree[nod].id);
        tree[nod].id=-1;
        tree[nod].tot=0;
        return;
    }

    if(tree[left].tot>=i)
    qury(left,b,mid,i);
    else
    qury(right,mid+1,e,i-tree[left].tot);

    tree[nod].tot=tree[left].tot+tree[right].tot;
}



int main()
{
    int test,n,q,cnt,pos,total,num;
    char ch;
    fs(test);

    Sfor(test)
    {
        fs(n);
        fs(q);
        cnt=total=n;
        loop(j,0,n)
        fs(ara[j]);

        init(1,0,n+q-1);

        pf("Case %d:\n",i);
        loop(j,0,q)
        {
        scanf("%c",&ch);
        getchar();
        if(ch=='a')
        {
            fs(num);
            update(1,0,n+q-1,cnt,num);
            cnt++;
            total++;
        }
        else
        {
            fs(num);
            if(num>total)
                pf("none\n");
            else
            {
            qury(1,0,n+q-1,num);
            total--;
            }
        }
        }
    }

    return 0;
}






