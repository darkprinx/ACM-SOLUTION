/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~

   Problem Name: 12210 - A Match Making Problem
       Platform: Uva
     Algorithom: Adhoc
  Author's Name: RC Tushar



                 শুনেছি তোমার ভীষণ রাগ ?
                              সে কি রাগ , নাকি
                                     মগজ  কোণে পচন ধরা
                 পুরনো কোডের বাগ ?

   ~~~     Never Lost Hope     ~~~

*/


#include<bits/stdc++.h>
#define pi 2*acos(0.0)
#define PS system("pause")
#define liter(n,T1)  for(list<T1>::iterator it=n.begin();it!=n.end();it++)
#define siter(n,T1)  for(set<T1>::iterator it=n.begin();it!=n.end();it++)
#define miter(n,T1,T2)  for(map<T1,T2>::iterator it=n.begin();it!=n.end();it++)
#define meter(n,T1,T2)  for(map<T1,T2>::iterator it=n.end();it!=n.begin();it--)
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
#define ull unsigned long long int
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
#define M 10000
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<char,char> pcc;
typedef pair<ll,bool> pib;
typedef pair<double,int> pdi;
typedef pair<int,string> pis;


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



//~~~~~~~~~~~~CODE STARTING POINT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


int boy[M+3],girl[M+3];
bool ara[M+3],mara[M+3];
int main()
{
    int a,b,k=0;

    while(fs(a)&&fs(b)&&a+b)
    {
        for(int i=0; i<a; i++)
        {
            fs(boy[i]);
            ara[i]=false;
        }

        for(int i=0; i<b; i++)
        {
            fs(girl[i]);
            mara[i]=false;
        }

        if(a<=b)
        {pf("Case %d: 0\n",++k);continue;}

        sort(boy,boy+a);
        sort(girl,girl+b);

        int mx,x,y;

        for(int i=a-1; i>=0; i--)
        {
            mx=INT_MAX;
            if(!ara[i])
                for(int j=b-1; j>=0; j--)
                {
                    if(!mara[j])
                    {
                        if(abs(boy[i]-girl[j])<mx)
                        {
                            mx=abs(boy[i]-girl[j]);
                            x=i;
                            y=j;
                        }
                    }
                }

//            cout<<boy[x]<<' '<<girl[y]<<' '<<mx<<endl;
//            PS;

             ara[x]=true;
             mara[y]=true;
        }
        mx=INT_MAX;
        for(int i=0;i<a;i++)
            if(!ara[i])
            mx=min(mx,boy[i]);
        pf("Case %d: %d %d\n",++k,a-b,mx);
    }
    return 0;
}
