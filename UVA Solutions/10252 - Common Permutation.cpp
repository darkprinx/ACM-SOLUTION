
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
using namespace std;


int main()
{
int i;
string x,y;
while(getline(cin,x)&&getline(cin,y))
{
string w;
bool mark[1003]={0};
for(i=0;i<x.length();i++)
{
    for(int j=0;j<y.length();j++)
    {
        if(x[i]==y[j]&&mark[j]==0)
            {
                w.push_back(x[i]);
                mark[j]=-1;
                break;
            }
    }
}
sort(w.begin(),w.end());
cout<<w<<endl;
}
return 0;
}

