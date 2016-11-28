#include <stdio.h>
#include <string.h>
#define MAX  100040
#define INF 0x7f7f7f7f

struct point
{
    int next, to, time;
}road[MAX];
int head[MAX] = {-1}, q[MAX * 10], d[MAX], v[MAX], n, no = 0;

void add(int x, int y, int ti)
{
    road[++no].next = head[x];
    head[x] = no;   road[no].to = y;   road[no].time = ti;
    return;
}

int spfa(int s, int e)
{
    int f, r, i, x, y, now;

    for(i = 1; i <= n; i++)
    {
        v[i] = 0;   d[i] = INF;
    }
    d[s] = 0;   v[s] = 1;
    for(q[f = r = 1] = s; f <= r; f++)
    {
        x = q[f];   v[x] = 0;
        for(now = head[x]; now != -1; now = road[now].next)
        {
            y = road[now].to;
            if(d[y] > d[x] + road[now].time)
            {
                d[y] = d[x] + road[now].time;
                if(!v[y])
                {
                    q[++r] = y; v[y] = 1;
                }
            }
        }
    }
    return d[e];
}

int main(void)
{
    int m, end, st1, st2, stt, max = 0,temp, i;
    scanf("%d%d%d", &n, &m, &end);
    memset(head, -1, sizeof(head));
    while(m--)
    {
        scanf("%d%d%d", &st1, &st2, &stt);
        add(st1, st2, stt);
    }
    for(i = 1; i <= n; i++)
    {
        temp = 0;
        temp += spfa(i, end);
        temp += spfa(end, i);
        max = max > temp ? max : temp;
    }
    printf("%d\n", max);

    return 0;
}
