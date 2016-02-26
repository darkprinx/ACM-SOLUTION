

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
#define M 100005
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

//~~~~~~~~~~~~~~~~~CODE STARTING POINT~~~~~~~~~~~~~~~~~~~~~~

int T[M],D[M],P[M][22],mnd[M][22],mxd[M][22];
int lev[M],mn;

vector<pii>node[M];

void dfs(int par,int u,int dep)
{
	lev[u]=dep;
	int len=node[u].size();
	for(int i=0;i<len;i++)
	{
		if(node[u][i].F!=par)
		{
			T[node[u][i].F]=u;
			D[node[u][i].F]=node[u][i].S;
			dfs(u,node[u][i].F,dep+1);
		}
	}
}

void bosho(int N)
{
	Mems(P,-1);

    for (int i = 1; i <= N; i++)
       {
          P[i][0] = T[i];
          mxd[i][0]=D[i];
          mnd[i][0]=D[i];
	  }

    for (int j = 1; 1 << j < N; j++)
         for (int i = 1; i <= N; i++)
         {
			 if (P[i][j - 1] != -1)
			 {
				 mxd[i][j]=max(mxd[i][j-1],mxd[P[i][j-1]][j-1]);
				 mnd[i][j]=min(mnd[i][j-1],mnd[P[i][j-1]][j-1]);
                 P[i][j] = P[P[i][j - 1]][j - 1];
			 }
		 }
}


int mx=0;
int khujo(int N,int p,int q)
{
	int log, i;
	if (lev[p] < lev[q])
          swap(p,q);
    for (log = 1; 1 << log <= lev[p]; log++);
      log--;

      for (i = log; i >= 0; i--)
          if (lev[p] - (1 << i) >= lev[q])
          {
			  mx=max(mx,mxd[p][i]);
			  mn=min(mn,mnd[p][i]);
              p = P[p][i];
		  }

      if (p == q)
          return p;

      for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
          {
               mx=max3(mx,mxd[p][i],mxd[q][i]);
               mn=min3(mn,mnd[p][i],mnd[q][i]);
               p = P[p][i];
              q = P[q][i];
		  }
     mx=max3(mx,D[p],D[q]);
     mn=min3(mn,D[p],D[q]);
     return T[p];
}
int main()
{
	int test;
	fs(test);
	Sfor(test)
	{
		int n,q;
		fs(n);
		loop(j,1,n+1)
		node[j].clear();

		loop(j,1,n)
		{
			int a,b,c;
			fs(a);
			fs(b);
			fs(c);
			node[a].pb(pii(b,c));
			node[b].pb(pii(a,c));
		}
		dfs(-1,1,1);
		bosho(n);
		fs(q);
		printf("Case %d:\n",i);
		loop(j,0,q)
		{
			int x,y;
			mx=0;
			mn=inf;
			fs(x);
			fs(y);
            khujo(n,x,y);
            pf("%d %d\n",mn,mx);
		}
	}
}
