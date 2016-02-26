#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cmath>

using namespace std;

char block[25][25];
int r,c,cnt=0,trav[25][25];

void DFS(int I,int K)
{
    if(I<0||K<0||I>=c||K>=r)
        return ;
    if(block[I][K]=='#'||trav[I][K]==-1)
        return ;
    else
    {
        cnt++;
        trav[I][K]=-1;
        DFS(I,K+1);
        DFS(I+1,K);
        DFS(I-1,K);
        DFS(I,K-1);
    }
}

int main()
{
    int I,K,M,X,Y,Test;
    cin>>Test;
    for(M=0;M<Test;M++)
    {
        cin>>r>>c;
        for(I=0;I<c;I++)
        {
            for(K=0;K<r;K++)
            {
                trav[I][K]=0;
            }
        }
        for(I=0;I<c;I++)
        {
            for(K=0;K<r;K++)
            {
                cin>>block[I][K];
                if(block[I][K]=='@')
                {
                    X=I;
                    Y=K;
                }
            }
        }

        DFS(X,Y);
        printf("Case %d: %d\n",M+1,cnt);
        cnt=0;
    }

    return 0;
}


