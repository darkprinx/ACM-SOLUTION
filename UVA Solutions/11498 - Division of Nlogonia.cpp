#include<iostream>
using namespace std;
int main()
{
    int i,k,N,M;
    while(cin>>k&&(k<1001&&k>0))
    {

        int X[k],Y[k];
        cin>>N>>M;
        for(i=0; i<k; i++)
        {
            cin>>X[i]>>Y[i];
            if(X[i]>N&&Y[i]>M)
                cout<<"NE"<<endl;
            else if(X[i]<N&&Y[i]>M)
                cout<<"NO"<<endl;
            else if(X[i]<N&&Y[i]<M)
                cout<<"SO"<<endl;
            else if(X[i]>N&&Y[i]<M)
                cout<<"SE"<<endl;
            else if(X[i]==N||Y[i]==M)
                cout<<"divisa"<<endl;
        }
    }
    return 0;
}
