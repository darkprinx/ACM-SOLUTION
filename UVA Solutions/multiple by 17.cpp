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
    string num;
    while( cin>>num&&num!="0")
    {

        int I,K,len,sum=0;

        len=num.length();

        loop(I,0,len)
        {
            sum*=10;
            sum+=(num[I]-48);
            if(sum<17)
                continue;
            else
                sum%=17;
        }
        if(sum==0)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}

