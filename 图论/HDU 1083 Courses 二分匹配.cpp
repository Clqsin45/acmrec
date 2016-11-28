#include <stdio.h>
#include <string.h>

int f[111][333], v[333], match[333];
int p, n;

int dfs(int x)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        if(f[x][i] && !v[i])
        {
            v[i] = 1;
            if(match[i] == -1 || dfs(match[i]))
            {
                match[i] = x;
                return 1;
            }
        }
    }
    return 0;
}
int main(void)
{
    int t, i, j, ct, st, ans;
    bool flag = true;
    scanf("%d", &t);
    while(t--)
    {
        ans = 0;    flag = true;
        memset(match, -1, sizeof(match));
        memset(f, 0, sizeof(f));

        scanf("%d%d", &p, &n);

        for(i = 1; i <= p; i++)
        {
            scanf("%d", &ct);
            while(ct--)
            {
                scanf("%d", &st);
                f[i][st] = 1;
            }
        }

        for(i = 1; i <= p; i++)
        {
            memset(v, 0, sizeof(v));
            if(!dfs(i))
            {
                flag = false;
                break;
            }
        }
        if(flag)    printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
