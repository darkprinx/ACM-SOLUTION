#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int num,elem[20];
    int flag;
    int T,k;
    scanf("%d",&T);
    for(int p=0;p<T;p++)
    {
    flag=0;
    scanf("%d",&num);
    k=0;
    while(num!=0)
    {
      elem[k]=num%10;
      num=num/10;
      k++;
    }
    for(int i=0,j=k-1;i<k/2;i++,j--)
    {
        if(elem[i]!=elem[j])
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("Case %d: Yes\n",p+1);
    else
        printf("Case %d: No\n",p+1);
    }
return 0;
}
