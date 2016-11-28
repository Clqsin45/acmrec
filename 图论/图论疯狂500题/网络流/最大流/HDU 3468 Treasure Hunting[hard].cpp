#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cctype>
using namespace std;

#define T 114
#define N 21004
#define M 4100000
#define LL __int64
#define INF 0x3f7f7f7f
struct point
{
    int u, v, flow, next;
    point(){};
    point(int x, int y, int z, int w) : u(x), v(y), flow(z), next(w){};
}p[M];
struct record
{
    int x, y, no;
    record(){};
    record(int u, int v, int t) : x(u), y(v), no(t) {};
}rec[T];
int head[N], diss[N], dise[N], f[T][T], d[N], st[M], cur[N], id[T][T];
int now, s, e, no, n, m, num, ct, limit;
int gox[4] = {0, -1, 0, 1}, goy[4] = {-1, 0, 1, 0};
char map[T][T];

void init()
{
    memset(head, -1, sizeof(head));
    memset(id, -1, sizeof(id));
    no = num = ct = 0;
}

bool cmp(record a, record b)
{
    return a.no < b.no;
}

bool inmap(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
void add(int x,int y, int z)
{
    p[no] = point(x, y, z, head[x]);    head[x] = no++;
}
bool bfs(int surx, int sury, int endx, int endy, int *dis)
{
    memset(dis, -1, N * sizeof(int));
    memset(f, 0x3f, sizeof(f));
    queue<record>q;
    int i, j, x, y, xx, yy;
    record a, b;
    f[surx][sury] = 0;
    a = record(surx, sury, 0);
    q.push(a);
    while(!q.empty())
    {
        a = q.front();  q.pop();
        x = a.x;    y = a.y;
        //printf("%d %d\n", x, y);
        for(i = 0; i < 4; i++)
        {
            xx = x + gox[i];    yy = y + goy[i];
            if(!inmap(xx, yy) || f[xx][yy] != f[0][0] || map[xx][yy] == '#')  continue;
            //printf("  %d %d\n",  xx, yy);

                if(xx == endx && yy == endy)
                {
                    limit = f[x][y] + 1;    return true;
                }
            f[xx][yy] = f[x][y] + 1;
            if(map[xx][yy] == '*')
            {
                if(id[xx][yy] == -1)
                {
                    id[xx][yy] = ++num;
                }
                dis[id[xx][yy]] = f[xx][yy];
            }
            b = record(xx, yy, 0);
            q.push(b);

        }
    }
    return false;
}

bool  gao()
{
    int i, j, sx, sy, ex, ey;
    bool flag = true;
    s = 0;
    for(i = 1; i < ct; i++)
    {
        //printf("%d\n", i);
        sx = rec[i].x;  sy = rec[i].y;
        ex = rec[i+1].x;    ey = rec[i+1].y;
        flag = bfs(sx, sy, ex, ey, diss);
        if(!flag) return false;
        flag = bfs(ex, ey, sx, sy, dise);
        for(j = 1; j <= num; j++)
        {
            if(diss[j] == -1 || dise[j] == -1)  continue;
            if(diss[j] + dise[j] == limit)
            {
                add(i, j + ct, 1);
                add(j + ct, i, 0);
            }
        }
        add(s, i, 1); add(i, s, 0);
    }
    e = ct + num + 1;
    for(j = 1; j <= num; j++)
    {
        add(j + ct, e,  1);   add(e, j + ct, 0);
    }

    return true;
}

bool find()
{
    int i, x,y;
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
    int i, top, maxflow = 0, nowflow, x = s, loc;
    while(find())
    {
        for(i = s; i <= e; i++) cur[i] = head[i];   top = 0;
        while(true)
        {
            if(x==e)
            {
                nowflow = INF;
                for(i = 0 ; i < top; i++)
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
            for(i = cur[x]; i != -1; i = p[i].next)
                if(p[i].flow && d[p[i].v] == d[x] + 1)  break;
            cur[x] = i;
            if(i != -1)
            {
                st[top++] = i;
                x =p[i].v;
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
    int i, j, x, y;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        init();
        for(i = 1; i <= n; i++)
        {
            scanf("%s", map[i] + 1);
            for(j = 1; j <= m; j++)
            {
                if(isalpha(map[i][j]))
                {
                    rec[++ct].x = i;    rec[ct].y = j;
                    rec[ct].no =
                     (isupper(map[i][j]) ? map[i][j] - 'A' : map[i][j] - 'a' + 26) + 1;
                }
            }
        }
        sort(rec + 1, rec + 1 + ct, cmp);


        if(gao())
        {
            printf("%d\n", dinic());
        }
        else printf("-1\n");
    }
    return 0;
}
