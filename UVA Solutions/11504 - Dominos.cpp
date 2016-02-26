/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 11504
       Platform: Uva
     Algorithom: SCC
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
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction
//freopen("sum.in","r",stdin);
//freopen("sum.out","w",stdout);
typedef vector<int> vi;
typedef pair<int,int> pii;


#define  M  100000




vector<int> nod[M+2],renod[M+2];

stack<int> st;

queue<int> qu;


bool mark[M+2];

void dfs1(int u)
{
    if(mark[u])
        return;
    mark[u]=true;
    for(int i=0;i<nod[u].size();i++)
    {
        int v=nod[u][i];
        dfs1(v);
    }
    st.push(u);
}


void dfs2(int u,vi *num)
{
    if(mark[u])
        return;
    mark[u]=true;
    for(int i=0;i<num[u].size();i++)
    {
        int v=num[u][i];
        dfs2(v,num);
    }
}

int main()
{
    int test,m,n,a,b;

    cin>>test;

    for(int i=0;i<test;i++)
    {
        cin>>n>>m;

        for(int j=1;j<=n;j++)
        {
            nod[j].clear();
            renod[j].clear();
            mark[j]=false;
        }

        for(int j=0;j<m;j++)
        {
            cin>>a>>b;
            nod[a].push_back(b);
            renod[b].push_back(a);
        }


        for(int j=1;j<=n;j++)
        if(!mark[j])
            dfs1(j);


        for(int j=1;j<=n;j++)
        mark[j]=false;

        while(!st.empty())
        {
            int tp=st.top();
            st.pop();
            if(!mark[tp])
            {
                qu.push(tp);
                dfs2(tp,renod);
            }
        }



        for(int j=1;j<=n;j++)
        mark[j]=false;

        int cnt=0;

        while(!qu.empty())
        {
            int tp=qu.front();
            qu.pop();
            if(!mark[tp])
            {
            dfs2(tp,nod);
            cnt++;
            }
        }
        cout<<cnt<<endl;

    }

    return 0;
}
