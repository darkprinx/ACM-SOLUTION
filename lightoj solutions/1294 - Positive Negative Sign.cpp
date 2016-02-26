#include<iostream>
#include<cstdio>
#define  s(n)  scanf("%d",&n);
using namespace std;

int main()
{
    int test;
    long long int a,b;
    s(test);
    for(int i=1;i<=test;i++)
    {
        cin>>a>>b;
        cout<<"Case "<<i<<": "<<a/2*b<<endl;
    }
    return 0;
}
