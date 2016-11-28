#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define MD 1000200
#define MT 1004
#define INF 0x3f7f7f7f

struct point
{
    int u, v, lim, next, cost;
}p[MD<<2];

int no, head[MT], d[MT], c[MT], s, e, n;
bool v[MT];

void init(void)
{
    memset(head, -1, sizeof(head));
    no = 0; return;
}

void add(int x, int y, int ct, int z)
{
    p[no].u = x;    p[no].v = y;    p[no].lim = z;
    p[no].cost = ct;    p[no].next = head[x];   head[x] = no++;
    p[no].u = y;    p[no].v = x;    p[no].lim = 0;
    p[no].cost = -ct;     p[no].next = head[y];   head[y] = no++;
//    if(x == 1)  printf("%d\n", no);
}

bool spfa()
{
    int i, x, y;
    queue<int>q;
    memset(v, false, sizeof(v));
    memset(c, -1, sizeof(c));

    for(i = 0; i <= e; i++) d[i] = INF;
    v[s] = true;    d[s] = 0;
    q.push(s);

    while(!q.empty())
    {
        x = q.front();  q.pop();    v[x] = false;
//        printf("%d\n", x);
//        system("pause");
        for(i = head[x]; i != -1; i = p[i].next)
        {
            //printf("!\n");

            y = p[i].v;
//            printf("%d %d\n",i, y);
//            system("pause");
            if(p[i].lim > 0 && d[y] > d[x] + p[i].cost)
            {
                d[y] = d[x] + p[i].cost;
                c[y] = i;
                if(!v[y])
                {
                    q.push(y);
                    v[y] = true;
                }
            }
        }
    }
    if(d[e] == INF) return false;
    return true;
}

int mcmfs()
{
    int maxflow = 0, i, minflow, mincost;
    mincost = 0;
    while(spfa())
    {
        //printf("!!!\n");
        minflow = INF + 1;
        for(i = c[e]; i != -1; i = c[p[i].u])
            if(p[i].lim < minflow)
                minflow = p[i].lim;
        maxflow += minflow;

        for(i = c[e]; i != -1; i = c[p[i].u])
        {
            p[i].lim -= minflow;
            p[i^1].lim += minflow;
        }
        mincost += d[e]*minflow;
//        printf("%d\n", mincost);
    }
    //sumflow = maxflow;
    return mincost;
}

int main(void)
{
    int m, i, j, ans, x, y, z;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        s = 0;  e = n;
        init();
        while(m--)
        {
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z, 1);
            add(y, x, z, 1);
        }
        add(s, 1, 0 ,2);
        ans = mcmfs();
        printf("%d\n", ans);
    }
    return 0;
}
