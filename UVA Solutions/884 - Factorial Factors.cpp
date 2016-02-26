#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#define s(n)          scanf("%d",&n)
#define loop(i,a,b)    for(int i=int(a);i<int(b);i++)
#define ll             long long int
#define MAX             1000000
using namespace std;

vector<bool> prime(MAX+3,false);
vector<int> p;
vector<int> fact(MAX+3,0);

void siv()
{
    prime[0]=prime[1]=true;
    for(int i=2;i<=sqrt(MAX);i++)
    {
        if(!prime[i])
        {
            for(int j=2;i*j<=sqrt(MAX);j++)
                prime[i*j]=true;
        }
    }
  for(int i=2;i<1010;i++)
  {
      if(!prime[i])
        p.push_back(i);
  }
}

int p_f(int n)
{
    int cnt=0;
    for(int i=0;p[i]<=sqrt(n);i++)
    {
        if(n%p[i]==0)
        {
            while(n%p[i]==0)
              {
                  n/=p[i];
                  cnt++;
              }
        }

    }
    if(n>1)
        cnt++;
    return cnt;
}

int main()
{
    int num;
    int sum;
    siv();
    for(int i=2;i<=MAX;i++)
    {
        fact[i]=fact[i-1]+p_f(i);
    }
    while(s(num)==1)
    {
        cout<<fact[num]<<endl;
    }

return 0;
}




