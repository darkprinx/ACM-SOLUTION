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
#include <cstring>
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
#define ll long long int
#define MAX 1001
#define len 2601

using namespace std;


int ara[MAX][len];

void calc()
{
    ara[0][0]=ara[1][0]=1;
    for(int i=2; i<MAX; i++)
    {
        for(int j=0; j<len; j++)
        {
            ara[i][j]+=ara[i-1][j]*i;
            if(ara[i][j]>9)
            {
                ara[i][j+1]+=ara[i][j]/10;
                ara[i][j]%=10;
            }
        }
    }
}

int main()
{
    int num,i;
    calc();
    while(cin>>num)
    {
        pf("%d!\n",num);
        for(i=len-1; i>0; i--)
        {
            if(ara[num][i]!=0)
                break;
        }
        for(; i>=0; i--)
            pf("%d",ara[num][i]);
       pf("\n");
    }


}


