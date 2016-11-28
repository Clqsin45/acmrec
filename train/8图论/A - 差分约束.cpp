#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define N 1004
#define M 20004
#define LL __int64
#define INF 0x3f7f7f7f

int head[N], v[N], time[N], d[N], no = 0;
bool flag = false;
struct point
{
    int now, w, next;
    point(){};
    point(int x, int y, int z):now(x), next(y), w(z) {};
}p[M];
queue<int>q;
void add(int x, int y, int z)
{
    p[no] = point(y, head[x], z);
    head[x] = no++;
}

void init()
{
    memset(head, -1, sizeof(head)); memset(time, 0, sizeof(time));
}

void spfa(int n)
{
    int i, x, y;

    for(i = 1; i <= n; i++)
        d[i] = INF;
    d[1] = 0;   v[1] = 1;   time[1]++;
    q.push(1);
    while(!q.empty())
    {
        x = q.front();  q.pop();    v[x] = 0;
        for(i = head[x]; i != -1; i = p[i].next)
        {
            y = p[i].now;
            if( x != y && d[y] > d[x] + p[i].w)
            {
                d[y] = d[x] + p[i].w;
                if(v[y])    continue;

                v[y] = true;    time[y] ++;
                q.push(y);
                if(time[y] < n) continue;

                flag = true;
                return;
            }
        }
    }
    return;
}
int main(void)
{
    int n, ml, md, x, y, z;
    scanf("%d%d%d", &n, &ml, &md);
    init();
    while(ml--)
    {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    while(md--)
    {
        scanf("%d%d%d", &x, &y, &z);
        add(y, x, -z);
    }
    spfa(n);
    if(flag)    printf("-1\n");
    else if(d[n] == INF)    printf("-2\n");
    else printf("%d\n", d[n]);
    return 0;
}
