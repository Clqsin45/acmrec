#include <stdio.h>

struct point
{
    int now;    int next;
}p[2002];
int dfn[1002], low[1002], head[1002], v[2002];
int no,n,m;

void add(int x, int y)
{
    v[no] = 0;
    p[no].next = head[x];   p[no].now = y;  head[x] = no++;
    v[no] = 0;
    p[no].next = head[y];   p[no].now = x;  head[y] = no++;
}

int min(int x, int y)
{
    return x < y ? x : y;
}

void tarjan(int u)
{
    int t, i;
    dfn[u] = low[u] = ++no;
    for(i = head[u]; i != -1; i = p[i].next)
    {
        if(v[i])    continue;
        v[i] = v[i ^ 1] = 1;
        t = p[i].now;
        if(!dfn[t])
        {
            tarjan(t);
            low[u] = min(low[u], low[t]);
        }
        else low[u] = min(low[u], dfn[t]);
    }
}
int main(void)
{
    int st1, st2, i , j;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        no = 0;
        for(i = 1; i <= n; i++) head[i] = -1;
        while(m--)
        {
            scanf("%d%d", &st1, &st2);
            add(st1, st2);
        }

        for(i = 1; i <= n; i++) dfn[i] = 0;
        no = 0;    tarjan(1);
        for(i = 1; i <= n; i++) dfn[i] = 0;
        for(i = 1; i <= n; i++)
        {
            for(j = head[i]; j != -1; j = p[j].next)
            {
                if(low[i] != low[p[j].now])  ++dfn[low[i]];
            }
        }
        m = 0;
        for(i = 1; i <= n; i++)
            m += (dfn[i] == 1);
        printf("%d\n", (m + 1) / 2);
    }


    return 0;
}
