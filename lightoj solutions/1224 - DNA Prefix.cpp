/*
   Problem Name: 1224 - DNA Prefix
       Platform: LightOj
     Algorithom: String Proccesing (Trie / Prefix tree)
   Coder's Name: RC Tushar

~~~ Never Show Your Arrogance.Keep In Mind,You Were Born From A Drop Of Impure Water ~~~

*/

#include<bits/stdc++.h>

#define pi 2*acos(0.0)
#define PS system("pause")
#define siter(n,T1)  for(set<T1>::iterator it=n.begin();it!=n.end();it++)
#define miter(n,T1,T2)  for(map<T1,T2>::iterator it=n.begin();it!=n.end();it++)
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define Sfor(n) for(int i=1;i<=n;i++)
#define inf (1<<30)
#define pb push_back
#define ppb pop_back
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
#define fot(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
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
#define M 5
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


struct node
{
    bool mark;
    node *next[M];
    int cnt[M];
    node()
    {
        mark=false;
        loop(i,0,M)
        {
            next[i]=NULL;
            cnt[i]=0;
        }
    }
}*root;

int boro_vai;

int dhukao(string str,int len)
{
    node *cur=root;
    for(int i=0; i<len; i++)
    {
        int id;
        switch(str[i])
        {
            case 'A':id=str[i]-65;
            break;
            case 'C': id=str[i]-66;
            break;
            case 'G': id=str[i]-69;
            break;
            case 'T': id=str[i]-81;
            break;
        }
        cur->cnt[id]++;
        boro_vai=max((i+1)*cur->cnt[id],boro_vai);
        if(cur->next[id]==NULL)
            cur->next[id]=new node();

        cur=cur->next[id];
    }
    cur->mark=true;
}



void ghechang(node * tree)
{
    for(int i=0; i<4; i++)
        if(tree->next[i])
            ghechang(tree->next[i]);
    delete (tree);
}
int main()
{
    string str;
    int test,n;

    fs(test);

    Sfor(test)
    {
       root=new node();
       boro_vai=0;
       fs(n);
       loop(j,0,n)
       {
        cin>>str;
        dhukao(str,str.length());
       }
       pf("Case %d: %d\n",i,boro_vai);
        ghechang(root);
    }
    return 0;
}
