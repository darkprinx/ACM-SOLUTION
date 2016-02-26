#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    string a;
    int i=1;
    while(true)
    {
        cin>>a;
        if(a=="Hajj")
            printf("Case %d: Hajj-e-Akbar\n",i);
        else if(a=="Umrah")
            printf("Case %d: Hajj-e-Asghar\n",i);
        else if(a=="*")
            break;
            i++;
    }
    return 0;
}
