#include <stdio.h>

int dfn[102], low[102], head[102], ged[102];
int top, ct, rt, no, n;
struct point
{
    int now;    int next;
}p[10002];

int min(int x, int y)
{
    return x < y ? x : y;
}

void tarjan(int u, int fa)
{
    int i, v, cnt = 0, ans;
    dfn[u] = low[u] = ++no;
    for(i = head[u]; i != -1; i = p[i].next)
    {
        v = p[i].now;
        if(dfn[v] == 0)
        {
            tarjan(v, u);
            ++cnt;
            low[u] = min(low[u], low[v]);
            if((u == rt && cnt > 1) || (u != rt && dfn[u] <= low[v]))
            {
                 ged[u] = 1;
            }
        }
        else if(v != fa)    low[u] = min(low[u] , dfn[v]);
    }
}

int main(void)
{
    int st, i, ans;
    char op;
    while(scanf("%d", &n) && n)
    {

        for(no = 0, i = 0; i <= n; i++)
        {
            head[i] = -1;  dfn[i] = 0;     ged[i] = 0;
        }

        while(scanf("%d", &i) && i)
        {
            while(getchar()!='\n')
            {
                scanf("%d", &st);
                p[++no].next = head[i];     head[i] = no;   p[no].now =  st;
                p[++no].next = head[st];    head[st] = no;  p[no].now = i;
            }
        }
        top = no = 0;
        for(rt = 1; rt <= n; rt++)
            if(!dfn[rt])     tarjan(rt, 0);
        for(i = 1, ans = 0; i <= n; i++)
            ans += ged[i];
        printf("%d\n", ans);

    }
    return 0;
}
