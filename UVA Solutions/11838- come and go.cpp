#include<bits/stdc++.h>
#define pf printf
#define sf scanf
#define ll  long long
#define pb push_back
#define M 2000
using namespace std;

template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

vector<int > g1[M+5],g2[M+5];
stack<int>st;
int color1[M+5],color2[M+5],n,m;

void dfs1(int b)
{
    if(color1[b]!=0)
        return ;
    color1[b]=1;
    for(int i=0; i<g1[b].size(); i++)
        dfs1(g1[b][i]);
    st.push(b);
}
void dfs2(int b)
{
    if(color2[b]!=0)
        return ;
    color2[b]=1;
    for(int i=0; i<g2[b].size(); i++)
        dfs2(g2[b][i]);
}

int main()
{
    int i,j,a,b,u,v,p;
    while(1)
    {
        fs(n);
        fs(m);
        if(n==0 && m==0)
            break;
        memset(color1,0,sizeof(color1));
        memset(color2,0,sizeof(color2));
        while(!st.empty())
            st.pop();
        for(i=1; i<=n; i++)
        {
            g1[i].clear();
            g2[i].clear();
        }
        for(i=0; i<m; i++)
        {
            fs(u);
            fs(v);
            fs(p);
            if(p==1)
            {
                g1[u].pb(v);
                g2[v].pb(u);
            }
            else
            {
                g1[u].pb(v);
                g1[v].pb(u);
                g2[u].pb(v);
                g2[v].pb(u);
            }
        }
        for(i=1; i<=n; i++)
        {
            if(color1[i]==0)
                dfs1(i);
        }
        b=0;
        while(!st.empty())
        {
            a=st.top();
            st.pop();
            if(color2[a]==0)
            {
                b++;
                dfs2(a);
            }
        }
        if(b>1)
            pf("0\n");
        else
            pf("1\n");
    }
    return 0;
}






















