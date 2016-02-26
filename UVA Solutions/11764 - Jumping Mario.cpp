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
#define s(n)          scanf("%d",&n)
#define loop(i,a,b)    for(int i=int(a);i<int(b);i++)
using namespace std;

int main()
{
    vector<int> ara;
    int Test,n,I,K,h,high,low;
    s(Test);
    loop(I,0,Test)
    {
        high=0;
        low=0;
        s(n);
        loop(K,0,n)
        {
            s(h);
            ara.push_back(h);
        }
        int len=ara.size();
        for(int j=0,K=j+1;j<len-1;j++,K++)
        {
            if(ara[j]<ara[K])
                high++;
            else if(ara[j]>ara[K])
                low++;
            else
                continue;
        }
        printf("Case %d: %d %d\n",I+1,high,low);
        ara.clear();
    }

return 0;
}
