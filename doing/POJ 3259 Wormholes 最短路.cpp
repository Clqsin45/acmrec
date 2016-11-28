#include <stdio.h>
#include <string.h>
#define MAX 10000005
#define INF 0x3f3f3f3f
struct line
{
    int now, next, w;
}p[5005];
int f[505][505], no, d[505];
void add(int x, int y, int z)
{
    p[++no].now = x;
    p[no].next = y;  p[no].w = z;
}

int bellman(int n)
{
    bool flag;
    int i, j;
    for(i = 1; i <= n - 1; i++)
    {
        for(j = 1; j <= no; j++)
        {
            if(d[p[j].next] > d[p[j].now] + p[j].w)
            {
                d[p[j].next] = d[p[j].now] + p[j].w;
                flag = true;
            }
        }
        if(!flag)   break;
    }
    for(i = 1; i <= no; i++)
    {
        if(d[p[i].next] > d[p[i].now] + p[i].w)
            return 1;
    }
    return 0;
}
int main(void)
{
    int t, i, j, st1, st2, stt, ans, n, pt, w;
    scanf("%d", &t);
    while(t--)
    {
        no = 0;
        scanf("%d%d%d", &n, &pt, &w);
        for(i = 0 ; i <= n; i ++)
        {
            for(j = 0; j <= n; j++)
                f[i][j] = INF;
            d[i] = INF;
        }


        for(i = 1; i <= pt; i++)
        {
            scanf("%d%d%d", &st1, &st2, &stt);
            if(f[st1][st2] > stt)
            {
                f[st1][st2] = f[st2][st1] = stt;
                add(st1, st2, stt);
                add(st2, st1, stt);
            }
        }
        for(i = 1; i <= w; i++)
        {
            scanf("%d%d%d", &st1, &st2, &stt);
            add(st1, st2, -stt);
        }
        ans = bellman(n);
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
