#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int ,int> ii;
typedef vector <int> vi;

vector <pair<double ,ii> > edges;
vi pset,vx,vy;

void init(int N){
    pset.assign(N,0);
    for(int i=0;i<N;i++) pset[i]=i;
}

int find_set(int i){
    if(pset[i]==i) return pset[i];
    return pset[i]=find_set(pset[i]);
}

bool issameset(int i,int j){ return find_set(i)==find_set(j); }

void joinset(int i,int j){ pset[find_set(i)]=find_set(j); }

int main(){
    int n,m,a,b;
    double dist;
    while(scanf("%d",&n)==1){
        init(n);
        edges.clear(); vx.clear(); vy.clear();
        for(int i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            vx.push_back(a); vy.push_back(b);
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                dist=sqrt( (vx[i]-vx[j])*(vx[i]-vx[j]) + (vy[i]-vy[j])*(vy[i]-vy[j]) );
                ii tmp=make_pair(i,j);
                edges.push_back(make_pair(dist,tmp));
            }
        }

        scanf("%d",&m);
        while(m--){
            scanf("%d %d",&a,&b);
            a--,b--;
            if(!issameset(a,b)) joinset(a,b);
        }

        sort(edges.begin(),edges.end());
        double sum=0.0;
        for(int i=0;i<edges.size();i++){
            if(!issameset(edges[i].second.first,edges[i].second.second)){
                sum+=edges[i].first;
                joinset(edges[i].second.first,edges[i].second.second);
            }
        }
        printf("%0.2lf\n",sum);
    }
    return 0;
}
