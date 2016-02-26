/* Problem Name: 871- Counting Cells In a Blob
       Platform: UVA
     Algorithom: BFS 2D
   Coder's Name: Rc Tushar
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
#define inf (1<<30)
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
#define Mems(p,n) memset(p, n, sizeof(p))
#define BOUNDARY(i,j,Row,Col) (i >= 0 && i < Row) && (j >= 0 && j < Col)
#define M  1000
using namespace std;

typedef vector<int> vi;

char MAP[26][26];

int MAX,r,c;
int fx[]={0,0,1,-1,1,1,-1,-1};
int fy[]={1,-1,0,0,1,-1,1,-1};

void bfs(int x,int y)
{
   queue<int> q;
   MAP[x][y]='0';
   int cnt=1;
   MAX=max(MAX,cnt);
   q.push(x);
   q.push(y);
   while(!q.empty())
   {
       int top_x,top_y;
       top_x=q.front();
       q.pop();
       top_y=q.front();
       q.pop();

       for(int i=0;i<8;i++)
       {
           int nx,ny;
           nx=top_x+fx[i];
           ny=top_y+fy[i];

           if(BOUNDARY(nx,ny,r,c)&&MAP[nx][ny]=='1')
           {
               MAP[nx][ny]='0';
               cnt++;
               MAX=max(MAX,cnt);
               q.push(nx);
               q.push(ny);
           }
       }

   }

}

int main()
{
    int test;
    scanf("%d\n",&test);
    string line;
    Sfor(test)
    {
        r=0,MAX=0;
        while(getline(cin,line))
        {
            if(line.size()==0)
                break;
            c=line.size();
            for(int j=0;j<r+c;j++)
                MAP[r][j]=line[j];
            r++;
        }
        for(int j=0; j<r; j++)
            for(int k=0; k<c; k++)
                if(MAP[j][k]=='1')
                    bfs(j,k);

        cout<<MAX<<endl;
        if(i<test)
            pf("\n");
    }

    return 0;
}


















