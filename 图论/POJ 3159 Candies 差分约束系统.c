#include <stdio.h>
#define INF 10000002
struct line
{
    int t, w, next;
}p[150004];
int head[30004], m , n, v[30004], d[30004],s[1000002];

void spfa(void)
{
    int i, j, x, y,top;
    v[1] = 1;   d[1] = 0;
    s[top = 1] = 1;
    while(top)
    {
        x = s[top--]; v[x] = 0;
        for(i = head[x]; i != -1; i = p[i].next)
        {
            y = p[i].t;
            if(x != y && (p[i].w +d[x]) < d[y])
            {
                d[y] = p[i].w + d[x];
                if(!v[y])
                {
                    s[++top] = y;     v[y] = 1;
                }
            }
        }
    }
    /*
    for(q[f = r = 1] = 1;  f <= r;  f++)
    {
        x = q[f];   v[x] = 0;
        for(i = head[x]; i != -1; i = p[i].next)
        {
            y = p[i].t;
            if(x != y && (p[i].w +d[x]) < d[y])
            {
                d[y] = p[i].w + d[x];
                if(!v[y])
                {
                    q[++r] = y;     v[y] = 1;
                }
            }
        }
    }
    */

}
int main(void)
{
    int st1, st2, stt, i, j;

    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++)
    {
        head[i] = -1;
        v[i] = 0;   d[i] = INF;
    }
    for(i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &st1, &st2, &stt);
        p[i].next = head[st1];   head[st1] = i;
        p[i].w = stt;   p[i].t = st2;
    }

    spfa();
    printf("%d\n", d[n]);

    return 0;
}
