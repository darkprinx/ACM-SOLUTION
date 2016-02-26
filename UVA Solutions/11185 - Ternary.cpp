
/* Problem Name: 11185 TERNARY
       Platform: UVA
     Algorithom: AD HOC ( INTIGER TO TERNARY CONVERSATION)
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
#include <fstream>
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
#define bit_cnt(x)   __builtin_popcount(x)
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))
using namespace std;

string itot(ll a)
{
    string num;
    int rem;
    while(a!=0)
    {
        if(a%3==0)
        {
            a/=3;
            num.pb(48);
        }
        else
        {
         rem=a%3;
         if(rem==1)
         {
             a=a-1;
             a/=3;
             num.pb(49);
         }
         else if(rem==2)
         {
             a=a-2;
             a/=3;
             num.pb(50);
         }
        }
    }
    int len=num.length();
    string ans;
    for(int i=len-1;i>=0;i--)
        ans.pb(num[i]);

    return ans;
}

int
main()
{
ll a;
while(cin>>a&&a>-1)
{
    if(a==0)
        cout<<0<<endl;
    else
    cout<<itot(a)<<endl;
}

return 0;
}



