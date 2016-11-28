#include <stdio.h>
#include <string.h>
#define MAX 40004
struct point
{
    int next, now, w;
}p[2 * MAX], q[2 * MAX];
int v[MAX], headp[MAX], headq[MAX], ans[222], dis[MAX], dfn[MAX];
int no, n;

void add(int x, int y, int z, point *st, int *s)
{
    st[++no].next = s[x];
    s[x] = no;
    st[no].w = z;   st[no].now = y;
}

int find(int x)
{
    if (x == dfn[x])    return x;
    else return dfn[x] = find(dfn[x]);
}

void tarjan(int x, int ndis)
{
    int i, y, w;
    v[x] = 1;
    dfn[x] = x; dis[x] = ndis;
    for(i = headq[x]; i != -1; i = q[i].next)
    {
        y = q[i].now;   w = q[i].w;
        if(v[y])
        {
            ans[w] = dis[x] + dis[y] - 2 * dis[find(y)];
        }
    }
    for(i = headp[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;   w = p[i].w;
        if(!v[y])
        {
            tarjan(y, ndis + w);
            dfn[y] = x;
        }
    }
}
int main(void)
{
    int t, i, st1, st2, stt, m;
    scanf("%d", &t);
    while(t--)
    {
        memset(headp, -1, sizeof(headp));
        memset(headq, -1, sizeof(headq));
        memset(v, 0, sizeof(v));

        scanf("%d%d", &n, &m);
        no = 0;
        for(i = 1; i < n; i++)
        {
            scanf("%d%d%d", &st1, &st2, &stt);
            add(st1, st2, stt, p, headp);
            add(st2, st1, stt, p, headp);
        }
        no = 0;
        for(i = 1; i <= m; i++)
        {
            scanf("%d%d", &st1, &st2);
            add(st1, st2, i, q, headq);
            add(st2, st1, i, q, headq);
        }
        tarjan(1, 0);
        for(i = 1; i <= m; i++)
        {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
