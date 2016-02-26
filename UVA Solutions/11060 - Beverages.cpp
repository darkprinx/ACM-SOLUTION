
/* Problem Name: 11060 - Beverages
       Platform: UVA
     Algorithom: TOP SORT (n^2 method)
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

map<string,int> ara;
vector<int> node[102],ans;
string nam[102];

int main()
{

    int n,m,l=1;
    string drink,a,b;
    while(s(n)==1)
    {
        int visit[102]= {};
        int indeg[102]= {};
        for(int i=1; i<=n; i++)
        {
            node[i].clear();
            cin>>drink;
            ara[drink]=i;
            nam[i]=drink;
        }
        s(m);
        for(int i=1; i<=m; i++)
        {
            cin>>a>>b;
            node[ara[a]].pb(ara[b]);
            indeg[ara[b]]++;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            if(!visit[j]&&!indeg[j])
            {
                visit[j]=1;
                ans.pb(j);
                for(int k=0;k<node[j].size();k++)
                    --indeg[node[j][k]];
                break;
            }
        int sz=ans.size(),i;
        pf("Case #%d: Dilbert should drink beverages in this order: ",l);
        for(i=0; i<sz-1; i++)
            cout<<nam[ans[i]]<<' ';
        cout<<nam[ans[i]]<<".\n\n";
        ans.clear();
        ara.clear();
        l++;
    }
    return 0;
}

