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
    string word;
    while(getline(cin,word))
    {
        if(word[0]=='*')
            return 0;
        bool flag=true;
        int len=word.length();
        for(int i=0;i<len;i++)
        {
            if(isupper(word[i]))
                word[i]=tolower(word[i]);
        }
        for(int i=0;i<len;i++)
        {
            if(word[i]==' '&&word[0]!=word[i+1])
            {
               // cout<<word[0]<<' '<<word[i+1]<<endl;
                flag=false;
                break;
            }
        }
        if(flag)
            printf("Y\n");
        else
            printf("N\n");
    }

}




