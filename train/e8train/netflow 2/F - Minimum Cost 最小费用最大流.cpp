#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 110
#define INF 0x3f7f7f7f

int e, ans;
int lim[MAX][MAX], p[MAX], cost[MAX][MAX], d[MAX];
int g[MAX][MAX], need[MAX][MAX], gt[MAX], nt[MAX];
bool v[MAX];

bool spfa()
{
    queue<int>q;
    int i, x, y;
    for(i = 0 ; i <= e; i++)
    {
        d[i] = INF; v[i] = false;
    }
    d[0] = 0;   q.push(0);
    v[0] = true;
    while(!q.empty())
    {
        x = q.front();    q.pop();
        v[x] =  false;
        for(i = 0 ; i <= e; i++)
        {
            if(lim[x][i] && d[i] > d[x] + cost[x][i])
            {
                d[i] = d[x] + cost[x][i];
                p[i] = x;
                if(!v[i])
                {
                    q.push(i);
                    v[i] = true;
                }
            }
        }
    }
    if(d[e] == INF) return 0;
    else return 1;
}
int mfmc()
{
    int minflow, mincost = 0, maxflow = 0, i;
    while(spfa())
    {
        minflow = INF;
        for(i = e; i != 0; i = p[i])
        {
            minflow = min(minflow, lim[p[i]][i]);
        }
        maxflow += minflow;
        for(i = e; i != 0; i = p[i])
        {
            lim[p[i]][i] -= minflow;
            lim[i][p[i]] += minflow;
        }
        mincost += d[e] * minflow;
    }
    return mincost;
}
int main(void)
{
    int n, m, t, i, j, k;
    while(scanf("%d%d%d", &n, &m, &t) && (n || m || t))
    {
        memset(nt, 0, sizeof(nt));
        memset(gt, 0, sizeof(gt));
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= t; j++)
            {
                scanf("%d", &need[i][j]);
                nt[j] += need[i][j];
            }
        }
        for(i = 1; i <= m; i++)
        {
            for(j = 1; j <= t; j++)
            {
                scanf("%d", &g[i][j]);
                gt[j] += g[i][j];
            }
        }

        bool flag = true;
        for(i = 1; i <= t; i++)
        {
            if(nt[i] > gt[i])
            {
                flag = false;   break;
            }
        }
        ans = 0;

        e = n + m + 1;
        for(k = 1; k <= t; k++)
        {
            memset(lim, 0, sizeof(lim));
            for(i = 1; i <= n; i++)
            {
                for(j = 1; j <= m; j++)
                {
                    scanf("%d", &cost[j][i + m]);
                    cost[i + m][j] = -cost[j][i + m];
                    lim[j][i + m]  = INF;
                }
            }
            for(i = 1; i <= m; i++)
            {
                cost[0][i] = cost[i][0] = 0;
                lim[0][i] = g[i][k];
            }
            for(i = 1; i <= n; i++)
            {
                cost[i + m][e] = cost[e][i + m] = 0;
                lim[i + m][e] = need[i][k];
            }
            ans += mfmc();
        }
        if(flag)    printf("%d\n", ans);
        else printf("-1\n");
    }
    return 0;
}
