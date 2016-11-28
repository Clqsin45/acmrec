#include <stdio.h>
#include <string.h>
#define MAXN 5555
#define MAXE 55555

struct point
{
    int now, next;
}p[MAXE];

int head[MAXN], match[MAXN], no;
bool v[MAXN];

void add(int x, int y)
{
    p[++no].next = head[x]; head[x] = no;
    p[no].now = y;  return;
}

int dfs(int x)
{
    int i, u;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        u = p[i].now;
        if(v[u])    continue;
        v[u] = 1;
        if(match[u] == -1 || dfs(match[u]))
        {
            match[u] = x;
            return 1;
        }
    }
    return 0;
}
int main(void)
{
    int n, m, tc, i, st1, st2, ans;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n);
        m = 3 * n / 2;

        no = 0;
        memset(head, -1, sizeof(head));
        memset(match, -1, sizeof(match));

        while(m--)
        {
            scanf("%d%d", &st1, &st2);
            add(st1, st2);
            add(st2, st1);
        }
        ans = 0;
        for(i = 1; i <= n; i++)
        {
            memset(v, false, sizeof(v));
            ans += dfs(i);
        }
        printf("%d\n", ans / 2);

    }
    return 0;
}
