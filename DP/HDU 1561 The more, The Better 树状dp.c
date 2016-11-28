#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f

struct point
{
    int now;    int next;
}p[202];
int v[202], head[202], n, m, no, f[202][202];

void add(int x, int y)
{
    p[++no].next = head[x];    head[x] = no;
    p[no].now = y;    return;
}
int max(int x, int y)
{
    return x > y ? x : y;
}

int find(int x)
{
    int i, j, k, y, ct = 1;
	f[x][1] = v[x];
    for(i = head[x]; i != -1; i = p[i].next)
	{
		y = p[i].now;
		ct += find(y);
        for(j = ct; j >= 1; j--)
        {
            /*for(k = j + 1; k <= ct + 1 ; k ++)*/
            for(k = ct + 1; k >= j + 1; k--)
            {
                f[x][k] = max(f[x][k], f[x][j] + f[y][k - j]);
            }
        }

    }		
    return ct;
}
int main(void)
{
    int i, j, st1;
    while(scanf("%d%d", &n, &m) && (m || n))
    {
        memset(head, -1, sizeof(head));
        no = 0;
        for(i = 0; i <= n + 1; i++)
        {
            for(j = 0; j <= m + 1; j++)
                f[i][j] = -INF;
        }
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d", &st1, &v[i]);
            add(st1, i);
        }

        find(0);
		printf("%d\n", f[0][m + 1]);
    }
    
    return 0;
}
