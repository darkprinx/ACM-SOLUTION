#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
    double n,p;
    while(cin>>p>>n)
    {
      printf("%.f\n",round(pow(n,(1/p))));
    }
     return 0;
}


