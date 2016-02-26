#include<iostream>
using namespace std;

int main()
{
    long long int a,b;
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            if(a>b)
                cout<<">"<<endl;
            else if(a<b)
                cout<<"<"<<endl;
            else
                cout<<"="<<endl;
        }
    }
    return 0;
}
