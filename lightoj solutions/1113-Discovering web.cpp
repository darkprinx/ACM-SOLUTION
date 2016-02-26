#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

int main()
{

    vector<string> line;
    vector<string> :: iterator it;
    string word,l;
    int T;
    cin>>T;
    for(int k=0; k<T; k++)
    {
        line.clear();
         line.push_back("http://www.lightoj.com/");
         int i=0,sum=0;
        printf("Case %d:\n",k+1);
        while(cin>>word&&word!="QUIT")
        {
            if(word=="VISIT")
            {
                i=i+1;
                sum++;
                if(i<sum)
                {
                    cin>>l;
                    for(int m=i; m<sum; m++)
                        line.pop_back();
                    line.push_back(l);
                    cout<<line[i]<<endl;
                    sum=i;
                }
                else if(i==sum)
                {
                    cin>>l;
                    line.push_back(l);
                    cout<<line[i]<<endl;
                }
            }
            if(word=="BACK")
            {
                i--;
                if(i<0)
                {
                    cout<<"Ignored"<<endl;
                    i=0;
                }
                else
                    cout<<line[i]<<endl;
            }
            if(word=="FORWARD")
            {
                i=i+1;
                if(i>sum)
                {
                    cout<<"Ignored"<<endl;
                    i=sum;
                }
                else
                    cout<<line[i]<<endl;
            }

        }

    }

    return 0;
}

