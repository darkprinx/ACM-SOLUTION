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

int main()
{
vector<int> stu;
int sum,test,n,cnt,grade;
float avg,ans;
s(test);
while(test--)
{
    s(n);
    sum=0;
    cnt=0;
    for(int i=0;i<n;i++)
    {
        s(grade);
        sum=sum+grade;
        stu.push_back(grade);
    }
    avg=sum/n;
    for(int i=0;i<n;i++)
    {
        if(stu[i]>avg)
            cnt++;
    }
    printf("%.3f%%\n",(100*cnt)/(n*1.00));
    stu.clear();
}
return 0;
}
