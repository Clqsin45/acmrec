#include <stdio.h>
#include <string.h>
#define MAX 100000000
//超级源点将图联通
int d[102], v[102], head[102], time[102], sign, q[100002], n, no;
struct point
{
    int now;    int next;   int w;
}p[10002];
void add(int x, int y, int z)
{
    p[no].next= head[x];    head[x] = no;
    p[no].now = y;  p[no].w = z;    no++;
}
void spfa(void)
{
    int i, x, y, f, r;
    d[n + 1] = 0;   v[n + 1] = 1;
    time[n + 1] = 0;    time[n + 1]++;
    for(q[f = r = 1] = n + 1 ; f <= r; f++)
    {
        x = q[f];   v[x] = 0;
        for(i = head[x]; i != -1; i = p[i].next)
        {
            y = p[i].now;
            if(d[y] > d[x] + p[i].w)
            {
                d[y] = d[x] + p[i].w;
                if(!v[y])
                {
                    q[++r] = y; v[y] = 1;
                    if(++time[y] > n + 1)
                    {
                        sign = 1;
                        return;
                    }
                }
            }
        }
    }

}
int main(void)
{
    int m, i, st1, st2, stt;
    char op[10];
    while(scanf("%d", &n) && n)
    {
        scanf("%d", &m);
        sign =  0;  no = 0;
        memset(time, -1, sizeof(time));
        memset(head, -1, sizeof(head));
        while(m--)
        {
            scanf("%d%d%s%d", &st1, &st2, op, &stt);
            if(strcmp(op,"gt") == 0)
            {
                add(st1 - 1, st1 + st2, -(stt + 1));
            }
            else
            {
                add(st1+st2, st1 - 1, stt - 1);
            }
        }
        for(i = 0; i <= n ;i++)
        {
            d[i] = MAX;     v[i] = 0;
            add(0, i, 0);
        }
        spfa();
        if(sign)    printf("successful conspiracy\n");
        else printf("lamentable kingdom\n");
    }
    return 0;
}
