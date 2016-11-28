#include <stdio.h>
#include <string.h>
#define MAX  40004
struct point
{
    int now, next, cost;
}p[MAX << 1];
int head[MAX], f[MAX], no = 0, ans = 0;

void add(int x, int y, int z)
{
    p[++no].next = head[x];
    head[x] = no;
    p[no].now = y;  p[no].cost = z;
}

inline int findmax(int x, int y)
{
    return x > y ? x : y;
}
void dfs(int x, int fa)
{
    int i, y, zwai = 0;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(y == fa) continue;
        dfs(y, x);
        if(f[y] + p[i].cost >= f[x])
        {
            zwai = f[x];
            f[x] = f[y] + p[i].cost;
        }
        else if(f[y] + p[i].cost > zwai)
        {
            zwai = f[y] + p[i].cost;
        }
    }
    ans = findmax(f[x] + zwai, ans);
}

int main(void)
{
    int n, m, i, st1, st2, stt;
    char gb;
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    memset(f, 0, sizeof(f));

    while(m--)
    {
        scanf("%d%d%d %c", &st1, &st2, &stt, &gb);
        add(st1, st2, stt);
        add(st2, st1, stt);
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}
