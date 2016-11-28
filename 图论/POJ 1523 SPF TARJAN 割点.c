#include <stdio.h>
#include <string.h>
struct point
{
    int now;    int next;
}p[1000002];

int dfn[1002], low[1002], head[1002], ged[1002], ex[1002];
int ct, rt, top, n, no, sign;

int min(int x, int y)
{
    return  x < y ? x : y;
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
            ++cnt;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if((u == rt && cnt > 1) || (u != rt && dfn[u] <= low[v]))
            {

                ged[u]++;   sign = 1;                                                     //求是否有割点时  1 求割除后连通分量，++
            }
        }
        else if(v != fa) low[u] = min(low[u], dfn[v]);
    }
    return;
}

int main(void)
{
    int st1, st2, i;
    ct = 0;
    while(scanf("%d", &st1) && st1)
    {
        ct++;
        memset(head, -1, sizeof(head));
        memset(dfn, 0, sizeof(dfn));
        memset(ged, 0, sizeof(dfn));
        no = 0; n = 0;

        scanf("%d", &st2);
        if(st1 > n) n = st1;
        if(st2 > n) n = st2;
        p[++no].next = head[st2];   head[st2] = no;   p[no].now = st1;
        p[++no].next = head[st1];   head[st1] = no;   p[no].now = st2;

        while(scanf("%d", &st1) && st1)
        {
            scanf("%d", &st2);
            if(st1 > n) n = st1;
            if(st2 > n) n = st2;
            ex[st1] = 1;    ex[st2] = 1;

            p[++no].next = head[st2];   head[st2] = no;   p[no].now = st1;
            p[++no].next = head[st1];   head[st1] = no;   p[no].now = st2;
        }

        no = 0;   sign = 0;

        for(rt = 1; rt <= n; rt++)
        {
            if(dfn[rt] == 0 && ex[rt])    tarjan(rt, -1);
        }
        printf("Network #%d\n", ct);
        if(sign)
        {
            for(i = 1; i <= n; i++)
            {
                if(ged[i] && ex[i])     printf("  SPF node %d leaves %d subnets\n", i, ged[i] + 1);
            }
        }
        else printf("  No SPF nodes\n");
        printf("\n");

    }
    return 0;
}
