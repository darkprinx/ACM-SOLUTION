#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
int main()
{
int casos, cols, northRow, southRow;
scanf("%d", &casos);
while(casos--)
{
    scanf("%d", &cols);
    set<int> mySet;
    for(int x=0; x<cols; x++)
    {
        scanf("%d %d",&northRow, &southRow);
        mySet.insert(abs(northRow - southRow));
    }

    if(mySet.size() == 1)
       printf("yes\n");
    else
        printf("no\n");
        if(casos)
       printf("\n");
}
return 0;
}
