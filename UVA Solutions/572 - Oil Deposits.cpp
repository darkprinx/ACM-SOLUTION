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
#include <sstream>
#include <fstream>
#define s(n)          scanf("%d",&n)
#define loop(i,a,b)    for(int i=int(a);i<int(b);i++)
using namespace std;

char Map[100][100];
int next[8][2]={{-1,1},{-1,0},{-1,-1},{0,1},{0,-1},{1,1},{1,0},{1,-1}};
void BFS(int x,int y,int xmax,int ymax)
{
    int px,py,nx,ny;
    queue<int> Q;
    Map[x][y]='*';
    Q.push(x);
    Q.push(y);
    while(!Q.empty())
    {
        px=Q.front();
        Q.pop();
        py=Q.front();
        Q.pop();
        for(int i=0;i<8;i++)
        {
            nx=px+next[i][0];
            ny=py+next[i][1];
            if(nx>=0&&nx<xmax&&ny>=0&&ny<ymax&&Map[nx][ny]=='@')
            {
                Map[nx][ny]='*';
                Q.push(nx);
                Q.push(ny);
            }
        }
    }

}

void show(int M,int N)
{
    loop(I,0,M)
        {
            loop(K,0,N)
            {
                cout<<Map[I][K];
            }
            cout<<endl;
        }
}

int main()
{
    int M,N,I,K,oil;
    while(cin>>M>>N&&M!=0)
    {
        oil=0;
        loop(I,0,M)
        {
            loop(K,0,N)
                cin>>Map[I][K];
        }
        loop(I,0,M)
        {
            loop(K,0,N)
                {
                    if(Map[I][K]=='@')
                    {
                        BFS(I,K,M,N);
                        oil++;
                    }
                }
        }
        cout<<oil<<endl;
    }
    return 0;
}
