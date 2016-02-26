#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int a[3000],d[3000],i,j,n,f,m;
int X(int n)
{
    f=0;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    if(n==1)
        return 1;
    else if(n==2&&abs(a[0]-a[1])==1)
    {
        return 2;
    }
    else
    {
        for(i=0,j=1; i<n-1,j<n; i++,j++)
        {
            d[i]=abs(a[i]-a[j]);
        }

        for(i=0; i<n-1; i++)
        {
            for(j=i+1; j<n-1; j++)
            {
                if(d[i]<n&&d[i+1]<n)
                {
                    if(d[i]==d[j])
                    {
                        f=1;
                        break;
                    }
                }
                else
                {
                    f=1;
                    break;
                }
            }
        }
        if(f==0)
            return 3;
        else
            return 0;
    }
}
int main()
{
    while(cin>>n)
    {

        m=X(n);
        if(m==0)
            cout<<"Not jolly"<<endl;
        else
            cout<<"Jolly"<<endl;
    }
    return 0;
}
