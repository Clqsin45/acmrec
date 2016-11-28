#include <stdio.h>
#include <string.h>
int next[10004], lenp, lenw, p[10004], w[1000000];

void getnext(void)
{
    memset(next, 0, sizeof(next));
    int i = 0, j = -1;
    next[0] = -1;
    while(i < lenp)
    {
        if(j == -1 || p[j] == p[i])
        {
            i++;    j++;
            if(p[i]!=p[j])  next[i] = j;
            else next[i] = next[j];
        }
        else j = next[j];
    }
}

int kmp(void)
{
    int i = 0, j = 0;
    while(i < lenw && j < lenp)
    {
        if(j == -1 || w[i] == p[j])
        {
            i++;    j++;
        }
        else j = next[j];
    }
    if(j == lenp)   return i - j + 1;
    else return -1;
}
int main(void)
{
    int t, i;
    scanf("%d" ,&t);
    while(t--)
    {
        scanf("%d%d", &lenw, &lenp);
        for(i = 0; i < lenw; i++)   scanf("%d", &w[i]);
        for(i = 0; i < lenp; i++)   scanf("%d", &p[i]);
        getnext();

        printf("%d\n", kmp());
    }
    return 0;
}
