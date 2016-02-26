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
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;
int main()
{
    long long int sum;
    char a[210];
    int t,b;
    cin>>t;
    for(int I=1; I<=t; I++)
    {
        sum=0;
        cin>>a>>b;
        if(b<0)
            b=-b;
        int len=strlen(a);
        for(int K=0; K<len; K++)
        {
            if(a[K]=='-')
                continue;
            sum=sum*10;
            sum=sum+(a[K]-48);
            if(sum<b)
                continue;
            else
                sum=sum%b;
        }
        if(sum==0)
        printf("Case %d: divisible\n",I);
      else
        printf("Case %d: not divisible\n",I);
    }
    return 0;
}


