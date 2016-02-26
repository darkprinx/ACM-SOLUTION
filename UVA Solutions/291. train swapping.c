#include<iostream>
using namespace std;

int main()
{
    int z,X[50],test,line,i,j;
    while(cin>>z)
    {

        for(test=0; test<z; test++)
        {
            int count=0;
            cin>>line;
            for(i=0; i<line; i++)
            {
                cin>>X[i];
            }
            for(i=0; i<line; i++)
            {
                for(int j=i+1; j<line; j++)
                {
                    if(X[i]>X[j])
                    {
                        swap(X[i],X[j]);
                        count++;
                    }
                }

            }
            cout<<"Optimal train swapping takes "<<count<<" swaps."<<endl;
        }
    }
    return 0;
}

