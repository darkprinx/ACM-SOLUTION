#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
    long long int n,f,x,s,a,ef,i,mult,sum,j;
    while(cin>>n)
    {
        for(i=0; i<n; i++)
        {
            sum=0;
            cin>>f;
            for(j=0; j<f; j++)
            {
                cin>>s>>a>>ef;
                mult=s*ef;
                sum=mult+sum;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
