#include <stdio.h>
#include <string.h>

#define MAXD 111
#define MAXN 11111
int f[MAXD][MAXD], match[MAXD], a[MAXN], b[MAXN];
bool v[MAXD], n, m, k;

int dfs(int x)
{
    int i;
    for(i = 1; i <= m; i++)
    {
        if(!v[i] && f[x][i])
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

int getmax()
{
    int ans, i;
    ans = 0;
    for(i = 1; i <= n; i++)
    {
        memset(v, 0, sizeof(v));
        ans += dfs(i);
    }
    return ans;
}
int main(void)
{
    int i, ans, ct, t, nc = 1;
    while(scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        memset(f, 0, sizeof(f));
        memset(match, -1, sizeof(match));
        for(i = 1; i <= k; i++)
        {
            scanf("%d%d", &a[i], &b[i]);
            f[ a[i] ][ b[i] ] = 1;
        }
        ans = getmax();
        ct = 0;
        for(i = 1; i <= k; i++)
        {
            memset(match, -1, sizeof(match));
            f[ a[i] ][ b[i] ] = 0;
            t = getmax();
            if(t != ans)    ct++;
            f[ a[i] ][ b[i] ] = 1;
        }
        printf("Board %d have %d important blanks for %d chessmen.\n", nc++, ct, ans);
    }
    return 0;
}
