/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name:
       Platform:
     Algorithom:
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
#define M 10500
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction
//freopen("sum.in","r",stdin);
//freopen("sum.out","w",stdout);
typedef vector<int> vi;


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


bool ara[M+2]={};
map<int,int> fact;
vi num;

void siv()
{
    for(int i=2;i*i<=M;i++)
        if(!ara[i])
        for(int j=i;i*j<=M;j++)
        ara[i*j]=true;

    for(int i=2;i<=M;i++)
        if(!ara[i])
        num.pb(i);
}

void calc(int n)
{
    for(int i=0;num[i]*num[i]<=n;i++)
    {
        int cnt=0;
        if(n%num[i]==0)
        {
            while(n%num[i]==0)
            {
                n/=num[i];
                cnt++;
            }
            if(fact[num[i]]<cnt)
                fact[num[i]]=cnt;
        }
    }
    if(n>1&&fact[n]==0)
        fact[n]=1;
}

ll fast_pow(ll n,ll p)
{
    if(p==0)
        return 1;
    ll ans;
    if(p%2)
    {
        ans=(n*fast_pow(n,p-1));
        return ans;
    }
    else
    {
        ans=fast_pow(n,p/2);
        ans=(ans*ans);
        return ans;
    }
}


string mult(string a, string b)
{
    int len= a.length() + b.length();
    string result(len, '0'),ret;
    int num;
    int i, j;
    int last_pos_i, last_pos_j, last_pos_k;
    last_pos_i= len - 1;
    for (i= b.length() - 1; i >= 0; i --)
    {
        last_pos_j= last_pos_i;
        for (j= a.length() - 1; j >=0; j --)
        {
            last_pos_k= last_pos_j;
            num= INT(a[j]) * INT(b[i]);
            while (num)
            {
                num += INT(result[last_pos_k]);
                result[last_pos_k]= CHAR(num % 10);
                num= num / 10;
                last_pos_k --;
            }
            last_pos_j --;
        }
        last_pos_i --;
    }

    if(result[0]==48)
        result.erase(0,1);

    if(result[0]==48)
        return "0";
    return result;
}

int main()
{
    siv();
    int test,n,eid[1003],ans;
    string str,a;
    fs(test);
    Sfor(test)
    {
        str="1";
        fs(n);
        loop(j,0,n)
            {
                fs(eid[j]);
                calc(eid[j]);
            }
        miter(fact,int,int)
            {
                ans=fast_pow(it->F,it->S);
                stringstream ss;
                ss<<ans;
                a=ss.str();
                str=mult(str,a);
            }

        pf("Case %d: ",i);
        cout<<str<<endl;
        fact.clear();
    }
    return 0;
}
