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
#include <sstream>
#include <fstream>
#define s(n)          scanf("%d",&n)
#define loop(i,a,b)    for(int i=int(a);i<int(b);i++)
using namespace std;
int main()
{
long long int test,a,b,c,d;
cin>>test;
while(test--)
{
    cin>>a>>b>>c>>d;
    if(a==b&&b==c&&c==d)
        printf("square\n");
    else if((a==b&&c==d)||(a==c&&b==d)||(a==d&&c==b))
        printf("rectangle\n");
    else if((a<=b+c+d)&&(b<=a+c+d)&&(c<=a+b+d)&&(d<=a+b+c))
        printf("quadrangle\n");
    else
        printf("banana\n");
}
return 0;
}

