#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
    char a[100];
    int i,len=0;
    while(cin>>a)
    {
        len=strlen(a);
        for(i=0; i<len; i++)
        {
            a[i]=a[i]-7;
            cout<<a[i];
        }
        cout<<endl;

    }

    return 0;
}
