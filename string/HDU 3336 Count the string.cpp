#include <stdio.h>
#include <string.h>
#define MAXN 200004
char p[MAXN];
int next[MAXN], f[MAXN], len, sum;

void getnext(void)
{
    int j, i;
    j = 0;  next[1] = 0;
    for(i = 2;  i <= len; i++)
    {
        while(j && p[i] != p[j + 1] )   j = next[j];
        if(p[j + 1] == p[i])    j++;
        next[i] = j;
    }
    return;
}
int main(void)
{
    int t, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%s", &len, p + 1);
        memset(next, 0, sizeof(next));
        getnext();
        sum = 0;
        for(i = 1; i <= len; i++)   f[i] = 1;
        f[0] = 0;
        for(i = 1; i <= len; i++)
        {
            printf("%d\n", next[i]);
            f[i] += f[next[i]];
            sum += f[i];
            sum %= 10007;
        }
        printf("%d\n", sum);
    }
    return 0;
}
