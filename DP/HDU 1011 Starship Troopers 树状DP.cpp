#include <stdio.h>
#include <string.h>

struct point
{
    int next; int now;
}p[404];
int head[104],  v[104], visit[104], m, n, bug[104], no, f[102][102];

void add(int x, int y)
{
    p[++no].next = head[x]; head[x] = no;
    p[no].now = y;  return;
}

int max(int x, int y)
{
    return x > y ? x : y;
}
void dfs(int x)
{
    visit[x] = 1;
    int need = (bug[x] + 19) / 20, i, j, y, k;
    for(i = need; i <= m; i++)
    {
        f[x][i] = v[x];
    }
    for(i = head[x]; i != -1; i = p[i].next)
    {

        y = p[i].now;
        if(visit[y])    continue;
        dfs(y);
        for(j = m; j >= need; j--)
        {
            for(k = j + 1; k <= m; k++)
            {
                f[x][k] = max (f[x][k], f[x][j] + f[y][k - j]);
            }
        }
    }

}
int main(void)
{
    int i, st1, st2, j;
    while(scanf("%d%d", &n, &m))
    {
        if(n == -1 && m == -1)  break;
        no = 0;
        memset(head, -1, sizeof(head));
        memset(visit, 0, sizeof(visit));
        memset(f, 0, sizeof(f));
        for(i = 1; i <= n; i++)
            scanf("%d%d", &bug[i], &v[i]);
        for(i = 1; i < n; i++)
        {
            scanf("%d%d", &st1, &st2);

            add(st1, st2);
            add(st2, st1);
        }

        if(m == 0)
        {
            printf("0\n");
            continue;
        }
        dfs(1);
        printf("%d\n", f[1][m]);
    }
    return 0;
}
