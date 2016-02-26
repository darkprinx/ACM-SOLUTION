#include<algorithm>
#include<cstdio>
#include<iostream>

using namespace std;

int calc(string name1)
{
    int ans=0,I;
    for(I=0;name1[I]!='\0';I++)
    {
        if(name1[I]>='a'&&name1[I]<='z')
            name1[I]-=96;
        else if(name1[I]>='A'&&name1[I]<='Z')
            name1[I]-=64;
        else
            name1[I]=0;
        ans=ans+name1[I];
    }
    return ans;
}

int down(int num)
{
    int rem,ans=0,final;
    while(num!=0)
    {
        rem=num%10;
        ans+=rem;
        num=num/10;
    }
    final=ans;
    if(final>9)
    final=down(final);
    else
    return final;
}

int main()
{
    string name1,name2;
    int I,K,M;
    float ANS,ans1,ans2;
    while(getline(cin,name1)&&getline(cin,name2))
    {
        ans1=calc(name1);
        ans2=calc(name2);

        ans1=down(ans1);
        ans2=down(ans2);

        if(ans1>ans2)
        swap(ans1,ans2);
        ANS=(ans1/ans2)*100;
        printf("%.2f %%\n",ANS);
    }
    return 0;
}
