/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 1039 - A Toy Company
       Platform: LightOj
     Algorithom: Fucking BFS
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
#define M 10500
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction
//freopen("sum.in","r",stdin);
//freopen("sum.out","w",stdout);
typedef vector<int> vi;
typedef pair<string,int> pii;;


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


bool mark[130][130][130];
bool mara[130][130][130];
string str,vtr;

char cng(char a)
{
    if(a==96)
        return 'z';
    if(a==123)
        return 'a';
    return a;
}

bool ck(string x)
{
    if(mark[x[0]][x[1]][x[2]])
        return true;
    return false;
}

int bfs(string x)
{
    queue<pii> q;
    pii ret;
    string y;

    q.push(pii(x,0));
    mark[x[0]][x[1]][x[2]]=true;

    while(!q.empty())
    {
        ret=q.front();
        q.pop();

        x=ret.F;
        if(mara[x[0]][x[1]][x[2]])
            continue;

        if(ret.F==str)
            return ret.S;

        for(int i=0;i<3;i++)
        {
            x=ret.F;
            x[i]=cng(x[i]+1);
            if(!ck(x))
            {
                mark[x[0]][x[1]][x[2]]=true;
                q.push(pii(x,ret.S+1));
            }
            y=ret.F;
            y[i]=cng(y[i]-1);
            if(!ck(y))
            {
                mark[y[0]][y[1]][y[2]]=true;
                q.push(pii(y,ret.S+1));
            }
        }

    }
    return -1;
}

int main()
{

    int test,n;
    string x,y,z;
    fs(test);

    Sfor(test)
    {
        Mems(mark,false);
        Mems(mara,false);

        cin>>vtr>>str;
        fs(n);

        for(int j=0; j<n; j++)
        {
            cin>>x>>y>>z;

            for(int a=0; x[a]; a++)
                for(int b=0; y[b]; b++)
                    for(int c=0; z[c]; c++)
                        mara[x[a]][y[b]][z[c]]=true;
        }

    pf("Case %d: %d\n",i,bfs(vtr));

    }
    return 0;
}
