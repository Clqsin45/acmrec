#include <stdio.h>
#define pt 10002
int dfn[pt], low[pt], head[pt], ged[pt];
int rt, n, no, sign;

struct point
{
    int now;    int next;
}p[1000002];

int min(int x, int y)
{
    return x < y ? x : y;
}

void tarjan(int u, int fa)
{
    int i, v, cnt = 0;
    dfn[u] = low[u] = ++no;
    for(i = head[u]; i != -1; i = p[i].next)
    {
        v = p[i].now;

        if(dfn[v] == 0)
        {
            tarjan(v, u);
            ++cnt;
            low[u]=min(low[u],low[v]);
            if((u == rt && cnt > 1) || (u != rt && dfn[u] <= low[v]))
            {
                sign = 1;   ged[u]++;
            }
        }
        else if(v != fa)    low[u] = min(low[u], dfn[v]);
    }
}
int main(void)
{
    int m, i, st1, st2, max, sum;
    while(scanf("%d%d", &n, &m) && (m || n))
    {
        if(m == 0)
        {
            printf("%d\n", n - 1);
            continue;
        }
        for(i = 0; i <= n; i++)
        {
            head[i] = -1;   ged[i] = 0;    dfn[i] = 0;
        }
        no = 0;
        for(i = 1; i <= m; i++)
        {
            scanf("%d%d", &st1, &st2);
            p[++no].next = head[st1];   head[st1] = no;  p[no].now = st2;
            p[++no].next = head[st2];   head[st2] = no;  p[no].now = st1;
        }
        no = 0;     sign = max = 0;
        for(rt = sum = 0; rt < n; rt ++)
        {
            if(!dfn[rt])
            {
                tarjan(rt, -1);
                sum++;
            }
            if(max < ged[rt])   max = ged[rt];
        }
        max += sum;
        printf("%d\n", max);

    }
    return 0;
}
