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
#include <cstring>
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
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
#define on(x,w)  x=x|(1<<w)
#define check(x,w) (x&(1<<w))==(1<<w)?true:false
#define all(x) (x).begin(),(x).end()
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pf printf
#define ll long long int
#define MOD 1000000007
#define sqr(x) (( (x)* (x))%MOD)
#define cube(x)   ( (sqr(x)*(x))%MOD)
#define bit_cnt(x)   __builtint_popcount(x)
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))
#define MAX 1010

using namespace std;

int par[30];
void set_al()
{
    int i;
    loop(i,1,30)
    {
        par[i]=i;
    }
}
int FIND(int n)
{
    if(par[n]==n)
        return n;
    else
    {
        par[n]=FIND(par[n]);
        return par[n];
    }
}
void UN(int a,int b)
{
    int u,v;
    u=FIND(a);
    v=FIND(b);
    if(u!=v)
        par[u]=v;
}
int main()
{
    set<int>SET;
    int test,i,k,num,l;
    string X;
    s(test);
    getchar();
    getchar();
    loop(i,0,test)
    {
        set_al();
        while(getline(cin,X)&&!X.empty())
        {
            if(X.length()==1)
                l=X[0]-64;
            else
            {
                int a,b;
                a=X[0]-64;
                b=X[1]-64;
                UN(a,b);
            }
        }
        loop(k,1,l+1)
        {
            int Y=FIND(par[k]);
            SET.insert(Y);
        }
        cout<<SET.size()<<"\n";
        SET.clear();
        if(i+1<test)
            pf("\n");

    }

    return 0;
}



