#include <stdio.h>
#include <string.h>
#define MAXN 10004
char p[MAXN], w[MAXN * 100];
int next[MAXN], lenp, lenw, ct;

void getnext(void)
{
    int j = 0, i;
    next[1] = 0;
    for(i = 2; i <= lenp; i++)
    {
        while(j > 0 && p[j + 1] != p[i])    j = next[j];
        if(p[j + 1] == p[i])    j ++;
        next[i] = j;
    }
}

void kmp(void)
{
    int i, j = 0;
    for(i = 1; i <= lenw; i++)
    {
        while(j  > 0 && w[i] != p[j + 1])   j = next[j];
        if(p[j + 1] == w[i])    j++;
        if(j == lenp)
        {
            ct++;
            j = next[j];        //这里这里！
        }
    }
}
int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ct = 0;
        scanf("%s %s", p + 1, w + 1);
        memset(next, 0, sizeof(next));
        lenp = strlen(p + 1);
        lenw = strlen(w + 1);
        getnext();
        kmp();
        printf("%d\n", ct);
    }
    return 0;
}
