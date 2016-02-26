
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
#define ll    long long int
using namespace std;
ll ara[21]= {0};
int k,m=20;

set <int> S;
set <int>::iterator it;

ll fc(int n)
{
    if(n==0)
        return 1;
    if(ara[n]!=0)
        return ara[n];
    else
    {
        ara[n]=n*fc(n-1);
        return ara[n];
    }
}
void chk(ll n)
{
    for(int i=0; i<m; i++)
    {
        if(ara[i]>n)
            break;
        k=i;
    }

}
int main()
{
    ll n;
    int j,test;
    fc(20);
    s(test);
    for(int j=1; j<=test; j++)
    {
        cin>>n;
        ara[0]=1;
        int flag=1;
        while(true)
        {
            chk(n);
            n=n-ara[k];
            if(n<0)
                break;
        if(n==2)
       {
           S.insert(1);
           S.insert(0);
           n=n-2;
       }

            if(n>=ara[k])
            {
                flag=0;
                break;
            }
            else
            {
                S.insert(k);
                k--;
            }

        }
        if(!flag)
        {
            printf("Case %d: impossible\n",j);
        }
        else
        {

            printf("Case %d: ",j);
            int p=1;
            for(it=S.begin(); it!=S.end(); it++,p++)
            {
                printf("%d!",*it);
                if(p<S.size())
                    cout<<'+';
            }
            cout<<endl;
        }
        S.clear();
    }

    return 0;
}
