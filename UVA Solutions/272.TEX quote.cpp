#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    char a[1000];
    int i,n=0;
    while(gets(a))
    {
        for(i=0; a[i]!='\0'; i++)
        {
            if(a[i]=='"')
            {
                n++;
                if(n%2==1)
                    printf("``");
                else
                    printf("''");
            }
            else
            {
                printf("%c",a[i]);
            }

        }
        printf("\n");

    }

    return 0;
}











