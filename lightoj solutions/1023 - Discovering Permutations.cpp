/* Problem Name: 1023 - DISCOVERING PERMUTATIONS
       Platform: LightOj
     Algorithom: Recursion & Permutation
   Coder's Name: Rc Tushar
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
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include<assert.h>


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
#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))
#define M  20002
using namespace std;

typedef vector<int> vi;
string ara="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector<char>ans;
vector<char>::iterator it;
int take[28]={};
int n,m,cnt;

void call()
{
    if(cnt==m)
        return;
    if(ans.size()==n)
    {
       for(it=ans.begin();it!=ans.end();it++)
       cout<<*it;
       cout<<endl;
       cnt++;
    }

    for(int i=0;i<n;i++)
    {
        if(!take[i])
        {
        take[i]=1;
        ans.pb(ara[i]);
        call();
        take[i]=0;
        ans.pop_back();
        }
    }

}

void input(int i)
{
    s(n);
    s(m);
    cnt=0;
    pf("Case %d:\n",i);
    call();
}

int main()
{
int test;
s(test);
Sfor(test)
{
    input(i);
}


return 0;
}



