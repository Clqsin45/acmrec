#include <stdio.h>
#include <string.h>
#define MAXN 400004
char p[MAXN];
int next[MAXN], ans[MAXN], len, sum;

void getnext(void)
{
    int i = 0, j = -1;
    next[0] = -1;
    while(i < len)
    {
        if(j == -1 || p[i] == p[j])
        {
            i++;    j++;
           // if(p[i] != p[j])
                next[i] = j;
           //else next[i] = next[j];
        }
        else
            j = next[j];
    }
}
int main(void)
{
    int i;
    while(scanf("%s", p) != EOF)
    {
        sum = 0;
        len = strlen(p);

        memset(next, 0, sizeof(next));
        getnext();
        for(i = len; i > 0; i = next[i])
        {
            ans[++sum] = i;
        }
		for(i = sum; i >= 1; i--)   printf("%d%c", ans[i], i>1?' ' :'\n');

    }
    return 0;
}
