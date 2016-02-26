/*
   Problem Name: 12893 - Count It
       Platform: UVa
     Algorithom: Ad Hoc
   Coder's Name: RC Tushar

~~~ Never Show Your Arrogance.Keep In Mind,You Were Born From A Drop Of Impure Liquid ~~~

*/

#include<cstdio>


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

int num[2];
int main()
{
long long int n;
int cas;
num[0]=0;
num[1]=1;
fs(cas);
while(cas--)
{
fs(n);
int cnt=0;
while(n>1)
{
    cnt+=(n&1);
    n/=2;
}
printf("%d\n",num[n]+cnt);
}
return 0;
}

