#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
    int n[3][3],i,f,j,sum=0,g[6],x,min;
    while(1)
    {
        sum=0;
        f=1;
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                f=(scanf("%d",&n[i][j]));
                if(f==EOF)
                {
                    f=0;
                    break;
                }
                sum=sum+n[i][j];
            }
        }
        if(f==0)
            break;
        g[0]=n[0][0]+n[1][2]+n[2][1];
        g[1]=n[0][0]+n[1][1]+n[2][2];
        g[2]=n[0][2]+n[1][0]+n[2][1];
        g[3]=n[0][2]+n[1][1]+n[2][0];
        g[4]=n[0][1]+n[1][0]+n[2][2];
        g[5]=n[0][1]+n[1][2]+n[2][0];

        for(i=0; i<6; i++)
            g[i]=sum-g[i];
        x=0;
        min=g[0];
        for(i=1; i<6; i++)
        {

            if(min>g[i])
            {
                min=g[i];
                x=i;
            }
        }
        switch(x)
        {
        case 0:
            cout<<"BCG "<<min<<endl;
            break;
        case 1:
            cout<<"BGC "<<min<<endl;
            break;
        case 2:
            cout<<"CBG "<<min<<endl;
            break;
        case 3:
            cout<<"CGB "<<min<<endl;
            break;
        case 4:
            cout<<"GBC "<<min<<endl;
            break;
        case 5:
            cout<<"GCB "<<min<<endl;
            break;
        }

    }
    return 0;
}
