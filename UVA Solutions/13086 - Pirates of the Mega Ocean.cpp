#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define sf scanf
#define pf printf
#define ll long long
#define pll  pair<ll,ll>
#define M  100000
#define MOD 1000007
#define F first
#define S second



ll ara[M+6];
pll mara[M+6];
bool vis[M+5];
int main()
{
    ll  n,m,p,q,r,x,y,z;
    int test;

    sf("%d",&test);
    for(int k=0; k<test; k++)
    {
     ll sum=0,px;
        int pos;


        sf("%lld %lld",&n,&m);

        sf("%lld",&p);
        sf("%lld",&q);
        sf("%lld",&r);
        sf("%lld",&x);
        sf("%lld",&y);
        sf("%lld",&z);

        for(ll i=1; i<=n; i++)
        {
            ara[i]=(((p*i*i)+(q*i)+r))%MOD;
            sum+=ara[i];
            mara[i-1]=pll(ara[i],i);
        }

        sort(mara,mara+n);

        memset(vis,false,sizeof(vis));

        for(ll i=1; i<=m; i++)
            vis[(((x*i*i)+(y*i)+z)%n)+1]=true;



        for(int i=0; i<n; i++)
            if(!vis[mara[i].S])
            {
                sum=(sum-mara[i].F)*mara[i].F;
                break;
            }


        pf("Case %d: %lld\n",k+1,sum);

    }

    return 0;
}


