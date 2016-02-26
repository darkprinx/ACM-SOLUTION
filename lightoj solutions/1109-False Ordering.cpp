#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<assert.h>


#define PS system("pause")
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define inf 1<<30
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)x.size())
#define sqr(x) ( (x)* (x) )
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
#define on(x,w)  x=x|(1<<w)
#define check(x,w) (x&(1<<w))==(1<<w)?true:false
#define all(x) (x).begin(),(x).end()
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pf printf

using namespace std;

struct PR
{
    int n,d;
} all[1001];

bool chk(PR a,PR b)
{
    if(a.d<b.d)
        return true;
    else if(a.d==b.d&&a.n>b.n)
        return true;
    return false;
}
void div_cnt()
{
    for(int k=2; k<=1000; k++)
    {
            all[k].n=k;
            int sum=0;
            for(int i=1; i<sqrt(k); i++)
            {
                if(k%i==0)
                    sum+=2;
                if((i+1)*(i+1)==k)
                    sum++;
            }
            all[k].d=sum;

    }
}

int main()
{

    int num,test;
    div_cnt();
    sort(all,all+1001,chk);
    s(num);
    for(int i=1;i<=num;i++)
    {
        s(test);
        if(test==1)
            pf("Case %d: 1\n",i);
        else
            pf("Case %d: %d\n",i,all[test].n);
    }

    return 0;
}




