#include <stdio.h>
#define INF 10000002
struct point
{
    int now;  int w;  int next;
}p[20004];
int v[1002], q[INF], d[1002], time[1002], head[1002];
int n, sign = 0;

void spfa(void)
{
    int f, r, x, y, i;
    d[1] = 0;   v[1] = 1;   time[1] ++;
    for(q[f = r = 1] = 1; f <= r; f++)
    {
        x = q[f];   v[x] = 0;
        for(i = head[x]; i != -1; i = p[i].next)
        {
            y = p[i].now;
            if(x != y && d[y] > p[i].w + d[x])
            {
                d[y] = p[i].w + d[x];
                if(!v[y])
                {
                    q[++r] = y; v[y] = 1;
                    time[y]++;
                    if(time[y] >= n)
                    {
                        sign = -1;
                        return;
                    }
                }
            }
        }
    }
}
int main(void)
{
    int m1, m2, i, no = 0, st1, st2, stt;
    scanf("%d%d%d", &n, &m1, &m2);
    for(i = 1; i <= n; i++)
    {
        v[i] = 0;   d[i] = INF;
        head[i] = -1;   time[i] = 0;
    }
    while(m1--)
    {
        scanf("%d%d%d", &st1, &st2, &stt);
        p[no].next = head[st1];     head[st1] = no;
        p[no].now = st2;    p[no++].w = stt;
    }
    while(m2--)
    {
        scanf("%d%d%d", &st1, &st2, &stt);
        p[no].next = head[st2];     head[st2] = no;
        p[no].now = st1;    p[no++].w = -stt;
    }
    spfa();
    if(sign < 0)  printf("%d\n", sign);
    else if(d[n] == INF)    printf("-2\n");
    else printf("%d\n", d[n]);
    return 0;
}
