#include <cstdio>
int main()
{
    int t;
    long long int n,c,rev,r,d;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%lld",&n);
        d=n;
        c=0;
        while (true)
        {
            rev=0;
            while (d>0)
            {
                r=d%10;
                rev=rev*10+r;
                d=d/10;
            }
            if (n==rev)
                break;
            else
            {
                d=rev+n;
                n=rev+n;
                c++;
            }
        }
        printf("%lld %lld\n",c,n);
    }
    return 0;
}

