#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,a,b,c;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a>>b>>c;

            if((a<b&&a>c)||(a>b&&a<c))
                printf("Case %d: %d\n",i+1,a);

            else if((b<a&&b>c)||(b>a&&b<c))
                printf("Case %d: %d\n",i+1,b);

            else if((c<a&&c>b)||(c>a&&c<b))
                printf("Case %d: %d\n",i+1,c);
        }
    }
    return 0;
}
