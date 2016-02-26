#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

bool check(char *ara)
{
    int len=strlen(ara),K,M;
    char line[1100]={};
    for(K=len-1,M=0;K>=0;K--,M++)
        line[M]=ara[K];
    if(strcmp(ara,line)==0)
        return true;
    return false;
}

int main()
{
    string s;
    int i,j;
    while(getline(cin,s)&&s!="DONE")
    {
        char ara[1100]= {};
        i=0,j=0;
        while(s[i]!='\0')
        {
            if(s[i]>='A'&&s[i]<='Z')
                s[i]=s[i]+32;
            if(s[i]>='a'&&s[i]<='z')
            {
                ara[j]=s[i];
                j++;
            }
            i++;
        }
        if(check(ara))
            cout<<"You won't be eaten!"<<endl;
        else
            cout<<"Uh oh.."<<endl;
    }
    return 0;
}
