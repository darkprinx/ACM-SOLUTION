/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 11352 - Crazy King
       Platform: Uva
     Algorithom: BFS 2D
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
#define M 102
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
int ex[]={-1,0,1,1,1,0,-1,-1}; int ey[]={-1,-1,-1,0,1,1,1,0};
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction
//freopen("sum.in","r",stdin);
//freopen("sum.out","w",stdout);
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

int ara[M][M];
char maze[M][M];
int r,c;
void boshao(int x,int y)
{
    int nx,ny;
    for(int i=0;i<8;i++)
    {
        nx=x+dx[i];
        ny=y+dy[i];
        if(BOUNDARY(nx,ny,r,c)&&maze[nx][ny]!='B'&&maze[nx][ny]!='A')
        maze[nx][ny]='x';
    }
}

int bfs(int x,int y)
{
    int nx,ny,cnt=0;

    queue<pii> q;
    maze[x][y]='x';
    q.push(pii(x,y));

    while(!q.empty())
    {
        pii top=q.front();
        q.pop();

        for(int i=0;i<8;i++)
        {
            nx=top.F+ex[i];
            ny=top.S+ey[i];

            if(BOUNDARY(nx,ny,r,c)&&maze[nx][ny]!='x'&&maze[nx][ny]!='Z')
            {
                ara[nx][ny]=ara[top.F][top.S]+1;
                if(maze[nx][ny]=='B')
                    return ara[nx][ny];
                maze[nx][ny]='x';
                q.push(pii(nx,ny));
            }
        }
    }
    return -1;
}

int main()
{
    int test,x,y;
    stack<pii> st;
    fs(test);
    Sfor(test)
    {
        Mems(ara,0);
        fs(r);
        fs(c);
        loop(i,0,r)
        loop(j,0,c)
        {
            cin>>maze[i][j];
            if(maze[i][j]=='Z')
                st.push(pii(i,j));
            if(maze[i][j]=='A')
                x=i,y=j;
        }

        while(!st.empty())
        {
            pii top=st.top();
            boshao(top.F,top.S);
            st.pop();
        }
        int ans=bfs(x,y);
        if(ans==-1)
            pf("King Peter, you can't go now!\n");
        else
           pf("Minimal possible length of a trip is %d\n",ans);
    }
    return 0;
}
