#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    char a[100];
    int len,i,*x;
    while(gets(a))
    {
        int n=0;
        len=strlen(a);
        for(i=0; i<len+1; i++)
        {
            if((a[i+1]>=32&&a[i+1]<=64||a[i+1]>=91&&a[i+1]<=96||a[i+1]>=123&&a[i+1]<=126||a[i+1]=='\0')&&((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z')))
            {
                n++;
            }
        }
        cout<<n<<endl;
    }
    return 0;
}
