#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef vector<int> vi;
typedef vector<float> vf;
typedef list<int> li;
typedef list<float> lf;

#define s(n)          scanf("%d",&n)
#define sl(n)         scanf("%lld",&n)
#define sf(n)         scanf("%lf",&n)
#define pb            push_back
#define mp            make_pair
#define MOD           1000000007
#define INF           (int)1e9
#define EPS           1e-9
#define loop(i,a,b)    for(int i=int(a);i<int(b);i++)
#define TRli(a,it)      for(li::iterator it = (a).begin(); it!=(a).end(); ++it)
#define TRvi(a,it)      for(vi::iterator it = (a).begin(); it!=(a).end(); ++it)

int comp(int a,int b,int c)
{
    if(a<=b && a<=c)
        return a;
    else if(b<=a && b<=c)
        return b;
    return c;
}

int main()
{
    int n;
    int i,f,g,dev1=2,dev2=3,dev3=5;
    int ara[1550],num;
    i=f=g=0;
    for(int l=1;l<1500;l++)
    {
        num=comp(dev1,dev2,dev3);
        ara[l]=num;
        if(num==dev1)
        {
            i++;
            dev1=ara[i]*2;
        }
        if(num==dev2)
        {
            f++;
            dev2=ara[f]*3;
        }
        if(num==dev3)
        {
            g++;
            dev3=ara[g]*5;
        }
    }
    printf("The 1500'th ugly number is %d.\n",num);

    return 0;
}

