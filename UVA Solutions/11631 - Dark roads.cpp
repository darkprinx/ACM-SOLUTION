/* Problem Name: 11631- Dark Roads
   Platform: UVA
   Algorithom: MST (Kruskal)
   Coder's Name: R C Tushar
*/

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


#define PS system("pause")
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define Sfor(n) for(int i=1;i<=n;i++)
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

using namespace std;

map<int,int> num;

struct edge
{
    int u,v,w;
    bool operator <(const edge&p)const
    {
        return w<p.w;
    }
};

vector<edge>sat;

int rep(int n)
{
    if(num[n]==n)
        return n;
    return num[n]=rep(num[n]);
}
int MST(int n)
{
    int cnt=0,sum=0,u,v;
    sort(all(sat));
    int SZ=sat.size();

    for(int i=0;i<SZ;i++)
    {
        u=rep(sat[i].u);
        v=rep(sat[i].v);
        if(u!=v)
        {
            num[u]=v;
            sum+=sat[i].w;
            cnt++;
        }
        if(cnt==n-1)
            break;
    }
    return sum;
}
int main()
{
int m,n,a,b;
while(s(m)==1&&s(n)==1)
{
    int calc=0;
    if(m==0&&n==0)
        break;

    loop(i,0,m)
    num[i]=i;

    edge get;
    loop(i,0,n)
    {
        cin>>get.u>>get.v>>get.w;
        calc+=get.w;
        sat.push_back(get);
    }
    cout<<calc-MST(m)<<endl;
num.clear();
sat.clear();
}


return 0;
}



