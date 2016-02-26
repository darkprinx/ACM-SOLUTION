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

using namespace std;

ll hakmem(ll value){

  // find the lowest one bit in the input
  int lowestBit = value & -value;

  // determine the leftmost bits of the output
  int leftBits = value + lowestBit;

  // determine the difference between the input and leftmost output bits
  int changedBits = value ^ leftBits;

  // determine the rightmost bits of the output
  int rightBits = (changedBits / lowestBit) >> 2;

  // return the complete output
  return (leftBits | rightBits);
}

int main()
{
ll n;
int test;
s(test);
for(int i=1;i<=test;i++)
{
    s(n);
    printf("Case %d: %lld\n",i,hakmem(n));
}
    return 0;
}



