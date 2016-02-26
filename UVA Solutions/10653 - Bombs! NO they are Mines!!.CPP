
/* Problem Name: 10653 - Bombs! NO they are Mines!!
       Platform: UVA
     Algorithom: BFS 2D GRID
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
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include<assert.h>


#define pi 2*acos(0.0)
#define PS system("pause")
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define Sfor(n) for(int i=1;i<=n;i++)
#define inf 1<<30
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)x.size())
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
#define lcm(a,b) (a*(b/gcd(a,b)))
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
#define bit_cnt(x)   __builtin_popcount(x)
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define btz(a)   __builtin_ctz(a)
using namespace std;

int area[1001][1001];
bool vis[1001][1001];

int fx[]= {0,0,1,-1};
int fy[]= {1,-1,0,0};
int row,col,start_x,start_y,dest_x,dest_y;

int BFS()
{
    vis[start_x][start_y]=0;
    queue<int>q;
    q.push(start_x);
    q.push(start_y);

    while(!q.empty())
    {
        int top_x,top_y,nx,ny;
        top_x=q.front();
        q.pop();
        top_y=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            nx=top_x+fx[i];
            ny=top_y+fy[i];

            if(nx>=0&&nx<row&&ny>=0&&ny<col&&vis[nx][ny]==true)
            {
                vis[nx][ny]=false;
                area[nx][ny]=area[top_x][top_y]+1;
                if(nx==dest_x&&ny==dest_y)
                    return area[nx][ny];
                q.push(nx);
                q.push(ny);
            }
        }
    }
}
int main()
{
    int Rn,rb,bomnum,cb;
    while(s(row)==1&&s(col)==1)
    {
        if(row==0&&col==0)
            break;
        memset(vis,true,sizeof(vis));
        memset(area,0,sizeof(area));

        s(Rn);
        for(int i=0; i<Rn; i++)
        {
            s(rb);
            s(bomnum);
            for(int j=0; j<bomnum; j++)
            {
                s(cb);
                vis[rb][cb]=false;
            }
        }
        s(start_x);
        s(start_y);
        s(dest_x);
        s(dest_y);
        cout<<BFS()<<endl;
    }
    return 0;
}



