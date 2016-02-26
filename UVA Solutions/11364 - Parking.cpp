#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    int test,n,i,j,ans;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        int x[n];
        for(j=0;j<n;j++)
        {
              scanf("%d",&x[j]);
        }
        ans=(*max_element(x,x+n)-*min_element(x,x+n))*2;
        cout<<ans<<endl;
    }
    return 0;
}

