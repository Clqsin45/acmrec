#include <stdio.h>
#include <string.h>
#define INF 99999999
#define MAX 2147483647
int v[1004], q[INF], time[1004], head[1004], d[1004], n, no, sign;
struct point
{
    int now;    int next;   int w;
}p[400010];

void add(int x, int y, int z)
{
    p[no].next = head[x];   head[x] = no;
    p[no].now = y;  p[no].w = z;    no++;
}

void spfa(void)
{
    int i, f = 0, r = 0, x, y;

	q[r++] = 0; d[0] = 0;   v[0] = 1;
	while(f < r)
	{
		if(f == (INF - 1))    f = 0;
		x = q[f++]; 	v[x] = 0;
		for(i = head[x]; i != EOF; i = p[i].next)
		{
			y = p[i].now;
			if(d[y] > d[x] + p[i].w)
			{
				d[y] = d[x] + p[i].w;
				if(!v[y])
				{
					if(r == INF - 1)    r = 0;
					q[r++] = y; v[y] = 1;
					if(++time[y] > n)
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
    char op;
    while(scanf("%d%d", &n, &m)!= EOF)
    {
        no = 0; sign = 0;
        for(i = 0; i <= n; i++)
        {
            head[i] = -1;   v[i] = 0;   time[i] = 0;
            d[i] = MAX;
        }
        for(i = 1; i <= m; i++)
        {
            scanf("\n%c", &op);
            if(op == 'P')
            {
                scanf("%d%d%d", &st1, &st2, &stt);
                add(st2, st1, stt);
                add(st1, st2, -stt);
            }
            else if (op == 'V')
            {
                scanf("%d%d", &st1, &st2);
                add(st1, st2, -1);
            }
        }
        for(i = 1; i <= n; i++)
        {
           add(0, i, 0);
		}

        spfa();
        if(sign)    printf("Unreliable\n");
        else printf("Reliable\n");
    }
    return 0;
}
