#include<cstdio>
#include<vector>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t,n,m,sum,num,x,y;
    char s;
    vector<int> a,b;
    vector<int>::iterator it;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        a.clear();
        cin>>n>>m;
        for(int j=0; j<n; j++)
        {
            cin>>num;
            a.push_back(num);
        }
        for(int k=0; k<m; k++)
        {
            cin>>s;
            if(s=='S')
            {
                cin>>x;
                for(it=a.begin(); it!=a.end(); it++)
                    *it=*it+x;
            }
            else if(s=='M')
            {
                cin>>x;
                for(it=a.begin(); it!=a.end(); it++)
                    *it=*it*x;
            }
            else if(s=='D')
            {
                cin>>x;
                for(it=a.begin(); it!=a.end(); it++)
                    *it=*it/x;
            }
            else if(s=='R')
            {
                for(int l=n-1;l>=0; l--)
                {
                    b.push_back(a[l]);
                }
                a.clear();
                for(int l=0; l<n; l++)
                {
                    a.push_back(b[l]);
                }
                b.clear();
            }
            else if(s=='P')
            {
                cin>>x>>y;
                swap(a[x],a[y]);
            }
        }
        printf("Case %d:\n",i+1);
        cout<<a[0];
          for(it=a.begin()+1;it!=a.end();it++)
                printf(" %d",*it);
                cout<<endl;
    }
return 0;
}

