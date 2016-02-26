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
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    int test;
    long double num;
    cin>>test;
    for(int K=0;K<test;K++)
    {
       scanf("%Lf",&num);
       printf("%.0Lf\n",sqrtl(num));
    }
    return 0;
}
