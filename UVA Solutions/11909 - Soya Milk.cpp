
/* Problem Name: 11909-Soya Milk
       Platform: UVA
     Algorithom: Computational Geomatry
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


#define pi   2*acos(0.0)
#define conv  pi/180.0
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
typedef vector<int> vi;

int main()
{
int l,w,H,T;
double TR1,TR2,b,h1,h2,x1,x2,y1,y2,z;

while(cin>>l>>w>>H>>T)
{
//    h1=sin(T*conv)*l;
//    x1=cos(T*conv)*l;
//    y1=h1/tan((90-T)*conv);
//
//    h2=sin((90-T)*conv)*H;
//    x2=cos((90-T)*conv)*H;
//    y2=h2/tan(T*conv);
//
//    TR1=.5*h1*(x1+y1)*w;
//    TR2=.5*h2*(x2+y2)*w;
//
//    if(T<=45)
//    pf("%.3lf mL\n",(l*w*H)-TR1);
//    else
//    pf("%.3lf mL\n",TR2);

        b=T*conv;
        if(l*tan(b)<=h)
            printf("%.3f mL\n",(l*w*h)-.5*l*w*l*tan(b));
        else
            printf("%.3f mL\n",.5*w*h*h*1/tan(b));
}


return 0;
}



