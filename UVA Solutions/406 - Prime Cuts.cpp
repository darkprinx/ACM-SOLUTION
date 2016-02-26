#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#define s(n)          scanf("%d",&n)
#define loop(i,a,b)    for(int i=int(a);i<int(b);i++)
#define ll             long long int
#define PS            system("pause");
using namespace std;

vector<bool> prim(1050,false);
vector<int>p;

void siv()
{
    prim[0]=true;
    for(int i=2; i<=1000; i++)
    {
        if(!prim[i])
        {
            for(int j=i; i*j<=1000; j++)
                prim[i*j]=true;
        }
    }
    for(int i=0; i<1000; i++)
        if(!prim[i])
            p.push_back(i);
}

int main()
{
    siv();
    int num,c;
    while(s(num)==1&&s(c)==1)
    {
        int Total=0,C=c;
        for(int i=0; p[i]<=num; i++)
        {
            Total=Total+1;
        }
        if(Total>169)
            Total=169;

        if(Total%2==0)
            c=c*2;
        else
            c=c*2-1;


        if(c<Total)
        {
            Total=(Total-c)/2;
            printf("%d %d:",num,C);
            for(int i=Total; i<c+Total; i++)
            {
                if(p[i]<=0||p[i]>num)
                break;
                cout<<' '<<p[i];
            }
            cout<<endl<<endl;
        }
        else
            {
                Total=0;
                printf("%d %d:",num,C);
            for(int i=Total; p[i]<=num; i++)
            {
                if(p[i]<=0)
                    break;
                cout<<' '<<p[i];
            }
            cout<<endl<<endl;
            }

    }
    return 0;
}




