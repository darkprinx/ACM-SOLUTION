
/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 11831 - Sticker Collector Robot
       Platform: Uva
     Algorithom: Simulation Graph Travars
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
#define M 1000002
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

// ~~~~~~~~~~~~~~~ CODE STARTING POINT ~~~~~~~~~~~~~~~~

char maze[102][102];
bool ara[102][102];
int r,c,x,y,n,cnt,dir,mnt;
char ch;

void hata()
{
   switch(dir)
   {
   case 0:
    if(x-1>0&&maze[x-1][y]!='#')
        x--;
    break;
   case 1:
    if(y+1<=c&&maze[x][y+1]!='#')
        y++;
    break;
   case 2:
    if(x+1<=r&&maze[x+1][y]!='#')
        x++;
    break;
   case 3:
    if(y-1>0&&maze[x][y-1]!='#')
        y--;
    break;
   }
   if(maze[x][y]=='*'&&ara[x][y])
    mnt++,ara[x][y]=false;
}

int main()
{
    while(fs(r)&&fs(c)&&fs(n))
    {
        mnt=0;
        Mems(ara,true);
        if(r==0&&c==0&&n==0)
            break;
        loop(i,1,r+1)
        loop(j,1,c+1)
        {
            cin>>maze[i][j];
            if(maze[i][j]=='N')
                x=i,y=j,cnt=1000;
            if(maze[i][j]=='S')
                x=i,y=j,cnt=1002;
            if(maze[i][j]=='L')
                x=i,y=j,cnt=1001;
            if(maze[i][j]=='O')
                x=i,y=j,cnt=1003;
        }
        dir=cnt%4;
        loop(i,0,n)
        {
            cin>>ch;
            switch(ch)
            {
            case 'D':
                cnt++;
                dir=cnt%4;
                break;
            case 'E':
                cnt--;
                dir=cnt%4;
                break;
            case 'F':
                dir=cnt%4;
                hata();
            }

        }
        cout<<mnt<<endl;
    }
    return 0;
}
