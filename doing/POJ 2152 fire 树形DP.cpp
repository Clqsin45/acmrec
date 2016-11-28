#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 1004
#define M 4005
#define INF 0x3f3f3f3f
#define LL __int64

int head[N], d[N], dis[N], best[N], w[N], f[N][N], no, n;
struct point
{
    int now, next, len;
    point(){};
    point(int x, int y, int z):now(x), next(y), len(z){};
}p[M];

void add(int x, int y, int z)
{
    p[no] = point(y, head[x], z);   head[x] = no++;
    p[no] = point(x, head[y], z);   head[y] = no++;
}
void init()
{
    memset(head, -1, sizeof(head));
    no = 0;
}
void bfs(int x)
{
    int i, y;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(dis[y] != -1)    continue;
        dis[y] = dis[x] + p[i].len;
        bfs(y);
    }
}

void dfs(int x, int fa)
{
    int i, y, j;//printf("%d\n", x);
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(y == fa) continue;
        dfs(y, x);
    }
    //printf("%d\n", x);
    memset(dis, -1, sizeof(dis));
    dis[x] = 0; best[x] = INF;
    bfs(x);
    //printf("~~\n");
    for(i = 1; i <= n; i++)
    {
        if(dis[i] > d[x])   {f[x][i] = INF; continue;}
        f[x][i] = w[i];
        for(j = head[x]; j != -1; j = p[j].next)
        {
            y = p[j].now;
            if(y == fa) continue;
            f[x][i] += min(best[y], f[y][i] - w[i]);
        }
        best[x] = min(best[x], f[x][i]);
    }
}
int main()
{
    int TC, i, x, y, z;
    scanf("%d", &TC);
    while(TC--)
    {
        init();
        scanf("%d", &n);
        for(i = 1; i <= n; i++) scanf("%d", &w[i]);
        for(i = 1; i <= n; i++) scanf("%d", &d[i]);
        for(i = 1; i < n; i++)
        {
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z);
        }
        //printf("\n");
        dfs(1, -1);
        printf("%d\n", best[1]);
    }
}
