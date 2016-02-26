#include<iostream>

using namespace std;

int main()
{
    int testCase;
    unsigned int x,y;
    cin >> testCase;
    for(int i=0; i<testCase; i++)
    {
        cin >> x >>y;

        if(x>=y && (x+y)%2 == 0)
        {
            x=(x+y)/2;
            y=(x-y);
            cout << x << ' ' << y <<endl;
        }

        else
        {
            cout <<"impossible"<<endl;
        }
    }

    return 0;
}
