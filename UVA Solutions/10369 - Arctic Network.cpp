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
map<int,int> par;

struct edge
{
    int u,v;
    float w;
    bool operator < (const edge&p)const
    {
        return w<p.w;
    }
};
vector<edge> sat;
vector<float> man;

float rep(int n)
{
    if(par[n]==n)
        return n;
    return par[n]=rep(par[n]);
}

double distance(int x1,int y1,int x2,int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

float MST(int m,int n)
{
    int u,v,j,cnt=0;
    Sfor(n)
    par[i]=i;
    sort(all(sat));
    for(int i=0;i<sat.size();i++)
    {
        u=rep(sat[i].u);
        v=rep(sat[i].v);
        if(u!=v)
        {
            par[u]=v;
            man.push_back(sat[i].w);
            cnt++;
        }
        if(cnt==m-n)
            break;
    }
    return man[man.size()-m];
}

int main()
{
    int test,S,p,i,j,k;
    double dis;
    s(test);
    edge get;
    loop(i,0,test)
    {
        s(S);
        s(p);
        int cor[p+1][2];
        loop(j,0,p)
        {
            cin>>cor[j][0]>>cor[j][1];
        }
        for(j=0;j<p;j++)
        {
            for(k=j+1;k<p;k++)
            {
             dis=distance(cor[j][0],cor[j][1],cor[k][0],cor[k][1]);
             get.u=j;
             get.v=k;
             get.w=dis;
             sat.push_back(get);
            }
        }
        pf("%.2f\n",MST(S,p));
        sat.clear();
        man.clear();
        par.clear();
    }
    return 0;
}



