#include <stdio.h>
#define INF 10000002
#define MAX 1000000000
//痙커綱죄붤댕가가가가가가가가가 가가 가가가가가가 가가가가가가가 가가가가 가가가 가가가가가  가
int v[1002], d[1002], head[1002], sign, n, no, q[INF], time[1002], s[1002];
struct point
{
    int now;    int w;  int next;
}p[50002];

void add( int x, int y, int z)
{
    p[no].next = head[x];   head[x] = no;
    p[no].now = y;  p[no].w = z;    no++;
}

void spfa(void)
{
    int f, r, i, j, x , y;
    v[0] = 1;  time[0]++;
    for(q[f = r = 1] = 0 ; f <= r; f++)
    {
        x = q[f];   v[x] = 0;
        for(i = head[x]; i!= -1; i = p[i].next)
        {
            y = p[i].now;
            if(d[y] < d[x] + p[i].w)
            {
                d[y] = d[x] + p[i].w;
                if(!v[y])
                {
                    q[++r] = y;     v[y] = 1;
                    if(++time[y] > n)
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
    int m, i, j, st1, st2, stt;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(v, 0, sizeof(v));
        memset(time, 0, sizeof(time));
        sign = 0;   no = 0;
        d[0] = 0;

        for(i = 0; i <= n + 1; i++) head[i] = -1;
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &st1);
            d[i] = -MAX;
            add(i, i - 1, -st1);
            add(i - 1, i, 0);
            add(0, i, 0);
        }
        for(i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &st1, &st2, &stt);
            add(st1 - 1, st2, stt);
        }
        spfa();
        if(sign == -1)  printf("Bad Estimations\n");
        else printf("%d\n", d[n]);
    }
    return 0;
}
