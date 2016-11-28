#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
/*************
每次都要重新建图。。。
********************/
#define MT 240
#define MD 240000
#define INF 0x3f7f7f7f

int m[MT][MT], f[MT][MT], d[MT],s, e, k, c, t;
int q[MD * 10];

void init()
{
    s = 0;
    memset(m, 0, sizeof(m));
    return;
}

void floyd(int n)
{
    int i, j, k;
    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(f[i][j] > f[i][k] + f[k][j])
                    f[i][j] = f[i][k] + f[k][j];
            }
        }
    }
}

void build(int mid)
{
    int i, j;
    memset(m, 0, sizeof(m));
    for(i = 1; i <= k; i++)
        m[0][i] = t;
    for(i = k + 1; i < e; i++)
        m[i][e] = 1;

    for(i = 1; i <= k; i++)
    {
        for(j = k + 1; j < e; j++)
        {
            if(f[i][j] <= mid)  m[i][j] = 1;
            else m[i][j] = 0;
            //printf("%d ",  m[i][j]);
        }
        //printf("\n");
    }
}


bool bfs()
{
    memset(d, -1, sizeof(d));
    int f, r, i, x, y;
    f = r = 0;
    d[s] = 0;   q[r++] = s;
    while(f < r)
    {
        x = q[f++]; //printf("~~~%d\n", x);
        for(i = 0; i <= e; i++)
        {
            //printf("m[%d][%d] = %d\n", x, i, m[x][i]);
            if(m[x][i] > 0 && d[i] == -1)
            {
                d[i] = d[x] + 1;
                q[r++] = i;
                if(i == e)  return true;
            }
        }
    }
    return false;
}


int dinic(int x, int sum)
{
    int i, nowflow, flow = 0;
    if(x == e)  return sum;

    for(i = 0; i <= e; i++)
    {
        if(sum&& m[x][i] > 0 && d[i] == d[x] + 1 )
        {
            nowflow = dinic(i, min(sum, m[x][i]));
            m[x][i] -= nowflow;
            m[i][x] += nowflow;
            sum -= nowflow;
            flow += nowflow;
        }
    }
    return flow;
}

int main(void)
{
    int  i, j, high, low, mid,ans = 0;
    init();
    scanf("%d%d%d", &k, &c, &t);
    e = k + c + 1;
    for(i = 1; i < e; i++)
        for(j = 1; j < e; j++)
        {
            scanf("%d", &f[i][j]);
            if(f[i][j] == 0)    f[i][j] = INF;
        }

    floyd(e - 1);


    high =22222; low = 0;
    while(low <= high)
    {
        mid = (high + low) >> 1;
        build(mid);

        //printf("_________________\n");
        j = 0;
        while(bfs())
        {
            j+= dinic(0, INF);
            //printf("!%d     %d\n", mid, j);
        }

        if(j == c)
        {
            ans = mid;
            high = mid - 1;
            //printf("!!\n");
        }
        else low = mid + 1;
    }
    printf("%d\n", ans);

    return 0;
}
