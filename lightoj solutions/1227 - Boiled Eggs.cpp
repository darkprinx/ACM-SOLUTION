#include<cstdio>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;

int main()
{
    int t,p,n,q,cnt,sum;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>p>>q;
        int w[n];
        cnt=-1;
        sum=0;
        for(int j=0;j<n;j++)
        {
         cin>>w[j];
        }
        while(sum<=q&&cnt!=p)
        {
            cnt++;
            if(cnt==n)
                break;
            sum=sum+w[cnt];
        }
        cout<<"Case "<<i+1<<": "<<cnt<<endl;

    }
    return 0;
}

