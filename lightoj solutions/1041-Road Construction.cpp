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
#define MAX 100003
using namespace std;

typedef pair<int,int>pii;
typedef vector<int>vi;

map<string,string> city;
map<string,string> ::iterator it;

struct edge
{
    string u,v;
    int w;
    bool operator<(const edge&p)const
    {
        return w<p.w;
    }
};
vector<edge> line;

string REP(string n)
{
    return(city[n]==n)?n:city[n]=REP(city[n]);
}
int MST(int n)
{
    string u,v;
    sort(all(line));
    int cnt=0,sum=0,len;
    len=line.size();
    for(int i=0;i<len;i++)
    {
        u=REP(line[i].u);
        v=REP(line[i].v);
        if(u!=v)
        {
            city[u]=v;
            cnt++;
            sum+=line[i].w;
            if(cnt==n-1)
                break;
        }
    }
    return sum;
}


int main()
{
    int test,n,cost;
    string a,b;
    s(test);
    set<string> X;
    for(int i=1; i<=test; i++)
    {
        edge get;
        s(n);
        for(int j=1; j<=n; j++)
        {
            cin>>get.u;
            cin>>get.v;
            s(get.w);
            city[get.u]=get.u;
            city[get.v]=get.v;
            line.push_back(get);
        }
        cost=MST(city.size());
        for(it=city.begin();it!=city.end();it++)
        {
            X.insert(REP(it->first));
        }
        if(X.size()==1)
            pf("Case %d: %d\n",i,cost);
        else
            pf("Case %d: Impossible\n",i);
        city.clear();
        X.clear();
        line.clear();
    }
}





