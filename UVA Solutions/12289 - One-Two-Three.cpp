#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char a[6],x;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(strlen(a)==5)
            cout<<"3"<<endl;
        else if((a[0]=='o'&&a[1]=='n')||(a[0]=='o'&&a[2]=='e')||(a[1]=='n'&&a[2]=='e'))
            cout<<"1"<<endl;
        else
            cout<<"2"<<endl;
    }
    return 0;
}
