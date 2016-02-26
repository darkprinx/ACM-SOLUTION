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


string add(string a,string b)
{
    string num,str;
    int len1=a.length(),len2=b.length();
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
            num.push_back(temp+48);
            if(i==0)
                num.push_back(49);
            else
               a[i-1]+=1;
        }
        else
        num.push_back(n1+n2+48);
    }
    for(int i=num.length()-1;i>=0;i--)
    {
        str.push_back(num[i]);
    }
    return str;

}

int main()
{
string x,ans="0";
while(cin>>x&&x!="0")
{
    ans=add(x,ans);
}
cout<<ans<<endl;


return 0;
}



