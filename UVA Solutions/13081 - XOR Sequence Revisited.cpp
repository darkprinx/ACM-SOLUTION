#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define sf scanf
#define pf printf
#define ll  long long

int main()
{
    ll  test, n, l,r, temp;

    sf("%lld", &test);
    for(int i=0; i<test; i++)
    {
        sf("%lld %lld",&l,&r);

        if(l==r)
        {
            ll rem=l%4;
            if(rem==0)
            pf("%lld\n",l+1);
            else if(rem==1)
            pf("0\n");
            else if(rem==2)
            pf("%lld\n",l);
            else if(rem==3)
            pf("1\n");
        }
        else if(abs(l-r)==1&&l%4==3&&r%4==0)
        pf("1\n");
        else
        pf("0\n");



    }

    return 0;
}
