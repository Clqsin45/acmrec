#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 100004
#define INF 0x3f7f7f7f

char p[MAX], w[MAX * 10];
int next[MAX], lw, lp;

int count()
{
    int ct = 0, i = 0, j = 0;
    while(i < lw)
    {
        if(j == -1 || w[i] == p[j])
        {
            if(j == lp - 1 && w[i] == p[j])
                ct++;
            i++;    j++;
        }
        else j = next[j];
    }
    return ct;
}

void getnext()
{
    int i = 0, j = -1;
    memset(next, 0, sizeof(next));
    next[0] = -1;
    while(i < lp)
    {
        if(j == -1 || p[i] == p[j])
        {
            i ++;   j++;
            if(p[i] != p[j])    next[i] = j;
            else next[i] = next[j];
        }
        else j = next[j];
    }
}
int main(void)
{
    int TC, i;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%s%s", p, w);
        lw = strlen(w); lp = strlen(p);
        getnext();
        printf("%d\n", count());
        //for(i = 0; i <= lp; i++)    printf("%d\n", next[i]);
    }
    return 0;
}
