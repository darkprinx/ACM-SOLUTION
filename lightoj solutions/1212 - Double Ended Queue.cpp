/* Problem Name: 1212-Double Ended Queue
       Platform: lightOj
     Algorithom: Data Structure (list)/Simulation
   Coder's Name: R C Tushar
*/

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
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include<assert.h>


#define pi 2*acos(0.0)
#define PS system("pause")
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define Sfor(n) for(int i=1;i<=n;i++)
#define inf (1<<30)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)x.size())
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
#define lcm(a,b) (a*(b/gcd(a,b)))
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
#define bit_cnt(x)   __builtin_popcount(x)
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define btz(a)   __builtin_ctz(a)
#define Mems(p,n) memset(p, n, sizeof(p))
#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))
#define M  20002
using namespace std;

typedef vector<int> vi;

int main()
{

int test,n,a,m,j;
string line;

s(test);
Sfor(test)
{
    pf("Case %d:\n",i);
    s(n);
    s(m);
    list<int> q;
    for(int j=0;j<m;j++)
    {
        cin>>line;
        if(line=="pushLeft")
        {
            s(a);
            if(q.size()==n)
                pf("The queue is full\n");
            else
                {
                    q.push_front(a);
                    pf("Pushed in left: %d\n",a);
                }
        }
        else if(line=="pushRight")
        {
            s(a);
            if(q.size()==n)
                pf("The queue is full\n");
            else
                {
                    q.pb(a);
                    pf("Pushed in right: %d\n",a);
                }
        }
        else if(line=="popLeft")
        {
            if(q.size()==0)
                pf("The queue is empty\n");
            else
                {
                    int z=q.front();
                    q.pop_front();
                    pf("Popped from left: %d\n",z);
                }

        }
        else if(line=="popRight")
        {
            if(q.size()==0)
                pf("The queue is empty\n");
            else
                {
                    int z=q.back();
                    q.pop_back();
                    pf("Popped from right: %d\n",z);
                }
        }
    }
}

return 0;
}



