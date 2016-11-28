#include <stdio.h>
#include <string.h>
#define MAXN 1000004
char p[MAXN];
int next[MAXN], len;
void getnext(void)
{
    int i = 0, j = -1;
    next[0] = -1;
    while(i < len)
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
    int i, st, ct = 1;
    while(scanf("%d", &len) && len)
    {
        scanf("%s", p);
        memset(next, 0, sizeof(next));
        getnext();
        printf("Test case #%d\n", ct++);
        for(i = 1; i <= len; i++)
        {
            st = i - next[i];
            if(next[i] != 0 && i % st == 0)    printf("%d %d\n", i, i / st);
        }
        printf("\n");
    }
    return 0;
}
