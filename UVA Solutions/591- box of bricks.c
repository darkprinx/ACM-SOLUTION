#include<iostream>
//#include<fstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int main()
{
    int n,h[50],i,temp,tem2,m=1,x;
    while(scanf("%d",&n)==1&&n!=0)
    {
        tem2=0;
        temp=0;
        if(n<1||n>50)
            break;
         for(i=0;i<n;i++)
         {
             cin>>h[i];
             if(h[i]<1||h[i]>100)
             break;
             temp+=h[i];
         }
         x=temp;
         temp/=n;
         for(i=0;i<n;i++)
         {
             if(h[i]<temp)
             {
                 tem2+=temp-h[i];
             }

         }
         if(x>temp*n)
         {
             x=x-(temp*n);
             tem2+=x;
         }
            cout<<"Set #"<<m<<endl<<"The minimum number of moves is "<<tem2<<'.'<<"\n\n";
         m++;

    }
return 0;
}

