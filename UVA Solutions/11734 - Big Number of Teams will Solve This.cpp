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

int main()
{

int test,i;

scanf("%d\n",&test);
for(int j=1;j<=test;j++)
{
 string a,b,c;
 getline(cin,a);
 getline(cin,b);
 int len_a=a.length();
 int len_b=b.length();
 if(a==b)
        pf("Case %d: Yes\n",j);
 else if(len_a!=len_b)
     {
         int flag=0;
         for(int i=0;i<len_a;i++)
         {
             if(a[i]!=' ')
                c.push_back(a[i]);
         }
         if(b==c)
            pf("Case %d: Output Format Error\n",j);
         else
            pf("Case %d: Wrong Answer\n",j);
     }
     else
            pf("Case %d: Wrong Answer\n",j);
 c.clear();
}
return 0;
}



