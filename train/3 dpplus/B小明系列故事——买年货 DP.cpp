#include <stdio.h>
#include <string.h>
#define MAX 111
int w[MAX][3][3], v[MAX];
int f[MAX][MAX][10];

inline int findmax(int x, int y)
{
    return x > y ? x : y;
}
int main(void)
{
    //freopen("out.txt", "w", stdout);
    int n, k, m, g, i, j, t, fr, c, temp;
    while(scanf("%d%d%d%d", &n, &m, &g, &k) != EOF)
    {
        memset(f, 0, sizeof(f));
        for(i = 1; i <= n; i++)
        {
            w[i][0][1] = w[i][0][2] = w[i][1][0] = w[i][1][2] = w[i][2][0] = w[i][2][1] = 0;
            scanf("%d%d%d", &w[i][0][0], &w[i][1][1], &v[i]);
            w[i][2][2] = 1;
        }
        for(i = 1; i <= n; i++)
        {
            for(j = m; j >= 0; j--)
            {
            for(t = g; t >= 0; t--)
            {
            for(fr = k; fr >= 0; fr--)
            {
                temp = 0;
                for(c = 0; c < 3; c++)
                {
                    if(j - w[i][c][0] >= 0 && t - w[i][c][1] >= 0 && fr - w[i][c][2] >= 0)
                    {
                        //printf("!%d\n", c);
                        temp = findmax(temp, f[j - w[i][c][0]][t - w[i][c][1]][fr - w[i][c][2]] + v[i]);
                        //printf("in%d   f[%d][%d][%d] = %d\n",i,  j, t, fr, f[j][t][fr]);
                    }
                }
                f[j][t][fr] = findmax(temp, f[j][t][fr]);
            }
            }
            }
        }
        printf("%d\n", f[m][g][k]);
    }
    return 0;
}
