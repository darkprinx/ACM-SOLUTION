#include<cstdio>
using namespace std;
int main()
{
    int a,b,c,d,B,C,D,sum;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)==4&&(a||b||c||d)!=0)
    {
        B=((40-b)+a)%40;
        if(b<c||b==c)
            C=(c-b);
        else
            C=((40-b)+c);
        D=((40-d)+c)%40;
        sum=1080+9*(B+C+D);
        printf("%d\n",sum);
    }
    return 0;
}

