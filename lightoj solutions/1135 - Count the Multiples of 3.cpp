#include<bits/stdc++.h>
#define pf printf
#define sf scanf
#define ll  long long
#define PS system("pause")
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

int n,q;
struct info
{
    int prog0,prog1,prog2,tot;
} tree[300015];

void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].tot=0;
        tree[node].prog0=1;
        tree[node].prog1=0;
        tree[node].prog2=0;
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[node].prog0=tree[left].prog0+tree[right].prog0;
    tree[node].prog1=tree[left].prog1+tree[right].prog1;
    tree[node].prog2=tree[left].prog2+tree[right].prog2;
}

void update(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].tot++;
        swap(tree[node].prog0,tree[node].prog1);
        swap(tree[node].prog0,tree[node].prog2);
        return;
    }

    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;

    if(tree[node].tot)
    {
        tree[left].tot+=tree[node].tot;
        tree[right].tot+=tree[node].tot;
        int r=tree[node].tot%3;
        for(int k=0; k<r; k++)
        {
            swap(tree[left].prog0,tree[left].prog1);
            swap(tree[left].prog0,tree[left].prog2);
            swap(tree[right].prog0,tree[right].prog1);
            swap(tree[right].prog0,tree[right].prog2);
        }
        tree[node].tot=0;
    }

    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);

    tree[node].prog0=tree[left].prog0+tree[right].prog0;
    tree[node].prog1=tree[left].prog1+tree[right].prog1;
    tree[node].prog2=tree[left].prog2+tree[right].prog2;
}

int query(int node,int b,int e,int i,int j)
{
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;

    if (i > e || j < b)
        return 0;
    if(b>=i && e<=j)
        return tree[node].prog0;


    if(tree[node].tot)
    {
        tree[left].tot+=tree[node].tot;
        tree[right].tot+=tree[node].tot;
        int r=tree[node].tot%3;
        for(int k=0; k<r; k++)
        {
            swap(tree[left].prog0,tree[left].prog1);
            swap(tree[left].prog0,tree[left].prog2);
            swap(tree[right].prog0,tree[right].prog1);
            swap(tree[right].prog0,tree[right].prog2);
        }
        tree[node].tot=0;
    }

    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

int main()
{

    int t,tt,a,b,c,d,e,f,g,h,i,j;
    fs(tt);
    for(t=1; t<=tt; t++)
    {
        fs(n);
        fs(q);

        init(1,0,n-1);
        pf("Case %d:\n",t);
        while(q--)
        {
            fs(a);
            fs(i);
            fs(j);
            if(a==0)
                update(1,0,n-1,i,j);
            else
            {
                d=query(1,0,n-1,i,j);
                pf("%d\n",d);
            }
        }
    }
    return 0;
}
