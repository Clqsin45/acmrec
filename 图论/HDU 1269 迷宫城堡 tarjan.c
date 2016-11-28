#include <stdio.h>
#include <string.h>
#define INF 10004
int v[INF], s[INF], low[INF], dfn[INF], head[INF];
int ct, no, top, m, n;
struct line
{
    int now;  int next;
}p[100004];
int min(int x, int y)
{
    return x < y ? x : y;
}
void tarjan(int x)
{
    int i, j;
    dfn[x] = low[x] = ++no;
    s[++top] = x;   v[x] = 1;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        j = p[i].now;
        if(dfn[j] == 0)
        {
            tarjan(j);
            low[x] = min(low[x],low[j]);
        }
        else if(v[j])
        {
            low[x] = min(low[x], dfn[j]);
        }
    }
    if(dfn[x] == low[x])
    {
        while(top >= 1 && s[top] != x)
        {
            v[s[top]] = 0;
            top--;
        }
        ct++;
    }
}
int main(void)
{
    int i, st1, st2;
    while(scanf("%d%d", &n, &m) && (n || m))
    {
        memset(head, -1, sizeof(head));
        for(i = 1; i <= m; i++)
        {
            scanf("%d%d", &st1, &st2);
            p[i].now = st2;
            p[i].next = head[st1];
            head[st1] = i;
        }
        memset(dfn, 0, sizeof(dfn));
        memset(v, 0, sizeof(v));
        no = 0; ct = 0; top = 0;
        for(i = 1;  i <= n; i++)
        {
            if(dfn[i] == 0)   tarjan(i);
        }

        if(ct == 1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
