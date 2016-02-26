#include<iostream>
using namespace std;

int main()
{
    unsigned long a,b,c,num1,num2;
    while(cin>>num1>>num2)
    {
        if(num1==0&&num2==0)
            break;
        c=0;
        int cnt=0;
        while(num1||num2)
        {
            c=(num1%10+num2%10+c)/10;
            num1=num1/10;
            num2=num2/10;
            cnt=cnt+c;
        }
        if(cnt==0)
            cout<<"No carry operation.\n";
        if(cnt==1)
            cout<<"1 carry operation.\n";
        if(cnt>1)
            cout<<cnt<<" carry operations.\n";
    }
    return 0;
}
