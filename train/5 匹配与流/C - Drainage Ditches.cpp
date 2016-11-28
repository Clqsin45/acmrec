#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 202
#define INF 0x3f7f7f7f

int f[MAX][MAX], d[MAX], q[MAX  * 100];
int s, e;

bool bfs()
{
    int t, r, x, y, i;
    t = r = 0;
    memset(d, -1, sizeof(d));

    d[1] = 0;   q[r++] = 1;
    while(t < r)
    {
        x = q[t++];
        for(i = 0; i <= e; i++)
        {
            if(f[x][i] && d[i] == -1)
            {
                d[i] = d[x] + 1;
                if(i == e)  return true;
                q[r++] = i;
            }
        }
    }
    return false;
}

int maxflow(int x, int sum)
{
    if(x == e)  return sum;

    int nowflow = 0, i, tmp = sum;
    for(i = s; i <= e && tmp; i++)
    {
        if(f[x][i] && d[i] == d[x] + 1)
        {
            nowflow = maxflow(i, min(tmp, f[x][i]));
            f[x][i] -= nowflow;
            f[i][x] += nowflow;
            tmp -= nowflow;
        }
    }
    return sum - tmp;
}
int main(void)
{
    int n, m, i, st1, st2, stt;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(f, 0, sizeof(f));
        s = 1;  e = m;
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &st1, &st2, &stt);
            f[st1][st2] += stt;
        }
        int ans = 0;
        while(bfs())
        {
            while(stt = maxflow(s, INF))
                ans += stt;
        }
        printf("%d\n", ans);
    }
    return 0;
}
