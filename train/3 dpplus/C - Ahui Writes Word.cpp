#include <stdio.h>
#include <string.h>
#define MAX_D 11
#define MAX_T 10010

int d[MAX_D][MAX_D], f[MAX_T];
struct dir
{
    int v, c;
}w[MAX_D * 100];

inline int findmax(int x, int y)
{
    return x > y ? x : y;
}
int main(void)
{
    int n, i, j, c, v, m, k, temp;
    char ch[11];
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(d, 0, sizeof(d));
        memset(f, 0, sizeof(f));
        for(i = 1; i <= n; i++)
        {
            scanf("%s%d%d", ch, &v, &c);
            d[v][c] ++;
        }
        for(i = 0, n = 0; i <= 10; i++)
        {
            for(j = 0; j <= 10; j++)
            {
                temp = 1;
                while(d[i][j] >= temp * 2)
                {
                    w[++n].c = temp * j;
                    w[n].v = temp * i;
                    d[i][j] -= temp;
                    temp <<= 1;
                }
                if(d[i][j] > 0)
                {
                    w[++n].c = d[i][j] * j;
                    w[n].v = d[i][j] * i;
                }
            }
        }

        for(i = 1; i <= n; i++)
        {
            for(j = m; j >= w[i].c; j--)
            {
                f[j] = findmax(f[j], f[j - w[i].c] + w[i].v);
            }
        }
        printf("%d\n", f[m]);
    }
    return 0;
}
