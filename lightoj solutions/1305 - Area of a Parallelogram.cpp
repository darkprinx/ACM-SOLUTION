
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
using namespace std;

struct pt
{
    int x,y;
};

int main()
{
    pt A,B,C,D;
    int test,area;
    s(test);
    for(int i=1;i<=test;i++)
    {
        cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
            D.x=(A.x+C.x)-B.x;
            D.y=(A.y+C.y)-B.y;
    area=((A.x*B.y)+(B.x*C.y)+(C.x*D.y)+(D.x*A.y))-((A.y*B.x)+(B.y*C.x)+(C.y*D.x)+(D.y*A.x));
    area*=0.5;
            printf("Case %d: %d %d %d\n",i,D.x,D.y,abs(area));
    }

return 0;
}
