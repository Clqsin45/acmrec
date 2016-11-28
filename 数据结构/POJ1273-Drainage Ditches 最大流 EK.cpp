#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 202
#define INF 0x7f7f7f7f

int f[MAX][MAX],pre[MAX], v[MAX];
int n, m;
int q[MAX * 1000];
int bfs(int s, int e)
{
    int h, t, mi, x, i;
    memset(v, 0, sizeof(v));
    memset(pre, -1, sizeof(pre));
    v[s] = true;
    pre[s] = s;
    for(q[h = t = 1] = s; h <= t; h++)
    {
        x = q[h];
        //cout<<x<<endl;
        for(i = 1; i <= n; i++)
        {
            if(f[x][i] > 0 && !v[i])
            {
                v[i] = 1;
                pre[i] = x;
                q[++t] = i;
               // cout<<x<<endl;
                if(i == e)  return true;
                //break;
            }
        }
    }
    return false;
}
int maxflow(int s, int e)
{
    int i, mi = INF, flow = 0;
    while(bfs(s, e))
    {
        //cout<<1<<endl;
        mi = INF;
        for(i = e; i != s; i = pre[i])
        {
            mi = min(mi, f[pre[i]][i]);
          //  cout<<i<<endl;
        }

        for(i = e; i != s; i = pre[i])
        {
            f[pre[i]][i] -= mi;
            f[i][pre[i]] += mi;
        }
        flow += mi;
       // cout<<"!!!\n"<<endl;
    }
    return flow;
}
int main(void)
{
    int ans, i, st1, st2, stt;
    while(scanf("%d%d", &m, &n) != EOF)
    {
        memset(f, 0, sizeof(f));
        for(i = 1; i <= m ; i++)
        {
            scanf("%d%d%d", &st1, &st2, &stt);
            f[st1][st2] += stt;
        }
        //cout<<"!!!";
        ans = maxflow(1, n);
        cout<<ans<<endl;

    }
    return 0;
}
