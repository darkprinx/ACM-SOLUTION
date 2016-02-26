#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    int T, N, c[258], p;
    char ch;
    scanf("%d\n", &T);
    while(T-- && scanf("%d\n", &N)==1) {
        memset(c, 0, sizeof c);
        while (N-- && scanf("%c %d\n", &ch, &p)==2) c[ch + 128] = p;
        scanf("%d\n", &N);
        while (N--) while ((ch = getchar()) != '\n')
                c[257] += c[ch + 128];
        printf("%d.%02d$\n", c[257] / 100, c[257] % 100);
    }
    return 0;
}
