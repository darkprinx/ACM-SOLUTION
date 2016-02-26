#include <iostream>
#include <vector>
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



int main()
{
    int Tc,m;
    s(Tc);
    for(int d=0;d<Tc;d++)
    {
        s(m);
        if(m==1||m==4||m==78)
            printf("+\n");
        else if((m%100)/10==1||(m%100)/10==4||(m%1000)/10==78)
           printf("*\n");
        else if(m%10==1||m%10==4||m%100==78)
            printf("?\n");
        else if(m/100==1||m/100==4||m/100==78)
           printf("-\n");

    }
return 0;
}

