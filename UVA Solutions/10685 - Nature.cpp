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

using namespace std;

typedef pair<int,int>pii;
typedef vector<int>vi;

map<string,string> name;
map<string,int> stor;

map<string,string> ::iterator it;

string REP(string a)
{
    if(name[a]==a)
            return a;
    return name[a]=REP(name[a]);
}

void UN(string a,string b)
{
    a=REP(a);
    b=REP(b);
    if(a!=b)
        name[a]=b;
}

int main()
{
    string a,b;
    int i,j,R,C;
    while(s(R)==1&&s(C)==1)
    {
        if(R==0&&C==0)
            break;
        int cnt=0;
        loop(i,0,R)
        {
            cin>>a;
            name[a]=a;
        }
        loop(i,0,C)
        {
            cin>>a>>b;
            UN(a,b);
        }
        for(it=name.begin();it!=name.end();it++)
        {
            a=REP(it->first);
            stor[a]++;
            if(stor[a]>cnt)
                cnt=stor[a];
        }
        cout<<cnt<<endl;
        name.clear();
        stor.clear();
    }

    return 0;
}







