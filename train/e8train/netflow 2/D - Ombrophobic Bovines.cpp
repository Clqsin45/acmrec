#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MD 210
#define MT 160400
#define LL long long
#define INF 0x3f7f7f7f
const long long inf=100000000000000LL;
LL f[MD][MD];
int d[MD << 1], q[MT * 40], st[MT], head[MD << 1], c[MD<<1];
struct point
{
    int u, v, next, lim;
}p[MT];
int n, e, no;


void add(int x, int y, int z)
{
    p[no].u = x;    p[no].v = y;
    p[no].lim = z;
    p[no].next = head[x];
    head[x] = no++;
}
void init()
{
    int i, j;
    for(i = 0; i <= n + 1; i++)
        for(j = 0; j  <= n + 1; j++)
            f[i][j] = inf;

    return;
}

void floyd()
{
    int i, j, k;

    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                if(f[i][k] != inf && f[k][j] != inf)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
}

void build(LL mid)
{
    int i, j;
    memset(head, -1, sizeof(head));
    no = 0;
    for(i = 1; i <= n; i++)
    {
        add(0, i, f[0][i]);
        add(i, 0, 0);   add(e, i + n, 0);
        add(i + n, e, f[i][e - n]);
        add(i, i + n, INF); add(i + n, i , 0);
       // m[0][i] = f[0][i];
        //m[i][0] = m[e][i + n] = 0;
//        m[i + n][e] = f[i][e - n];
//        m[i][i + n] = INF;  m[i + n][i] =0;
        for(j = 1; j <= n; j++)
        {
            if(i == j)  continue;
            if(f[i][j] <= mid)
            {
////                m[i][j + n] = INF;
                add(i, j + n, INF);
                add(j + n, i, 0);
//                m[j + n][i] = 0;
            }
//            else m[i][j + n] = m[j + n][i] = 0;
        }
    }
}
bool bfs()
{
    int f, r, i, x, y;
    f = r = 0;
    memset(d, -1, sizeof(d));
    d[0] = 0;   q[r++] = 0;
    while(f < r)
    {
        x = q[f++];
        for(i = head[x]; i != -1; i = p[i].next)
        {
            if(p[i].lim > 0 && d[y = p[i].v] == -1)
            {
                d[y] = d[x] + 1;
                if(y == e)  return true;
                q[r++] = y;
            }
        }
    }
    return false;
}

int dinic()
{
    int maxflow = 0, nowflow, top, m, loc, x, y, i;
    x = 0;
    while(bfs())
    {
        top = 0;
        for(i = 0 ; i <= e; i++)    c[i] = head[i];
        while(1)
        {
            if(x == e)
            {
                nowflow = INF;
                for(i = 0; i < top; i++)
                {
                    if(p[st[i]].lim < nowflow)
                    {
                        nowflow = p[st[i]].lim;
                        loc = i;
                    }
                }
                maxflow += nowflow;
                for(i = 0 ; i < top; i++)
                {
                    p[st[i]].lim -= nowflow;
                    p[st[i]^1].lim += nowflow;
                }

                top = loc;
                x = p[st[top]].u;
            }
            for(i = c[x]; i != -1; i = p[i].next)
            {
                if(p[i].lim && d[p[i].v] == d[x] + 1)   break;
            }
            c[x] = i;
            if(i != -1)
            {
                st[top++] = i;
                x = p[i].v;
            }
            else
            {
                if(!top)    break;
                d[x] = -1;
                x = p[st[--top]].u;
            }
        }
    }
    return maxflow;
}

int main(void)
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int p, i;
    LL x, y, z, sum = 0, ans = -1, high, low, mid;
    scanf("%d%d", &n, &p);
    init();
    e = n * 2 + 1;

    for(i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &x, &y);
        f[0][i] = x;    f[i][e - n] = y;
        sum += x;
    }

    while(p--)
    {
        scanf("%lld%lld%lld", &x, &y, &z);
        f[x][y] = min(z, f[x][y]);
        f[y][x] = min(z, f[y][x]);
    }
    floyd();
    low = 0; high = inf - 1;
    while(low <= high)
    {
        mid = (low + high) >> 1;
        //printf("%lld\n", mid);
        build(mid);
        p = dinic();
        if(p == sum)
        {
            high = mid - 1;
            ans = mid;
        }
        else
            low = mid + 1;
    }
    printf("%lld\n", ans);
    return 0;
}
