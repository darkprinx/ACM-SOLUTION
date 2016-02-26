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
#include <cctype>
#define s(n)          scanf("%d",&n)
#define loop(i,a,b)    for(int i=int(a);i<int(b);i++)
#define ll             long long int
using namespace std;

string word(string s)
{
   int len=s.length();
   string line;
   for(int i=0;i<len;i++)
   {
       if(isalpha(s[i]))
       {
           if(isupper(s[i]))
        s[i]=tolower(s[i]);
        line.push_back(s[i]);
       }
   }
   sort(line.begin(),line.end());
   return line;
}

int main()
{
int test,i;
scanf("%d\n",&test);    // HERE U MAY FINE A PROBLEM IF U DONT TAKE A NEW LINE OR
string W1,W2;             //GETCHAR() AND TRY TO AVOID FFLUS(STDIN)
loop(i,1,test+1)
{
    getline(cin,W1);
    getline(cin,W2);
    if(word(W1)==word(W2))
        printf("Case %d: Yes\n",i);
    else
        printf("Case %d: No\n",i);
    W1.clear();
    W2.clear();
}

return 0;
}
