#include <stdio.h>
#include <string.h>
#define MAX 10004
struct point
{
    int now;    int next;
}p[MAX * 5];
int d[MAX], head[MAX], n, m, no, sum, v[MAX], son[MAX];
int main(void)
{
    int i, st1, st2;
    while(scnaf("%d%d", &n, &m) != EOF)
    {
        no = 0;  sum = 0;
        memset(head, -1, sizeof(head));
        memset(son, 0, sizeof(son));
        for(i = 0; i < n; i++)
        {
            scanf("%d", &d[i]);
            sum += d[i]
        }
        for(i = 1; i <= m; i++)
        {
            scanf("%d%d", &st1, &st2);
            add(st1, st2);  add(st2, st1);
        }
        for(i = 0; i < n; i++)
        {
            son[]dfs
        }
    }
    return 0;
}
