
/* Problem Name: 929 - Number Maze
       Platform: UVA
     Algorithom: Dijsktra 2D
   Coder's Name: Rc Tushar
*/

#include<bits/stdc++.h>

#define pi 2*acos(0.0)
#define PS system("pause")
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define Sfor(n) for(int i=1;i<=n;i++)
#define inf (1<<30)
#define pb push_back
#define ppb pop_back
#define mp make_pair
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
#define M  1000
using namespace std;

int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
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
int ara[M][M],n,m;


struct st
{
    int x,y,z;
    st (int a,int b,int c){x=a;y=b;z=c;}
    bool operator <(const st &op)const
    {
        return z>op.z;
    }
};
int bfs(int u,int v)
{
    vi k(m,inf);
    vector<vi> d;
    d.clear();
    d.assign(n,k);
    priority_queue<st>q;

    d[u][v]=ara[u][v];
    q.push(st(u,v,d[u][v]));

    while(!q.empty())
    {
        int nx,ny;
        st str=q.top();
        q.pop();

        for(int i=0;i<4;i++)
        {
            nx=dx[i]+str.x;
            ny=dy[i]+str.y;
            if(BOUNDARY(nx,ny,n,m)&&d[str.x][str.y]+ara[nx][ny]<d[nx][ny])
            {
               d[nx][ny]=d[str.x][str.y]+ara[nx][ny];
               q.push(st(nx,ny,d[nx][ny]));
            }
        }
    }
return d[n-1][m-1];
}

int main()
{
int test;
s(test);
Sfor(test)
{
    s(n);
    s(m);
    loop(j,0,n)
    loop(k,0,m)
        cin>>ara[j][k];
    cout<<bfs(0,0)<<endl;
}

return 0;
}



