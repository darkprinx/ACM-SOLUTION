#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include<assert.h>
#include<fstream>

#define PS system("pause")
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define inf 1<<30
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)x.size())
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
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
#define bit_cnt(x)   __builtint_popcount(x)
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))
#define MAX3(a,b,c) max(a,max(b,c))
#define MAX 100003
using namespace std;

typedef pair<int,int>pii;
typedef vector<int>vi;
map<int,int> num;
bool flag;

struct edge1
{
    int u,v,w;
    bool operator<(const edge1& p)const
    {
        return w<p.w;
    }
};
bool comp(edge1 a,edge1 b)
{
    return a.w>b.w;
}

vector<edge1> A;

int REP(int a)
{
    if(num[a]==a)
        return a;
    return num[a]=REP(num[a]);
}
int MST(int n,bool f)
{
    int u,v,len,cnt=0,sum=0;
    if(f)
       sort(A.begin(),A.end(),comp);
    else
       sort(all(A));
    len=A.size();
    for(int i=0; i<len; i++)
    {
        u=REP(A[i].u);
        v=REP(A[i].v);
        if(u!=v)
        {
            num[u]=v;
            cnt++;
            sum+=A[i].w;
            if(cnt==n)
                break;
        }
        else
            flag=false;
    }
    return sum;
}
void clr(int n)
{
    for(int i=0; i<n; i++)
        num[i]=i;
}
int main()
{
    int test,MXT,MNT,c,ans;
    edge1 x;
    s(test);
    for(int k=1; k<=test; k++)
    {
        cin>>c;
        flag=true;
        while(cin>>x.u>>x.v>>x.w)
        {
            if(x.u==0&&x.v==0&&x.w==0)
                break;
            A.push_back(x);
        }
        clr(c+1);
        MNT=MST(c+1,false);

        clr(c+1);
        MXT=MST(c+1,true);
        if(MXT!=MNT)
            ans=MXT+MNT;
        else
            ans=MNT;
        if(flag)
        pf("Case %d: %d\n",k,MNT);
        else
        {
        if(ans%2==0)
        pf("Case %d: %d\n",k,ans/2);
        else
        pf("Case %d: %d/%d\n",k,ans,2);
        }

        num.clear();
        A.clear();

    }
return 0;
}





