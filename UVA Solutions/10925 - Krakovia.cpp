#include<iostream>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cmath>

using namespace std;


string add(string a,string b)
{
    string num,str;
    int len1=a.length(),len2=b.length(),LEN,MEN;
    if(len1<len2)
        {
            swap(a,b);
            swap(len1,len2);
        }
    for(int i=len1-1,j=len2-1;i>=0;i--,j--)
    {
        int temp=0,n1,n2;
        n1=a[i]-48;
        if(j<0)
            n2=0;
        else
        n2=b[j]-48;
        if(n1+n2>9)
        {
            temp=(n1+n2)%10;
            num.push_back(temp+48);
            if(i==0)
                num.push_back(49);
            else
               a[i-1]+=1;
        }
        else
        num.push_back(n1+n2+48);
    }
    for(int i=num.length()-1;i>=0;i--)
    {
        str.push_back(num[i]);
    }
    return str;

}

string div(string a,int b)
{
    int len=a.length(),sum=0,flag=0;
    string num;
        for(int K=0; K<len; K++)
        {
            sum=sum*10;
            sum=sum+(a[K]-48);
            if(sum<b&&flag==1)
              num.push_back(48);
            else if(sum>=b)
                {
                    num.push_back(sum/b+48);
                    sum=sum%b;
                    flag=1;
                }
        }
            if(!flag)
            num.push_back(48);

   return num;
}

int main()
{
string x,y,ans;
int n,m,j=1;
while(cin>>n>>m&&n!=0)
{
    ans="0";
for(int i=0;i<n;i++)
{
    cin>>y;
    ans=add(ans,y);
}
cout<<"Bill #"<<j<<" costs "<<ans<<':'<<" each friend should pay "<<div(ans,m)<<"\n\n";
j++;
}

    return 0;
}
