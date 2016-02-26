#include <stdio.h>
int main()
{
    int x1[50],x2[50],x[100],y1[50],y2[50],y[100],n,j,m,i,k;
    scanf("%d",&n);
    for(i=0,k=1;i<n;i++,k++)
    {
        scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
        scanf("%d",&m);
        printf("Case %d:\n",k);
        for(j=0;j<m;j++)
        {
            scanf("%d%d",&x[j],&y[j]);
    if((x1[i]<=x[j]&&x[j]<=x2[i])&&(y1[i]<=y[j]&&y[j]<=y2[i]))

        printf("Yes\n");
    else
        printf("No\n");
        }
    }
    return 0;
}
