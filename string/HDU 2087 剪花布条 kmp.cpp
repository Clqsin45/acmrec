#include <stdio.h>
#include <string.h>
#define MAXN 1004
char w[MAXN], p[MAXN];
int next[MAXN], lenw, lenp, ct;
//ÄÚ¸½¸÷ÖÖBUG
void getnext(void)
{
    int i, j = 0;
    next[1] = 0;
    for(i = 2; i <= lenp; i++)
    {
        while(j > 0 && p[j + 1] != p[i])    j = next[j];
        if(p[j + 1] == p[i])    j++;
        next[i] = j;
    }
    return;
}

void kmp(void)
{
    int j = 0, i;
    for(i = 1; i <= lenw; i++)
    {
        while(j > 0 && p[j + 1] != w[i])   j = next[j];
        if(p [j +1] == w[i])    j++;
        if(j == lenp)
        {
            ct++;
            j = 0;
        }
    }
}
int main(void)
{
    while(scanf("%s", w + 1))
    {
        ct = 0;
        if(strcmp(w+1, "#") == 0)   break;
        scanf("%s", p + 1);
        lenw = strlen(w + 1);
        lenp = strlen(p + 1);
        memset(next, 0, sizeof(next));
        getnext();
        kmp();
        printf("%d\n", ct);
    }
    return 0;
}
