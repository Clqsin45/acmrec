#include <stdio.h>
#include <string.h>
#define MAX 111
int f[MAX][MAX], match[MAX], x, y;
bool v[MAX];

int dfs(int p)
{
    int i;
    for(i = 1; i <= y; i++)
    {
        if(f[p][i] && !v[i])
        {
            v[i] = 1;
            if(match[i] == -1 || dfs(match[i]))
            {
                match[i] = p;
                return 1;
            }
        }
    }
    return 0;
}

int main(void)
{
    int i, stt, st1, st2, k, ans;
    while(scanf("%d", &x) && x)
    {
        memset(f, 0, sizeof(f));
        memset(match, -1, sizeof(match));
        scanf("%d%d", &y, &k);
        while(k--)
        {
            scanf("%d%d%d", &stt,&st1, &st2);
            f[st1][st2] = 1;
        }
        ans = 0;
        for(i = 1; i <= x; i++)
        {
            memset(v, 0, sizeof(v));
            ans += dfs(i);
        }
        printf("%d\n", ans);
    }
    return 0;
}
