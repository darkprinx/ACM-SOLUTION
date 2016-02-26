
/* Problem Name:
       Platform:
     Algorithom:
   Coder's Name:
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
#define M  13
using namespace std;

int dx[]= {1,0,-1,0};
int dy[]= {0,1,0,-1};                        //4 Direction
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

char ara[M][M];
int cost[M][M];
bool visit[M][M];
int ap,cnt,n;
queue<int> q;

int bfs(int x,int y,int t)
{
    if(cnt==0)
        return 0;
    queue<int> p;

    visit[x][y]=true;
    cost[x][y]=0;
    p.push(x);
    p.push(y);

    while(!p.empty())
    {
        int px,py;
        px=p.front();
        p.pop();
        py=p.front();
        p.pop();

        for(int i=0; i<4; i++)
        {
            int nx,ny;
            nx=px+dx[i];
            ny=py+dy[i];
            if(BOUNDARY(nx,ny,n,n)&&ara[nx][ny]!='#'&&!visit[nx][ny]&&ara[nx][ny]<=ap)
            {
                visit[nx][ny]=true;
                cost[nx][ny]=cost[px][py]+1;
                if(ara[nx][ny]==ap)
                {
                    q.push(nx);
                    q.push(ny);
                    ap++;
                    return cost[nx][ny];
                }
                p.push(nx);
                p.push(ny);
            }
        }
    }

}

int main()
{

    int test,ans;
    fs(test);
    Sfor(test)
    {
        fs(n);
        cnt=0;
        loop(j,0,n)
        loop(k,0,n)
        {
            cin>>ara[j][k];
            if(ara[j][k]=='A')
            {
                q.push(j);
                q.push(k);
            }
            if(ara[j][k]>='A'&&ara[j][k]<='Z')
                cnt++;
        }
        ans=0;
        ap=66;
        while(!q.empty())
        {
            int a,b;
            a=q.front();
            q.pop();
            b=q.front();
            q.pop();
            Mems(visit,false);
            --cnt;
            ans+=bfs(a,b,0);
        }
        if(cnt==0)
        pf("Case %d: %d\n",i,ans);
        else
        pf("Case %d: Impossible\n",i);

    }

    return 0;
}



