
/* Problem Name: 10931 - Parity
       Platform: UVA
      Algorithm: AD HOC (bit manupulition)
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
#define bit_cnt(x)   __builtin_popcount(x)
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))
using namespace std;

string itob(int p)
{
    string num;
    while(p!=0)
    {
        if(p%2==0)
        {
            p/=2;
            num.push_back(48);
        }
        else
        {
            p-=1;
            p/=2;
            num.push_back(49);
        }
    }
    int len=num.length();
    string ans(len,0);
    for(int i=len-1,j=0;i>=0;i--,j++)
    {
        ans[j]=num[i];
    }
    return ans;
}
int main()
{
int n;
string bit;
while(s(n)==1&&n!=0)
{
    bit=itob(n);
    cout<<"The parity of "<<bit<<" is "<<bit_cnt(n)<<" (mod 2)."<<endl;
}

return 0;
}



