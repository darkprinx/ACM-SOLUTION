#include<iostream>
using namespace std;
int main()
{
    int i,n,a,b,sum;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        sum=(a/3)*(b/3);
        cout<<sum<<endl;
    }
    return 0;
}
