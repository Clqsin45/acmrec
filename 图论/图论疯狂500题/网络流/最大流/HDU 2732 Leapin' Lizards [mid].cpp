#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cmath>
using namespace std;

#define N  1004
#define M 260005
#define LL __int64
#define INF 0x3f7f7f7f
struct point
{
    int u, v, flow, next;
    point(){};
    point(int x, int y, int z, int w):u(x), v(y), flow(w), next(z){};
}p[M];
int head[N], d[N], cur[N], st[M], no, s, e, dis, n, m;
char c[22][22], ch[22][22];

void add(int x, int y, int z)
{
    p[no] = point(x, y, head[x], z);  head[x] = no++;
}
void init(void)
{
    memset(head, -1, sizeof(head)); no= 0;
}

void canj(int x, int y)
{
    int i, j, fx, fy;
    fx = (x - 1) * m + y; fx = fx * 2 + 1;
    for(i = 1; i <= n; i ++)
    {
        for(j = 1; j <= m; j ++)
        {
            if(i == x && j == y)    continue;
            if((x - i) * (x - i) + (y - j)*(y - j) <= dis * dis && c[i][j] != 0)
            {
                //printf("%d %d %d %d\n", x, y, i, j);
                fy = (i - 1) * m + j;   fy <<= 1;
                add(fx, fy, INF);   add(fy, fx, 0);
            }
        }
    }
}

bool bfs()
{
    int i, x, y;
    memset(d, -1, sizeof(d));
    queue<int>q;
    d[s] = 0;   q.push(s);
    while(!q.empty())
    {
        x = q.front();  q.pop();
        for(i = head[x]; i != -1; i = p[i].next)
        {
            if(p[i].flow && d[y = p[i].v] < 0)
            {
                d[y] = d[x] + 1;
                if(y == e)  return true;
                q.push(y);
            }
        }
    }
    return false;
}

int dinic()
{
    int nowflow, maxflow = 0, i, top, x = s, y, loc;
    while(bfs())
    {
        //printf("%d\n", maxflow);
        for(i = s; i <= e; i++) cur[i] = head[i];
        top = 0;
        while(true)
        {
            if(x == e)
            {
                nowflow = INF;
                for(i = 0; i < top; i++)
                {
                    if(nowflow > p[st[i]].flow)
                    {
                        nowflow = p[st[i]].flow;
                        loc = i;
                    }
                }
                for(i = 0; i < top; i++)
                {
                    p[st[i]].flow -= nowflow;
                    p[st[i] ^ 1].flow += nowflow;
                }
                maxflow += nowflow;
                top = loc;  x = p[st[top]].u;
            }
            for(i = head[x]; i != -1; i = p[i].next)
            {
                if(p[i].flow && d[p[i].v] == d[x] + 1)  break;
            }
            cur[x] = i;
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
    int TC, tc, i, j, x, y, z, sum, ans;
    scanf("%d", &TC);
    for(tc = 1; tc <= TC; tc++)
    {
        init();
        scanf("%d%d", &n, &dis);
        s = 0;
        for(i = 1; i <= n; i++)
            scanf("%s", c[i] + 1);
        m = strlen(c[1] + 1);
       // printf("%d\n", m);
        e = (n * m * 2) + 1;
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                x = (i - 1) * m + j;
                x *= 2; y = x + 1;
                c[i][j] -= '0';
                if(c[i][j] > 0)
                {
                    add(x, y, c[i][j]); add(y, x, 0);
                    if(i + dis > n || i <= dis || j + dis > m || j <= dis)
                    {
                        add(y, e, INF); add(e, y, 0);
                    }
                }
            }

        }
        //printf("!!!!%d\n", m);
        for(i = 1, sum = 0; i <= n; i++)
        {
            scanf("%s", ch[i] + 1);
            for(j = 1; j <= m; j++)
            {
                //printf("%c\n", c[i][j]);
                if(ch[i][j] == 'L')
                {
                    x = (i - 1) * m + j;  x <<= 1;    add(s, x, 1);   add(x, s, 0);
                    sum++;
                }
                if(c[i][j] > 0) canj(i, j);
            }
        }
        ans = dinic();
        //printf("%d %d\n", sum, ans);
        ans = sum - ans;
        if(ans == 1)
            printf("Case #%d: 1 lizard was left behind.\n", tc);
        else if(ans == 0)
            printf("Case #%d: no lizard was left behind.\n", tc);
        else printf("Case #%d: %d lizards were left behind.\n", tc, ans);
    }
    return 0;
}
