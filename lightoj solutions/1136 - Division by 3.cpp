#include <iostream>
#include <cstdio>

using namespace std;

int dev(int num)
{
    if(num==1||num==0)
        return 0;
    return(num-1)-(num-1)/3;
}

int main()
{
    int a,b,I,t;
    cin>>t;
    for(I=1;I<t+1;I++)
    {
        cin>>a>>b;
      printf("Case %d: %d\n",I,dev(b)-dev(a-1));
    }
    return 0;
}
