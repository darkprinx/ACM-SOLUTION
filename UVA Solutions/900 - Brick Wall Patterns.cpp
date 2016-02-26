#include<iostream>
#include<cstdio>

#define s(n) scanf("%d",&n)
#define sl(n,m) scanf("%d%d",&n,&m)
#define pf printf

using namespace std;
int test[50] = { };

int patt(int num)
{
    if(test[num]==0)
    {
        if(num==1)
            return num;
        if(num == 2)
            return num;
        else
        {
            test[num] = patt(num-1) + patt(num-2);
            return test[num];
        }
    }

}

int main()
{
    int num;
    while(s(num)==1 && num!=0)
    {
        pf("%d\n",patt(num));

    }


    return 0;
}
