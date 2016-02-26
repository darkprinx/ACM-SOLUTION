

/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 1188 - FAST QUERIES
       Platform: LightOj
     Algorithom: BIT
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

int tt,n,q,ara[M+3],tree[M+3],prev[M+3],a,b;
   vi num[M+3];
   vi pos[M+3];
    void update(int id,int val)
    {
        while(id<=n)
        {
            tree[id]+=val;
            id+=id&(-id);
        }
    }

    int sum(int id)
    {
        int sum=0;
        while(id>0)
        {
            sum+=tree[id];
            id-=id&(-id);
        }
        return sum;
    }

int main()
{
    fs(tt);
    Sfor(tt)
    {
        fs(n);
        fs(q);
        Mems(prev,0);
        Mems(tree,0);

        loop(j,1,n+1)
        {
            num[j].clear();
            pos[j].clear();
        }

        vector<pii> ans;

        loop(j,1,n+1)
        fs(ara[j]);

        loop(j,0,q)
        {
            fs(a);
            fs(b);
            num[b].pb(a);
            pos[b].pb(j);
        }



        for(int j=1;j<=n;j++)
        {
            if(prev[ara[j]])
                update(prev[ara[j]],-1);
            update(j,1);
            prev[ara[j]]=j;
            for(int k=0;k<num[j].size();k++)
                ans.pb(pii(pos[j][k],sum(j)-sum(num[j][k]-1)));
        }
        sort(all(ans));

        printf("Case %d:\n",i);
        int len=ans.size();
        for(int j=0;j<len;j++)
        pf("%d\n",ans[j].S);
    }
   return 0;
}



