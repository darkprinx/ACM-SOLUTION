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
#include <sstream>
#include <fstream>
#define s(n)          scanf("%d",&n)
#define loop(i,a,b)    for(int i=int(a);i<int(b);i++)
using namespace std;

int main()
{
    vector<int> num;
    int test,n,SZ;
    while(s(test)&&test!=0)
    {
        for(int i=0;i<test;i++)
        {
            s(n);
            num.push_back(n);
        }
        SZ=num.size();
        sort(num.begin(),num.begin()+SZ);
        for(int i=0;i<test;i++)
        {
            printf("%d",num[i]);
            if(i+1<test)
                printf(" ");
        }
        printf("\n");
      num.clear();
    }

return 0;
}
