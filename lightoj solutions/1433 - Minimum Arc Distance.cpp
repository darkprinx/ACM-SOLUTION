#include<cstdio>
#include<vector>
#include<cmath>
#include<iostream>
#define PI 3.14159265
using namespace std;

int main()
{
    int Ox,Oy,Ax,Ay,Bx,By,t;
    double OA,AB,theta;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>Ox>>Oy>>Ax>>Ay>>Bx>>By;
        OA=sqrt((Ox-Ax)*(Ox-Ax)+(Oy-Ay)*(Oy-Ay));
        AB=sqrt((Bx-Ax)*(Bx-Ax)+(By-Ay)*(By-Ay));
        theta=acos(((2*OA*OA)-AB*AB)/(2*OA*OA));
        printf("Case %d: %f\n",i+1,theta*OA);
    }
    return 0;
}

