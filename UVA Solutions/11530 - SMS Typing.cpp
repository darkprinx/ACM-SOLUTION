
/* Problem Name: 11530-SMS Typing
       Platform: UVA
     Algorithom: AD HoC
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


#define pi 2*acos(0.0)
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
using namespace std;

int main()
{

map<char,int>alph;

alph['a']=1,alph['b']=2,alph['c']=3,alph['d']=1,alph['e']=2,alph['f']=3,alph['g']=1,alph['h']=2,alph['i']=3,alph['j']=1,alph['k']=2,alph['l']=3,alph['m']=1,alph['n']=2,alph['o']=3,alph['p']=1,alph['q']=2,alph['r']=3,alph['s']=4,alph['t']=1,alph['u']=2,alph['v']=3,alph['w']=1,alph['x']=2,alph['y']=3,alph['z']=4,alph[' ']=1;

int n,sum;
string line;
scanf("%d",&n);
getchar();
for(int i=1;i<=n;i++)
{
    sum=0;
    getline(cin,line);
    for(int j=0;line[j]!='\0';j++)
        sum+=alph[line[j]];
    pf("Case #%d: %d\n",i,sum);
}

return 0;
}



