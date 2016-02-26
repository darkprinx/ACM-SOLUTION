
/* Problem Name: 439 - Knight Moves
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

int bord[10][10];
bool mark[10][10];

int fx[]={2,2,-2,-2,1,-1,1,-1};
int fy[]={1,-1,1,-1,2,2,-2,-2};
int ax,ay,bx,by;

int BFS()
{
  int x,y,nx,ny;
  mark[ax][ay]=false;

  queue<int>q;
  q.push(ax);
  q.push(ay);

  while(!q.empty())
  {
      x=q.front();
      q.pop();
      y=q.front();
      q.pop();
      for(int i=0;i<8;i++)
      {
        nx=x+fx[i];
        ny=y+fy[i];
        if(nx>=1&&nx<9&&ny>=1&&ny<9&&mark[nx][ny]==true)
        {
            bord[nx][ny]=bord[x][y]+1;
            if(nx==bx&&ny==by)
                return bord[nx][ny];
            mark[nx][ny]=false;
            q.push(nx);
            q.push(ny);
        }
      }
  }
}

int main()
{
char a[3],b[3];

while(cin>>a>>b)
{
    memset(bord,0,sizeof(bord));
    memset(mark,true,sizeof(mark));

    ax=a[0]-96;
    bx=b[0]-96;
    ay=a[1]-48;
    by=b[1]-48;
    if(strcmp(a,b)==0)
    pf("To get from %s to %s takes 0 knight moves.\n",a,b);
    else
    pf("To get from %s to %s takes %d knight moves.\n",a,b,BFS());
}

return 0;
}



