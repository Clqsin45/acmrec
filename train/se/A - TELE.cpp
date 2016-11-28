#include <stdio.h>
#include <string.h>
#define MAX 3111
#define INF 0x2f7f7f7f
int head[MAX] = {-1}, f[MAX][MAX], no = 0, n;
struct point
{
    int now, cost, next;
}p[MAX << 2];

void add(int x, int y, int z)
{
    p[++no].next = head[x]; head[x] = no;
    p[no].now = y;  p[no].cost = z;
}

inline int findmax(int x, int y)
{
    return x > y ? x : y;
}

int getv(int x)
{
    int ct = 0, i, y;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(head[y] == -1)
        {
            f[y][MAX - 1] = 1;
            ct++;
        }
        else ct += getv(y);
    }
    return f[x][MAX - 1] = ct;
}
void dfs(int x)
{
   // printf("%d\n", x);
    int i, y, fee, j, k, v = 0;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        fee = p[i].cost;
        dfs(y);
        for(j = f[x][MAX - 1]; j >= 0; j--)     //only ones
        {
            for(k = 0; k <= j && k <= f[y][MAX - 1]; k++)
            {
                f[x][j] = findmax(f[x][j], f[x][j - k] + f[y][k] + fee);
               // printf("x = %d,  y = %d, j = %d, f[x][j] = %d\n", x, y, j, f[x][j]);
            }

        }
    }
    return;
}

int main(void)
{
    //freopen("out.txt", "w", stdout);
    int m,to, i, j, co, max = -1, ans, time;
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= n; j++)
        f[i][j] = -INF;
    }

    for(i = 1; i <= n; i++) f[i][0] = f[i][MAX - 1] = 0;
    for(i = 1; i <= n - m; i++)
    {
        scanf("%d", &time);
        for(j = 1; j <= time; j++)
        {
            scanf("%d%d", &to, &co);
            add(i, to, -co);
        }
    }
    for(i = n - m + 1; i <= n; i++)
    {
        scanf("%d", &co);
        f[i][1] = co;
    }

    f[1][MAX - 1] = getv(1);

    dfs(1);
    //for(i = 1; i <= n; i++) printf("!%d\n", f[1][i]);
    for(i = 0; i <= n; i++)
    {
        if(f[1][i] >= 0 && i > max) ans = i;
    }

    printf("%d\n", ans);
    return 0;
}
