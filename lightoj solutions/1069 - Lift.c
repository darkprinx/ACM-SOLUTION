#include<stdio.h>
int main()
{
    int n[25],m[25],x,i,j,ans;
    scanf("%d",&x);
    for(i=0,j=1;i<x;i++,j++)
    {
        scanf("%d%d",&m[i],&n[i]);
        if(m[i]<n[i])
        {
            ans=n[i]*4+19;
            printf("Case %d: %d\n",j,ans);
        }
        else if(m[i]==n[i])
        {
            ans=n[i]*4+19;
            printf("Case %d: %d\n",j,ans);
        }
        else
        {
            ans=(m[i]-n[i])*4+m[i]*4+19;
            printf("Case %d: %d\n",j,ans);
        }
    }
    return 0;
}
