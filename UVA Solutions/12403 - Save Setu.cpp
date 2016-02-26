#include<cstdio>
#include<iostream>
using namespace std;
int conv(string f)
{
    int s,n,a=0;
    s=f.length();
    for(int i=0; i<s; i++)
    {
        a=a*10+(f[i]-48);
    }

    return a;
}
int main()
{
    int t,i,sum=0;
    string str, x;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        string x[t];
        fflush(stdin);
        getline(cin,str);
        if(str=="report")
                printf("%d\n",sum);
        if(str.substr(0,6)=="donate")
        {
            x[i].append(str.begin()+7,str.end());
            sum=sum+conv(x[i]);
        }
    }
    return 0;
}


