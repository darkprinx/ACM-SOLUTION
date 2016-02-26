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
int test,I,K,num;
bool flag;
s(test);
cout<<"Lumberjacks:"<<endl;
loop(I,0,test)
{
    flag=false;
   int ara[10]={0};
    loop(K,0,10)
        {
            cin>>ara[K];
        }

    if(ara[0]>ara[1])
        {
            for(int j=0,K=j+1;j<9;j++,K++)
            {
                if(ara[j]<ara[K])
                    {
                        flag=true;
                        break;
                    }
            }
        }
    else
        {
            for(int j=0,K=j+1;j<9;j++,K++)
            {
                if(ara[j]>ara[K])
                    {
                        flag=true;
                        break;
                    }
            }
        }
    if(!flag)
    printf("Ordered\n");
    else
    printf("Unordered\n");
}
return 0;
}
