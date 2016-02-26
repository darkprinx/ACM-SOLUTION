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
#define f(x) (x?x:1)
#define MAX 100003
using namespace std;

typedef pair<int,int>pii;
typedef vector<int>vi;

map<string,string> name;
map<string,int> stor;

map<string,string> ::iterator it;

string REP(string a)
{
    if(name[a]=="")
            return a;
    return name[a]=REP(name[a]);
}

int UN(string a,string b)
{
    int c;
    string u,v;
    u=REP(a);
    v=REP(b);
    if(u!=v)
        {
            name[u]=v;
            stor[v]=f(stor[v])+ f(stor[u]);
            return stor[v];
        }
        return stor[u];
}

int main()
{
    string a,b;
    int i,j,R,C;
    s(R);
    loop(i,0,R)
    {
        int cnt;
        s(C);
        loop(j,0,C)
        {
            cin>>a>>b;
            cnt=UN(a,b);
            cout<<cnt<<endl;
        }
        name.clear();
        stor.clear();
    }
    return 0;
}
