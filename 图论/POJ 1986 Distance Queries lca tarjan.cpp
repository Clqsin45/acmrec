#include <stdio.h>
#include <string.h>
#define MAX 100100
struct point
{
    int now, next, w;
}p[MAX *2], q[MAX * 2];
int headp[MAX], v[MAX], headq[MAX], dfn[MAX], ans[MAX], dis[MAX];
int n, m, no;

void add(int x, int y , int z, int *s, point *str)
{
    str[++no].next = s[x];
    s[x] = no;
    str[no].now = y;
    str[no].w = z;
}
int find(int x)             //寻找根节点同时压缩路径
{
    if(dfn[x] == x)    return x;
    else return dfn[x] = find(dfn[x]);
}
void tarjan(int x, int ndis)
{
    int i, y, w;
    dfn[x] = x;
    dis[x] = ndis;
    v[x] = 1;
    for(i = headq[x]; i != -1; i = q[i].next)
    {
        y = q[i].now;   w = q[i].w;
        if(v[y])
        {
            ans[w] = dis[x] + dis[y] - 2 * dis[find(y)];      //q里存储的是i,即ans[w]就是该点的距离 同时，当y未被走过就不更新，到y的时候x已更新，于是更新答案
                                                              //dis数组里存的是从根到i的距离，所以两点的距离即为他们到根的距离减去他们共同的祖先到根的距离的两倍
        }
    }
    for(i = headp[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;   w = p[i].w;
        if(!v[y])
        {
            tarjan(y, ndis + w);                              //找x的子节点，并更新子节点到根节点的距离
            dfn[y] = x;
        }
    }
}
int main(void)
{
    int st1, st2, stt, st, i;
    char b;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(headp, -1, sizeof(headp));
        memset(headq, -1, sizeof(headq));
        memset(v, 0, sizeof(0));
        memset(dfn, -1, sizeof(dfn));
        no = 0;

        for(i = 1; i  <= m; i++)
        {
            scanf("%d%d%d %c", &st1, &st2, &stt, &b);
            add(st1, st2, stt, headp, p);
            add(st2, st1, stt, headp, p);
        }
        scanf("%d", &st);   no = 0;
        for(i = 1; i <= st; i++)
        {
            scanf("%d%d", &st1, &st2);
            add(st1, st2, i, headq, q);
            add(st2, st1, i, headq, q);
        }
        tarjan(1, 0);
        for(i = 1; i <= st; i++)    printf("%d\n", ans[i]);
    }
    return 0;
}
