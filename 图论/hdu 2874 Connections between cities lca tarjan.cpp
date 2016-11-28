#include <stdio.h>
#include <string.h>
#define MAX 10005
#define MAXASK 1000006
#define INF 0x3f3f3f3f
struct point
{
    int w, next, now;
}p[MAX * 2], q[MAXASK * 2];
int headp[MAX], headq[MAX], v[MAX], dfn[MAX], ans[MAXASK], dis[MAX];
int n, no;

void add(int x, int y, int z, point *st, int  *s)
{
    st[++no].next = s[x];    s[x] = no;
    st[no].now = y;     st[no].w = z;
}
int find(int x)
{
    if(dfn[x] == x) return x;
    return dfn[x] = find(dfn[x]);
}

void tarjan(int x, int ndis, int pos)
{
    int i, y, w;
    dfn[x] = x; dis[x] = ndis; v[x] = pos;
    for(i = headq[x]; i != -1; i = q[i].next)
    {
        y = q[i].now;   w = q[i].w;
        if(v[y] && v[y] == v[x])
            ans[w] = dis[x] + dis[y] - 2 * dis[find(y)];
    }
    for(i = headp[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;   w = p[i].w;
        if(!v[y])
        {
            tarjan(y, ndis + w, pos);
            dfn[y] = x;
        }
    }
}

int main(void)
{
    int i, st1, st2, stt, pos, m, c;
    while(scanf("%d%d%d", &n, &m, &c)!= EOF)
    {
        pos = 1;    no = 0;
        memset(headp, -1, sizeof(headp));
        memset(headq, -1, sizeof(headq));
        memset(v, 0, sizeof(v));

        for(i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &st1, &st2, &stt);
            add(st1, st2, stt, p, headp);
            add(st2, st1, stt, p, headp);
        }
        no = 0;
        for(i = 1; i <= c; i++)
        {
            scanf("%d%d", &st1, &st2);
            ans[i] = INF;
            add(st1, st2, i, q, headq);
            add(st2, st1, i, q, headq);
        }
        pos = 1;
        for(i = 1; i <= n; i++)
        {
            if(!v[i])
            {
                tarjan(i, 0, pos);
                pos++;
            }
        }
        for(i = 1; i <= c; i++)
        {
            if(ans[i] == INF)   printf("Not connected\n");
            else printf("%d\n", ans[i]);
        }
    }
    return 0;
}
