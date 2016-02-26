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


int fn(int num)
{
    int sum=0,a;
    while(num!=0)
    {
        a=num%10;
        sum=sum+a;
        num=num/10;
    }
    if(sum>0&&sum<10)
        return sum;
    else
      fn(sum);
}

int main()
{
    int num;
    while(cin>>num&&num!=0)
    cout<<fn(num)<<endl;
}
