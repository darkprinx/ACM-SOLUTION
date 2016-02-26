
/* Problem Name: 713 - Adding Reversed Numbers
       Platform: UVA
     Algorithom: AD HOC (BIG INT ADD & REVERSE)
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


string str_rev(string a)
{
    bool flag=false;
    int len=a.length();
    string str;
    for(int i=len-1;i>=0;i--)
    {
        if(a[i]!=48)
        {
            str.push_back(a[i]);
            flag=true;
        }
        else if(a[i]==48&&flag==true)
            str.push_back(a[i]);
    }
    return str;
}
string ADD(string a,string b)
{
    string num,str;
    int len1=a.length();
    int len2=b.length();
    if(len1<len2)
    {
        swap(a,b);
        swap(len1,len2);
    }
    for(int i=len1-1,j=len2-1;i>=0;i--,j--)
    {
        int temp=0,n1,n2;
        n1=a[i]-48;
        if(j<0)
            n2=0;
        else
            n2=b[j]-48;
        if(n1+n2>9)
        {
            temp=(n1+n2)%10;
            num.pb(temp+48);
            if(i==0)
                num.pb(49);
            else
                a[i-1]+=1;
        }
        else
            num.pb(n1+n2+48);
    }
    int nlen=num.length();
    for(int i=nlen-1;i>=0;i--)
        str.pb(num[i]);

    return str;
}
int main()
{
int test,n;
s(test);
loop(i,0,test)
{
    string a,b,ans;
    cin>>a>>b;
    a=str_rev(a);
    b=str_rev(b);
    ans=ADD(a,b);
    ans=str_rev(ans);
    cout<<ans<<endl;
}

return 0;
}



