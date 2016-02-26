/* Problem Name: 100 - The 3n + 1 problem
       Platform: uva
     Algorithom: AD HOC
   Coder's Name: R C Tushar
*/

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,y,j,m,l,MAX;
    int j1,x;
    while(cin>>m>>l)
    {
        MAX=0;
        y=m;
        j1=l;
        if(y>j1)
        {
            swap(y,j1);
        }
        for(x=y; x<=j1; x++)
        {
            j=x;
            n=0;
            while(j!=1)
            {
                if(j%2==0)
                {
                    j=j/2;
                    n++;
                }
                else
                {
                    j=j*3+1;
                    n++;
                }
            }
            if(MAX<n)
            {
                MAX=n;
            }
        }
        printf("%d %d %d\n",m,l,MAX+1);
    }
    return 0;
}
