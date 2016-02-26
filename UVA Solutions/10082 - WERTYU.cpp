
/* Problem Name: 10082
       Platform: WERTYU
     Algorithom: Ad Hoc
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
#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))
using namespace std;

int main()
{
    char c;
    while ( scanf("%c",&c)==1)
    {
        if (c=='1')
            printf("`");
        if (c=='2')
            printf("1");
        if (c=='3')
            printf("2");
        if (c=='4')
            printf("3");
        if (c=='5')
            printf("4");
        if (c=='6')
            printf("5");
        if (c=='7')
            printf("6");
        if (c=='8')
            printf("7");
        if (c=='9')
            printf("8");
        if (c=='0')
            printf("9");
        if (c=='-')
            printf("0");
        if (c=='=')
            printf("-");
        if (c=='W')
            printf("Q");
        if (c=='E')
            printf("W");
        if (c=='R')
            printf("E");
        if (c=='T')
            printf("R");
        if (c=='Y')
            printf("T");
        if (c=='U')
            printf("Y");
        if (c=='I')
            printf("U");
        if (c=='O')
            printf("I");
        if (c=='P')
            printf("O");
        if (c=='[')
            printf("P");
        if (c==']')
            printf("[");
        if (c=='\\')
            printf("]");
        if (c=='S')
            printf("A");
        if (c=='D')
            printf("S");
        if (c=='F')
            printf("D");
        if (c=='G')
            printf("F");
        if (c=='H')
            printf("G");
        if (c=='J')
            printf("H");
        if (c=='K')
            printf("J");
        if (c=='L')
            printf("K");
        if (c==';')
            printf("L");
        if (c=='\'')
            printf(";");
        if (c=='X')
            printf("Z");
        if (c=='C')
            printf("X");
        if (c=='V')
            printf("C");
        if (c=='B')
            printf("V");
        if (c=='N')
            printf("B");
        if (c=='M')
            printf("N");
        if (c==',')
            printf("M");
        if (c=='.')
            printf(",");
        if (c=='\n')
            printf("\n");
        if (c=='/')
            printf(".");
        if (c==' ')
            printf(" ");

    }
    return 0;
}


