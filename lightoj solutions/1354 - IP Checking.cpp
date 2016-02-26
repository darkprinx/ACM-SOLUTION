//#include<iostream>
//#include<cstdlib>
#include<cstdio>
//using namespace std;

int b_num(int bn)
{
    int dc=0,x,i=1;
    while(bn>0)
    {
        x=bn%10;
        dc=dc+(i*x);
        i=i*2;
        bn=bn/10;
    }
    return dc;
}

int main()
{
    int T=0,a[5],b,c=1,ip[5],flag;
    scanf("%d",&T);

    while(T--)
    {
        flag=0;
        scanf("%d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3]);
        scanf("%d.%d.%d.%d",&ip[0],&ip[1],&ip[2],&ip[3]);
        for(b=0;b<4;b++)
        {
            if(b_num(ip[b])!=a[b])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("Case %d: Yes\n",c);
        else
            printf("Case %d: No\n",c);
     c++;
    }
    getchar();
}
