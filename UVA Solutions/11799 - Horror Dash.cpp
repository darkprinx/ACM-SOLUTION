#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;
int main()
{
    int t,n,c;
    vector<int> ara;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>c;
            ara.push_back(c);
        }
        printf("Case %d: %d\n",i,*max_element(ara.begin(),ara.end()));
        ara.clear();
    }
    return 0;
}

