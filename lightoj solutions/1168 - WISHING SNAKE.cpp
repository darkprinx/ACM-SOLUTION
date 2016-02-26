/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 1168 - WISHING SNAKE
       Platform: LightOj
     Algorithom: SCC
  Author's Name: RC Tushar



                 শুনেছি তোমার ভীষণ রাগ ?
                              সে কি রাগ , নাকি
                                     মগজ কোণে পচন ধরা
                 পুরনো কোডের বাগ ?


         ~~~~~ MY DEDICATION TO SOME FRIENDS ~~~~~

   Kim: Whenever you start to believe  yourself, people also start to believe in you.
  Oshy: Every programming contest is like a new life.To do better in every life you must dedicate your real life.
 Elise: Keep studying and the improvement will come. it's a slow process but each step is rewarding.


 ~~~     Never Lose Hope     ~~~
*/


#include<bits/stdc++.h>
#define pi 2*acos(0.0)
#define PS system("pause")
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
#define rall(x) (x).rbegin(),(x).rend()
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pf printf
#define ll long long int
#define ull unsigned long long int
#define MOD 1000000007
#define sqr(x) (( (x)* (x))%MOD)
#define cube(x)   ( (sqr(x)*(x))%MOD)
#define bit_cnt(x)   __builtin_popcount(x)
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define btz(a)   __builtin_ctz(a)
#define Mems(p,n) memset(p, n, sizeof(p))
#define BOUNDARY(i,j,Row,Col) ((i >= 0 && i < Row) && (j >= 0 && j < Col))
#define ubound(d,val)  int (upper_bound (d.begin(), d.end(), val) - d.begin())
#define lbound(d,val)  int (lower_bound (d.begin(), d.end(), val) - d.begin())

using namespace std;

//int dx[]= {1,0,-1,0};
//int dy[]= {0,1,0,-1};                        //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,bool> pib;
typedef pair<double,double> pdd;
typedef pair<int,char> pic;
typedef pair< int, pii> ipii;


//TEMPLATES
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


int sat(int n,int pos)
{
    return n=n | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool cak(int n,int pos)
{
    return (bool)(n&(1<<pos));
}

ll binPow(ll a, ll q, ll mud)
{
    a %= mud;
    if (q == 0) return 1;
    return ((q % 2 == 1 ? a : 1) * binPow(a * a, q / 2, mud)) % mud;
}

#define M 1000

// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool ara[M+5][M+5];
vi nod[M+4],bod[M+5],ans[M+5];
bool mark[M+5];
stack<int> st;
vi num;
int lead[M+5];


void dfs1(int u)
{
    if(mark[u])
       return ;
    mark[u]=true;
    for(int i=0;i<nod[u].size();i++)
        {
            int v=nod[u][i];
            dfs1(v);
        }
    st.push(u);
}

void dfs2(int u,int ld)
{
    if(mark[u])
       return ;
    mark[u]=true;
    lead[u]=ld;

    for(int i=0;i<bod[u].size();i++)
        {
            int v=bod[u][i];
            dfs2(v,ld);
        }
}

void dfs3(int u)
{
    mark[u]=true;
    if(ans[u].size()==1)
    dfs3(ans[u][0]);
}

int main()
{
    int test,a,b,mx=0,ch,n,cnt;
    bool flag;

    fs(test);

    Sfor(test)
    {
        fs(n);
        Mems(ara,false);
        Mems(mark,false);
        Mems(lead,-1);

        flag=true;
        for(int j=0;j<num.size();j++)
        {
            nod[num[j]].clear();
            bod[num[j]].clear();
            ans[num[j]].clear();
        }
        num.clear();

        mx=0;

        loop(j,0,n)
        {
            fs(ch);
            loop(k,0,ch)
            {
                fs(a);
                fs(b);

                nod[a].pb(b);
                bod[b].pb(a);
                ara[a][b]=true;

                if(!mark[a])
                    num.pb(a);
                if(!mark[b])
                    num.pb(b);
                mark[a]=mark[b]=true;
                mx=max3(mx,a,b);
            }
        }


        Mems(mark,false);

        dfs1(0);
        for(int j=0;j<num.size();j++)
        if(!mark[num[j]])
        dfs1(num[j]);


        Mems(mark,false);
        set<int> ss;

        while(!st.empty())
        {
            int tp=st.top();
            st.pop();
            if(!mark[tp])
               {
                   dfs2(tp,tp);
                   ss.insert(tp);
               }
        }


        for(int j=0;j<=mx;j++)
        for(int k=0;k<=mx;k++)
        {
            if(lead[j]!=lead[k]&&ara[j][k])
                    ans[lead[j]].pb(lead[k]);
        }


        Mems(mark,false);

        dfs3(0);

        siter(ss,int)
        if(!mark[*it])
        {
            flag=false;
            break;
        }

        if(flag)
            pf("Case %d: YES\n",i);
        else
            pf("Case %d: NO\n",i);


    }
    return 0;
}





