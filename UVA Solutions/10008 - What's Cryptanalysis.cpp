
/* Problem Name: 10008- Whats's Cryptanalysis
       Platform: UVA
     Algorithom: Ad hoc
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
#define inf 1<<30
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
#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))
using namespace std;


struct st
{
    char a;
    int b;
    bool operator<(const st& A)const
    {
        if(b!=A.b)
        return b>A.b;
        else
            return a<A.a;
    }
};

int main()
{
    int test;
    st X[27]={};
    s(test);
    string line;
    getchar();
    while(test--)
    {
        getline(cin,line);

        for(int i=0; line[i]!='\0'; i++)
        {
            if(isalpha(line[i]))
            {
                if(islower(line[i]))
                    line[i]=toupper(line[i]);

                    X[line[i]-65].a=line[i];
                    X[line[i]-65].b++;
            }
        }
    }
    sort(X,X+26);
    for(int i=0;i<26;i++)
        if(X[i].b!=0)
        cout<<X[i].a<<' '<<X[i].b<<endl;
    return 0;
}



