
/* Problem Name: 10106
       Platform: UVA
     Algorithom: BIT INTEGER MULTIPLICATION
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
using namespace std;


string mult(string a, string b)
{
    int len= a.length() + b.length();
    string result(len, '0'),ret;
    int num;
    int i, j;
    int last_pos_i, last_pos_j, last_pos_k;
    last_pos_i= len - 1;
    for (i= b.length() - 1; i >= 0; i --)
    {
        last_pos_j= last_pos_i;
        for (j= a.length() - 1; j >=0; j --)
        {
            last_pos_k= last_pos_j;
            num= INT(a[j]) * INT(b[i]);
            while (num)
            {
                num += INT(result[last_pos_k]);
                result[last_pos_k]= CHAR(num % 10);
                num= num / 10;
                last_pos_k --;
            }
            last_pos_j --;
        }
        last_pos_i --;
    }
    int r_len=result.length();
    bool flag=false;

    if(result[0]==48)
        result.erase(0,1);

    if(result[0]==48)
        return "0";
    return result;
}

int main()
{
string a,b;
while(cin>>a>>b)
{
    cout<<mult(a,b)<<endl;
}
return 0;
}



