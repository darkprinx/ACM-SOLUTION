#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#define M  102
using namespace std;

vector<int> node[M],ans;
int cycle;
int  visit[M]= {};
void take(int p)
{
    if(visit[p]==2||cycle)
        return;
    if(visit[p])
    {
        cycle=1;
        return;
    }
    visit[p]=1;
    for(int i=0; i<node[p].size(); i++)
            take(node[p][i]);
    ans.push_back(p);
    visit[p]=2;
}

int main()
{

    int i,j,k,n,a,b,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
            break;
        int indeg[M]= {};
        cycle=0;
        memset(visit,0,sizeof(visit));
        for(i=0; i<m; i++)
        {
            cin>>a>>b;
            node[a].push_back(b);
            indeg[b]++;
        }
        for(i=1; i<=n; i++)
            if(indeg[i]==0)
                take(i);
        int SZ=ans.size();

        for(int i=SZ-1; i>=0; i--)
        {
            printf("%d", ans[i] );
            if(i>0)
                cout<<" ";
        }
    cout<<endl;
    ans.clear();
    for(i=0; i<=n; i++)
        node[i].clear();
    }

    return 0;
}





