#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 400004
#define INF 0x3f7f7f7f
char p[MAX];
int l, next[MAX], ans[MAX];

void getnext()
{
    int i = 0, j = -1;
    memset(next, 0, sizeof(next));
    next[0] = -1;
    while(i < l)
    {
        if(j == -1 || p[i] == p[j])
        {
            i++;    j++;
            next[i] = j;
        }
        else j = next[j];
    }
}
int main(void)
{
    int i, t, ct;
    while(scanf("%s", p) != EOF)
    {
        ct = 0;
        l = strlen(p);
        getnext();

        for(i = l; i > 0; i = next[i])  ans[++ct] = i;

        for(i = ct; i >= 1; i--)   printf("%d%c", ans[i], i > 1 ? ' ' : '\n');
    }
    return 0;
}
