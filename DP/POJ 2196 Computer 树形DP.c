#include <stdio.h>
#include <string.h>
#define MAX 10002
struct point
{
    int next;   int now;    int v;
}p[4*MAX];
int head[MAX], n, no = 0;
int maxn[MAX], dmaxn[MAX], maxid[MAX], dmaxid[MAX];

void add(int x, int y, int z)
{
    p[++no].next = head[x]; head[x] = no;
    p[no].now = y;  p[no].v = z;
    return;
}

void dfson(int u, int fa)
{
    int i, temp, v;
    maxn[u] = 0;    dmaxn[u] = 0;
    for(i = head[u]; i != -1; i = p[i].next)
    {
        v = p[i].now;
        if(v == fa) continue;
        dfson(v, u);
        if(dmaxn[u] < maxn[v] + p[i].v)
        {
            dmaxn[u] = maxn[v] + p[i].v;
            dmaxid[u] = v;
            if(dmaxn[u] > maxn[u])
            {
                temp = dmaxn[u];    dmaxn[u] = maxn[u]; maxn[u] = temp;
                temp = dmaxid[u];    dmaxid[u] = maxid[u]; maxid[u] = temp;
            }

        }

    }
}

void dfsfa(int u, int fa)
{
    int i, v, temp;
    for(i = head[u] ; i != -1; i = p[i].next)
    {
        v = p[i].now;
        if(v == fa) continue;
        if(v == maxid[u])
        {
            if(dmaxn[v] < dmaxn[u] + p[i].v)
            {
                dmaxn[v] = dmaxn[u] + p[i].v;
                dmaxid[v] = u;
            }
            if(dmaxn[v] > maxn[v])
            {
                temp = dmaxn[v];    dmaxn[v] = maxn[v]; maxn[v] = temp;
                temp = dmaxid[v];    dmaxid[v] = maxid[v]; maxid[v] = temp;
            }
        }
        else
        {
            if(dmaxn[v] < maxn[u] + p[i].v)
            {
                dmaxn[v] = maxn[u] + p[i].v;
                dmaxid[v] = u;
            }
            if(dmaxn[v] > maxn[v])
            {
                temp = dmaxn[v];    dmaxn[v] = maxn[v]; maxn[v] = temp;
                temp = dmaxid[v];    dmaxid[v] = maxid[v]; maxid[v] = temp;
            }
        }
        dfsfa(v, u);
    }

}
int main(void)
{
    int i, st1, stt;
    while(scanf("%d", &n) != EOF)
    {
        memset(head, -1, sizeof(head));
        no = 0;
        for(i = 2; i <= n; i++)
        {
            scanf("%d%d", &st1, &stt);
            add(i, st1, stt);
            add(st1, i, stt);
        }
        dfson(1, -1);
        dfsfa(1, -1);
        for(i = 1; i <= n; i ++)    printf("%d\n", maxn[i]);
    }
    return 0;
}
