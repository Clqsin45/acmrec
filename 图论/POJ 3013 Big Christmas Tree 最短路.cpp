#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 55555
const __int64 INF = 0x7f7f7f7f7f7f7f7f;
struct point
{
    int now, next, w;
}pt[MAX * 3];

struct node
{
    int u;  __int64 dis;
    bool operator < (const node &a) const{
        return dis > a.dis;
    }
};
int head[MAX], val[MAX], no, vis[MAX];
__int64 d[MAX];

void add(int x, int y, int z)
{
    pt[++no].next = head[x]; head[x] = no;
    pt[no].now = y;  pt[no].w = z;
    return;
}

void dijkstra (int n)
{
    int u, v, i;
    for(i = 1; i <= n; i++)
    {
        vis[i] = 0;   d[i] = INF;
    }
    d[1] = 0;
    priority_queue<node>que;
    node a;
    a.u = 1; a.dis = 0;
    que.push(a);
    while(!que.empty())
    {
        u = que.top().u;
        que.pop();
        if(vis[u])  continue;
        vis[u] = 1;
        for(i = head[u]; i != -1; i = pt[i].next)
        {
            v = pt[i].now;
            if(!vis[v] && d[v] > d[u] + pt[i].w)
            {
                d[v] = d[u] + pt[i].w;
                a.u = v;    a.dis = d[v];
                que.push(a);
            }
        }
    }

}
int main(void)
{
    //freopen("in.txt", "r", stdin);
    int t, i, n, m, st1, st2, stt;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        if(n == 1 || n == 0)
        {
            for(i = 1; i <= n; i++) scanf("%d", &stt);
            for(i = 1; i <= m; i++) scanf("%d%d%d", &st1, &st2, &stt);
            printf("0\n");
            continue;
        }
        for(i = 1; i <= n ;i ++)
        {
            head[i] = -1;   scanf("%d", &val[i]);
        }
        no = 0;
        for(i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &st1, &st2, &stt);
            add(st1, st2, stt);
            add(st2, st1, stt);
        }
        dijkstra(n);
        __int64 ans = 0;
        bool flag = true;
        for(i = 2; i <= n; i++)
        {
            if(d[i] != INF) ans += d[i] * val[i];
            else
            {
                flag = false;
                break;
            }
        }
        if(flag) printf("%I64d\n", ans);
        else printf("No Answer\n");
    }
    return 0;
}
