#include <stdio.h>
#include <string.h>
#define MAX 6004
int f[MAX][2], rate[MAX], head[MAX], v[MAX];
struct point
{
    int now;    int next;
}p[MAX * 4];
int no, n, ans;

void add(int x, int y)
{
    p[++no].next = head[x]; head[x] = no;
    p[no].now = y;
    return;
}

void dfs(int x)
{
    int i, y, max = 0, st;
    if(v[x])   return;
    v[x] = 1;
    for(i = head[x]; i != -1; i = p[i].next)
    {

        y = p[i].now;   max = 0;
        if(v[x])   dfs(y);
        f[x][1] += f[y][0];
        max = (f[y][1] > f[y][0] ? f[y][1] : f[y][0]);
        f[x][0] += max;
    }

    st = (f[x][1] > f[x][0] ? f[x][1] : f[x][0]);
    if(ans < st)
        ans = st;
    return;
}
int main(void)
{
    int i, st1, st2;
    while(scanf("%d", &n) != EOF)
    {
        no = 0; ans = 0;
        memset(head, -1, sizeof(head));
        memset(v, 0, sizeof(v));
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &rate[i]);
            f[i][0] = 0;
            f[i][1] = rate[i];
        }

        while(scanf("%d%d", &st1, &st2) && (st1 || st2))
        {
            add(st2, st1);
        }

        for(i = 1; i <= n; i++)
        {
            dfs(i);
        }
        printf("%d\n", ans);
    }
    return 0;
}
