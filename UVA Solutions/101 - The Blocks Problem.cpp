/* Problem Name: 101 - The Blocks Problem
       Platform: uva
     Algorithom: SIMULATION (DATA STRUCTURE)
   Coder's Name: R C Tushar
*/


#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <cstdio>
using namespace std;

#define s(n)          scanf("%d",&n)
#define MOD           1000000007
#define INF           (int)1e9
#define EPS           1e-9
#define loop(i,a,b)    for(int i=int(a);i<int(b);i++)

struct block
{
    vector<int> num;
};
block cell[50];
vector<int> ::iterator it;

int possB,indexB,possA,indexA;

void POSITION_B(int K,int LOW,int HIGH,int part)
{
    int D=-1,C;
    loop(K,LOW,HIGH)
    {
        D++;
        C=-1;
        for(it=cell[K].num.begin(); it!=cell[K].num.end(); it++)
        {
            C++;
            if(*it==part)
            {
                possB=C;
                indexB=D;
                break;
            }
        }
    }
}
void POSITION_A(int K,int LOW,int HIGH,int part)
{
    int D=-1,C;
    loop(K,LOW,HIGH)
    {
        D++;
        C=-1;
        for(it=cell[K].num.begin(); it!=cell[K].num.end(); it++)
        {
            C++;
            if(*it==part)
            {
                possA=C;
                indexA=D;
                break;
            }
        }
    }
}

int main()
{
    int I,K,M,n,a,b,possition;
    string word1,word2;
    cin>>n;
    loop(I,0,n)
    {
        cell[I].num.push_back(I);
    }

    while(true)

    {
        cin>>word1;
        if(word1=="quit")
            break;
        s(a);
        cin>>word2;
        s(b);
        if(word1=="move"&&word2=="onto")
        {
            //search position for B
            POSITION_B(K,0,n,b);
            //search position for A
            POSITION_A(K,0,n,a);
            if(indexA==indexB||a==b)
                continue;
            else
            {
                //            //reform of A
                for(int M=possA+1; M<cell[indexA].num.size(); M++)
                {
                    possition=cell[indexA].num[M];
                    if(cell[possition].num.size()>0)
                        cell[possition].num.clear();
                    cell[possition].num.push_back(possition);

                }
                // reform of B
                for(int M=possB+1; M<cell[indexB].num.size(); M++)
                {
                    possition=cell[indexB].num[M];
                    if(cell[possition].num.size()>0)
                        cell[possition].num.clear();
                    cell[possition].num.push_back(possition);

                }

                if(cell[indexB].num.size()>1&&cell[indexA].num.size()==1)
                {

                    int SIZE=cell[indexB].num.size();
                    for(int M=possB+1; M<SIZE; M++)
                        cell[indexB].num.pop_back();
                    cell[indexB].num.push_back(a);
                    cell[indexA].num.clear();
                }
                else if(cell[indexA].num.size()>1&&cell[indexB].num.size()==1)
                {
                    int SIZEA=cell[indexA].num.size();
                    //POP BACK
                    for(int M=possA; M<SIZEA; M++)
                        cell[indexA].num.pop_back();

                    cell[indexB].num.push_back(a);

                }
                else if(cell[indexA].num.size()>1&&cell[indexB].num.size()>1)
                {
                    int SIZEA=cell[indexA].num.size();
                    int SIZEB=cell[indexB].num.size();

                    //POP BACK
                    for(int M=possA; M<SIZEA; M++)
                        cell[indexA].num.pop_back();
                    for(int M=possB+1; M<SIZEB; M++)
                        cell[indexB].num.pop_back();

                    cell[indexB].num.push_back(a);
                }
                else
                {
                    cell[indexB].num.push_back(a);
                    cell[indexA].num.clear();
                }
            }
        }
        if(word1=="move"&&word2=="over")
        {
            //search for B
            POSITION_B(K,0,n,b);
            //search for A
            POSITION_A(K,0,n,a);
            if(indexA==indexB||a==b)
                continue;
            else if(cell[indexA].num.size()>1)
            {
                int SIZEA=cell[indexA].num.size();
                //reformation
                for(int M=possA+1; M<SIZEA; M++)
                {
                    possition=cell[indexA].num[M];
                    cell[possition].num.clear();
                    cell[possition].num.push_back(possition);
                }
                //pop back
                for(int M=possA; M<SIZEA; M++)
                    cell[indexA].num.pop_back();

                cell[indexB].num.push_back(a);
            }
            else
            {
                cell[indexB].num.push_back(a);
                cell[indexA].num.clear();
            }
        }
        else if(word1=="pile"&&word2=="onto")
        {
            //search for B
            POSITION_B(K,0,n,b);
            //search for A
            POSITION_A(K,0,n,a);
            if(indexA==indexB||a==b)
                continue;
            else
            {
                //reform B
                for(M=possB+1; M<cell[indexB].num.size(); M++)
                {
                    possition=cell[indexB].num[M];
                    cell[possition].num.clear();
                    cell[possition].num.push_back(possition);
                }
                int SIZEB=cell[indexB].num.size();
                int SIZEA=cell[indexA].num.size();
                //POP BACK
                for(M=possB+1; M<SIZEB; M++)
                    cell[indexB].num.pop_back();
                //piling push_back
                for(M=possA; M<SIZEA; M++)
                {
                    int x;
                    x=cell[indexA].num[M];
                    cell[indexB].num.push_back(x);
                }
                if(SIZEA==1)
                    cell[indexA].num.clear();
                else if(SIZEA>1)
                {
                    for(M=possA; M<SIZEA; M++)
                        cell[indexA].num.pop_back();
                }

            }
        }
        else if(word1=="pile"&&word2=="over")
        {
            //search for B
            POSITION_B(K,0,n,b);
            //search for A
            POSITION_A(K,0,n,a);
            if(indexA==indexB||a==b)
                continue;
            else if(cell[indexA].num.size()>1)
            {
                int SIZEA=cell[indexA].num.size();
                //piling push_back
                for(M=possA; M<SIZEA; M++)
                {
                    int x;
                    x=cell[indexA].num[M];
                    cell[indexB].num.push_back(x);
                }
                //pop back
                for(int M=possA; M<SIZEA; M++)
                    cell[indexA].num.pop_back();

            }
            else
            {
                cell[indexB].num.push_back(a);
                cell[indexA].num.clear();
            }

        }
    }
    loop(I,0,n)
    {
        cout<<I<<":";
        for(it=cell[I].num.begin(); it!=cell[I].num.end(); it++)
            cout<<' '<<*it;
        cout<<endl;
    }
    return 0;
}
