#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    string x;
    char n;
    while(cin>>x)
    {
        n=getchar();
        int len=x.length();
        for(int i=len-1;i>=0;i--)
        {
            cout<<x[i];
        }
        putchar(n);
    }
    return 0;
}
