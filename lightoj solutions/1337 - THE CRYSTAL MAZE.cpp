
/* Problem Name: 1337 - THE CRYSTAL MAZE
       Platform: LightOj
     Algorithom: BFS 2D
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
#define BOUNDARY(i,j,Row,Col) ((i >= 1 && i <=Row) && (j >= 1 && j <=Col))
#define M  502
using namespace std;

int dx[]= {1,0,-1,0}; int dy[]= {0,1,0,-1};                        //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction

typedef vector<int> vi;


//~~~~~~~~~~~~~~~~~CODE STARTING POINT~~~~~~~~~~~~~~~~~~~~~~


char bord[M][M];
int cost[M][M];
int n,m,cnt;


int bfs(int x,int y)
{
    queue<int>q,mk;

    cnt=0;
    q.push(x);
    q.push(y);
    cost[x][y]=0;

    while(!q.empty())
    {
        int px,py;
        px=q.front();
        q.pop();
        py=q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nx,ny;
            nx=px+dx[i];
            ny=py+dy[i];
            if(BOUNDARY(nx,ny,n,m)&&cost[nx][ny]==-1&&bord[nx][ny]!='#')
            {
                cost[nx][ny]=0;
                if(bord[nx][ny]=='C')
                    cnt++;

                q.push(nx);
                q.push(ny);

                mk.push(nx);
                mk.push(ny);
            }
        }
    }

    while(!mk.empty())
    {
        int i,j;
        i=mk.front();
        mk.pop();
        j=mk.front();
        mk.pop();
        cost[i][j]=cnt;
    }
    return cost[x][y]=cnt;
}



int main()
{
    int test,q,a,b;

    s(test);
    Sfor(test)
    {
        Mems(cost,-1);
        s(n);
        s(m);
        s(q);

        for(int j=1; j<=n; j++)
            for(int k=1; k<=m; k++)
                cin>>bord[j][k];
        pf("Case %d:\n",i);
        for(int j=0; j<q; j++)
        {
            s(a);
            s(b);
            if(cost[a][b]==-1)
                cout<<bfs(a,b)<<endl;
            else
                cout<<cost[a][b]<<endl;
        }
    }

    return 0;
}





