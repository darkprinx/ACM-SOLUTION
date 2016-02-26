/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 12086 - Potentiometers
       Platform: Uva
     Algorithom: Segment tree
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
#define M  200000
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction

typedef vector<int> vi;
typedef pair<int,int> pii;

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

int n,q,ara[M+2],tree[M*3],i,j,c;


void bosho(int nod,int b,int e)
{
    if(e==b)
    {
        tree[nod]=ara[e];
        return;
    }
    int left,right,mid;
    left=2*nod;
    right=2*nod+1;
    mid=(b+e)/2;

    bosho(left,b,mid);
    bosho(right,mid+1,e);
    tree[nod]=tree[left]+tree[right];
}

void update(int nod,int b,int e)
{

    if(b>i||i>e)
        return;
    if(b>=i&&e<=i)
    {
        tree[nod]=c;
        return;
    }

    int left,right,mid;

    left=2*nod;
    right=2*nod+1;

    mid=(b+e)/2;

    update(left,b,mid);
    update(right,mid+1,e);

    tree[nod]=tree[left]+tree[right];
}


int query(int nod,int b,int e)
{

    if(b>j||i>e)
        return 0;
    if(b>=i&&e<=j)
        return tree[nod];

    int left,right,mid;

    left=2*nod;
    right=2*nod+1;

    mid=(b+e)/2;

    int p1=query(left,b,mid);
    int p2=query(right,mid+1,e);
    return p1+p2;
}
int main()
{
    int l=0;
    bool flag=true;
    string str;
    int test;
    while(cin>>test&&test!=0)
    {
        loop(k,1,test+1)
        fs(ara[k]);
        bosho(1,1,test);
        if(!flag)
            pf("\n");
        else
            flag=false;
        pf("Case %d:\n",++l);
        while(cin>>str&&str!="END")
        {
            if(str=="S")
            {
                fs(i);
                fs(c);
                update(1,1,test);
            }
            else
            {
                fs(i);
                fs(j);
                cout<<query(1,1,test)<<endl;
            }
        }
    }
    return 0;
}




