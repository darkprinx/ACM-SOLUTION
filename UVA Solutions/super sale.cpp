#include<iostream>
#include<cstring>
#include<cstdio>
#define MAX 1010
using namespace std;
int price[MAX],wit[MAX],DP[MAX][35];
int cap,n;
int knap(int i,int w)
{
    int prof1=0,prof2=0;
    if(i==n+1)
        return 0;
    if(DP[i][w]!=-1)
        return DP[i][w];
    if(w+wit[i]<=cap)
        prof1=price[i]+knap(i+1,w+wit[i]);

    prof2=knap(i+1,w);
    DP[i][w]=max(prof1,prof2);
    return DP[i][w];
}
int main()
{
    int Tcase,man;
    cin>>Tcase;
    while(Tcase--)
    {
        int total=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>price[i]>>wit[i];
        }
        cin>>man;
        while(man--)
        {
            memset(DP,-1,sizeof(DP));
            cin>>cap;
            total+=knap(1,0);
        }
        cout<<total<<endl;
    }
     return 0;
}
