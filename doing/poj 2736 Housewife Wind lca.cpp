#include <stdio.h>
#define MAX 100006
struct point
{
    int now, next, w;
}p[ MAX << 1];
int head[MAX] = {-1}, f[MAX], level[MAX], fv[MAX], lv[MAX], dis[MAX], max[MAX << 1][22];
//邻接表              记录欧拉  层      firstvisit lastvist distance
int no = 0, time = 0;

void dfs(int u, int w, int d)
{
    f[++time] = u;
    level[time] = d;    fv[u] = time;
    dis[u] = w;
    for(i = head[u]; i != -1; i = p[i].next)
    {
        int v = p[i].now;
        if(!fv[v])
        {
            dfs(v, w + g[i].w, d + 1);
            f[++time] = u;
            level[time] = d;
        }
    }
    lv[u] = time;
}
void add(int x, int y, int z)
{
    p[++no].now = head[x];  head[x] = no;
    p[no].next = y; p[no].w = z;
}
int main(void)
{
    int n, q, s, i;
    scanf("%d%d%d",&n, &q, &s);
    memset(head, -1, sizeof(head));
    memset(fv, 0, sizeof(fv));
    for(i = 1; i < n; i++)
    {
        scanf("%d%d%d", &st1, &st2, &stt);
        add(st1, st2, stt);
        add(st2, st1 ,stt);
    }
    dfs(s, 0, 0);
    for(i = 0; i <= time; i++)  max[i][0] = i;
    for(j = 1; (1 << j) <= time; j++)
    {
        for(i = 1; (1 << j) + i - 1 <= time; i++)
        {
            max [i][j] = level[max[i][j - 1]] < level[max[(1 << j) + i - 1][j - 1]] ? max[i][j - 1] : max[(1 << j) + i - 1][j - 1];
        }
    }
    while(q--)
    {
        scanf("%d", &op);
        if(op)
        {
            scanf("%d%d", &st1, &st2);
        }
    }

    return 0;
}
