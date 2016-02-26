/*
   Problem Name: 1080 - Binary Simulation
       Platform: LightOj
     Algorithom: Segmented Tree/ Binary Indexed Tree
   Coder's Name: RC Tushar

~~~ Never Show Your Arrogance.Keep In Mind,You Were Born From A Drop Of Impure Water ~~~

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
#define M  100002
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
    int sum,prop;
}tree[M*3];

string str;
void bosho(int node,int b,int e)
{
    if(e==b)
        {
            tree[node].sum=str[b]-48;
            return;
        }
    int left=node*2;
    int right=node*2+1;
    int mid=(e+b)/2;

    bosho(left,b,mid);
    bosho(right,mid+1,e);
}

void date (int node,int b,int e,int i,int j,int taka=1)
{
    if(i>e||j<b)
        return;
    if(b>=i&&e<=j)
    {
        tree[node].sum+=((e-b+1)*taka);
        tree[node].prop+=taka;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(e+b)/2;
    date(left,b,mid,i,j,taka);
    date(right,mid+1,e,i,j,taka);

    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}

int khujo(int node,int b,int e,int i,int taka=0)
{

    if(i>e||i<b)
        return 0;
    if(b==e)
        return tree[node].sum+(e-b+1)*taka;
    int left=node<<1;
    int right=(node<<1)+1;
    int mid=(b+e)>>1;

    int ans1=khujo(left,b,mid,i,taka+tree[node].prop);
    int ans2=khujo(right,mid+1,e,i,taka+tree[node].prop);
    return ans1+ans2;
}

int main()
{

    int test,n,len,a,b,q,taka;
    char c;
    fs(test);
    Sfor(test)
    {
      cin>>str;
      len=str.length();
      Mems(tree,0);
      bosho(1,0,len-1);
      fs(n);
      pf("Case %d:\n",i);
      loop(j,0,n)
      {
          scanf("%c",&c);
          if(c=='I')
          {
              fs(a);
              fs(b);
              date(1,1,len,a,b);
          }
          else if(c=='Q')
          {
            fs(a);
            pf("%d\n",(khujo(1,1,len,a)&1));
          }
      }
    }
    return 0;
}

