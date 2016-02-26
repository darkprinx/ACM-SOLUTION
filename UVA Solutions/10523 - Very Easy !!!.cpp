
/* Problem Name:
       Platform:
     Algorithom:
   Coder's Name:
*/

#include<bits/stdc++.h>

#define pi 2*acos(0.0)
#define PS system("pause")
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define Sfor(n) for(int i=1;i<=n;i++)
#define inf (1<<30)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)x.size())
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define on(x,w)  x=x|(1<<w)
#define check(x,w) (x&(1<<w))==(1<<w)?true:false
#define all(x) (x).begin(),(x).end()
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pf printf
#define ll long long int
#define MOD 1000000007
#define sqr(x) (( (x)* (x))%MOD)
#define cube(x)   ( (sqr(x)*(x))%MOD)
#define bit_cnt(x)   __builtin_popcount(x)
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define btz(a)   __builtin_ctz(a)
#define Mems(p,n) memset(p, n, sizeof(p))
#define makeint(n,s)  istringstream(s)>>n
#define BOUNDARY(i,j,Row,Col) ((i >= 0 && i < Row) && (j >= 0 && j < Col))
#define M  20002
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction

typedef vector<int> vi;

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

//~~~~~~~~~~~~~~~~~CODE STARTING POINT~~~~~~~~~~~~~~~~~~~~~~

string add(string a,string b)
{
    string num,str;
    int len1=a.length(),len2=b.length();
    if(len1<len2)
        {
            swap(a,b);
            swap(len1,len2);
        }
    for(int i=len1-1,j=len2-1;i>=0;i--,j--)
    {
        int temp=0,n1,n2;
        n1=a[i]-48;
        if(j<0)
            n2=0;
        else
        n2=b[j]-48;
        if(n1+n2>9)
        {
            temp=(n1+n2)%10;
            num.push_back(temp+48);
            if(i==0)
                num.push_back(49);
            else
               a[i-1]+=1;
        }
        else
        num.push_back(n1+n2+48);
    }
    for(int i=num.length()-1;i>=0;i--)
    {
        str.push_back(num[i]);
    }
    return str;
}

string mult(string a, string b)
{
    int len= a.length() + b.length();
    string result(len, '0'),ret;
    int num;
    int i, j;
    int last_pos_i, last_pos_j, last_pos_k;
    last_pos_i= len - 1;
    for (i= b.length() - 1; i >= 0; i --)
    {
        last_pos_j= last_pos_i;
        for (j= a.length() - 1; j >=0; j --)
        {
            last_pos_k= last_pos_j;
            num= INT(a[j]) * INT(b[i]);
            while (num)
            {
                num += INT(result[last_pos_k]);
                result[last_pos_k]= CHAR(num % 10);
                num= num / 10;
                last_pos_k --;
            }
            last_pos_j --;
        }
        last_pos_i --;
    }

    if(result[0]==48)
        result.erase(0,1);

    if(result[0]==48)
        return "0";
    return result;
}

string num[17][152];

void easy()
{
    for(int i=0; i<=15; i++)
    {
        string ans="0";
        string sum="1";
        string str;
        stringstream cs;
        cs<<i;
        str=cs.str();
        for(int j=1; j<=150; j++)
        {
            string inc;
            stringstream ss;
            ss<<j;
            inc=ss.str();
            sum=mult(sum,str);
            ans=add(ans,mult(inc,sum));
            num[i][j]=ans;
        }
    }
}

int main()
{
int n,m;
easy();

while(s(n)==1&&s(m)==1)
cout<<num[m][n]<<endl;


return 0;
}



