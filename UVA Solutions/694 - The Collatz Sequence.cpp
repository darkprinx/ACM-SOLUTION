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
#include <cstdlib>
#include <sstream>
#include <fstream>
#define s(n)          scanf("%d",&n)
#define loop(i,a,b)    for(int i=int(a);i<int(b);i++)
#define ll             long long int
using namespace std;
int main()
{
   ll n,e,c,a;
   int no=0;
   while(scanf("%lld %lld",&n,&e)==2)
   {
       if(n<0&&e<0)
       break;
       c=0;
       a=n;
       while(n<=e)
       {
           if(n==1)
           {
               c++;
               break;
           }
           else if(n%2==0)
           {
               c++;
               n/=2;
           }
           else if(n%2==1)
           {
               c++;
               n=n*3+1;
           }

       }
       printf("Case %d: A = %lld, limit = %lld, number of terms = %lld\n",
          ++no,a,e,c);
   }
    return 0;
}
