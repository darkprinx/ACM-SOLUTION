
/*
   Problem name: 1238- power Puff Girls
       Platform: Lightoj
      Algorithm: BFS 2D grid
   Coder's Name: R C Tushar
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include<assert.h>


#define PS system("pause")
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define inf 1<<30
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)x.size())
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
#define on(x,w)  x=x|(1<<w)
#define check(x,w) (x&(1<<w))==(1<<w)?true:false
#define all(x) (x).begin(),(x).end()
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pf printf
#define ll long long int
#define MOD 1000000007
#define sqr(x) (( (x)* (x))%MOD)
#define cube(x)   ( (sqr(x)*(x))%MOD)
#define bit_cnt(x)   __builtint_popcount(x)
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))
#define max2(a,b)   max(a,b)
#define max3(a,b,c)   max(a,max2(b,c))
using namespace std;

int fx[]= {0,0,1,-1};
int fy[]= {1,-1,0,0};

char maze[23][23];
int r,c,ans=0;

int BFS(int x,int y)
{
    int mark[23][23]= {};
    int cost[23][23];
    queue<int>q;
    mark[x][y]=-1;
    cost[x][y]=0;
    q.push(x);
    q.push(y);
    while(!q.empty())
    {
        int nx,ny,n,m;
        n=q.front();
        q.pop();
        m=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            nx=n+fx[i];
            ny=m+fy[i];
            if(nx>=0&&nx<r&&ny>=0&&ny<c&&mark[nx][ny]==0)
            {
                if(maze[nx][ny]!='#'&&maze[nx][ny]!='m')
                {
                  cost[nx][ny]=cost[n][m]+1;
                  mark[nx][ny]=-1;
                  if(maze[nx][ny]=='h')
                        return cost[nx][ny];
                q.push(nx);
                q.push(ny);
                }

            }
        }
    }
}

int main()
{

    int test ,x[3],y[3];
    s(test);
    loop(i,0,test)
    {
        s(r);
        s(c);
        loop(j,0,r)
        {
            loop(k,0,c)
            {
                cin>>maze[j][k];
                if(maze[j][k]=='a')
                {
                    x[0]=j;
                    y[0]=k;
                }
                 else if(maze[j][k]=='b')
                {
                    x[1]=j;
                    y[1]=k;
                }
                 else if(maze[j][k]=='c')
                {
                    x[2]=j;
                    y[2]=k;
                }
            }
        }
        int a,b,c;
        a=BFS(x[0],y[0]);
        b=BFS(x[1],y[1]);
        c=BFS(x[2],y[2]);
        pf("Case %d: %d\n",i+1,max3(a,b,c));
    }

    return 0;
}
