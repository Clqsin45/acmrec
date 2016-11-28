#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 20010
#define INF 0x3f7f7f7f
struct point
{
    int u, v, lim, next;
}p[1800000];
int head[MAX], cur[MAX], par[MAX], d[MAX], ct[MAX], agt[MAX];
int s, e, no;

void add(int x, int y, int z)
{
    p[no].u = x;    p[no].v = y;
    p[no].lim = z;  p[no].next = head[x];   head[x] = no++;
}

int sap(void)
{
    int maxflow = 0, x, y, mind, aug, i;
    memset(d, 0, sizeof(d));
    memset(ct, 0, sizeof(ct));

    for(i = 0 ; i <= e ;i++)
        cur[i] = head[i];
    agt[0] = INF;   par[0] = -1;
    x = 0;

    while(d[0] <= e)
    {
        //printf("%d\n", x);
        //'system("pause");
        if(x == e)
        {
            maxflow += agt[e];
            aug = agt[e];
            for(y = par[e]; y != -1; y = par[y])
            {
                i = cur[y];
                p[i].lim -= aug;
                p[i^1].lim += aug;
                agt[p[i].v] -= aug;
                if(p[i].lim == 0)   x = y;
            }
        }

        for(i = cur[x]; i != -1; i = p[i].next)
        {
            y = p[i].v; //printf("y = %d\n", y);
            if(p[i].lim > 0 && d[x] == d[y] + 1)
            {
                agt[y] = min(agt[x], p[i].lim);
                cur[x] = i;
                par[y] = x;
                x = y;
                //printf("!%d\n", x);
                break;
            }
        }
        if(i == -1)
        {
            if(--ct[d[x]] == 0)  break;

            cur[x] = head[x];
            mind = e + 1;
            for(i = head[x]; i != -1; i = p[i].next)
            {
                if(p[i].lim > 0)    mind = min(mind, d[p[i].v]);
            }
            d[x] = mind + 1;
            ct[d[x]] ++;
            if(x != 0)  x = par[x];
        }
    }
    return maxflow;
}
int main(void)
{
    int m, x, y, z, i, j, n;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(head, -1, sizeof(head));
        no = 0;
        e = n + 1;
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d", &x, &y);
            add(0, i, x);   add(i, 0, 0);
            add(i, e, y);   add(e, i, 0);
        }
        while(m--)
        {
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z);   add(y, x, z);
        }
        int ans = sap();
        printf("%d\n", ans);
    }
    return 0;
}
