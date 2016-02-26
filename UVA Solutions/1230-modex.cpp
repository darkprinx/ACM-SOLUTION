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
//#define MOD    1000000007
#define ll    long long int
using namespace std;
ll MOD;
ll lab(ll num,ll po)
{
    ll c;
    if(po==0)
        return 1;
    if(po%2==0)
    {
        c=lab(num,po/2);
        return ((c%MOD)*(c%MOD))%MOD;
    }
    else
        return((num%MOD)*(lab(num,po-1)%MOD))%MOD;
}

int main()
{
    ll num,po,ans;
    int n;
    while(cin>>n&&n!=0)
    {
        while(n--)
        {
            cin>>num>>po>>MOD;
            ans=lab(num,po);
            cout<<ans<<endl;
        }

    }
    return 0;
}
