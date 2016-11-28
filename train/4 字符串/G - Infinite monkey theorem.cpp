#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MC 33
#define ML 14
#define MN 11111
#define INF 0x3f7f7f7f
int n, m, lt;
int next[ML];
double v[MC], f[MN][ML];
char p[ML], dir[MC];

void getnext()
{
    int i = 0, j = -1;
    memset(next, 0, sizeof(next));
    next[0] = -1;

    while(i < lt)
    {
        if(j == -1 || p[i] == p[j])
        {
            i++;    j++;
            //if(p[i] != p[j])
                next[i] = j;
            //else next[i] = next[j];
        }
        else j = next[j];
    }
    return;
}

int main(void)
{
    int s, i, j, k;
    double ans;
    while(scanf("%d%d", &m, &n) && (n || m))
    {
        getchar();
        for(i = 1; i <= m; i++)
        {
            scanf("%c%lf", &dir[i], &v[i]);
            getchar();
        }
        scanf("%s", p);     lt = strlen(p);

        getnext();

        memset(f, 0, sizeof(f));

        f[0][0] = 1;    next[0] = 0;
        //for(i = 0; i <= lt; i++)    printf("%d  %d\n", i, next[i]);

        for(i = 1; i <= n; i++)
        {
            for(j = 0; j < lt; j++)
            {
                for(k = 1; k <= m; k++)
                {
                    s = j;
                    while(s > 0 && p[s] != dir[k]) s = next[s];
                    if(p[s] == dir[k])    s++;  //到最后一位之后， s = lt + 1, 此时满足
                    //printf("%d  %d  %d  %d\n", i, j, k, s);
                    f[i][s] += f[i - 1][j] * v[k];
                }
            }
        }
        ans = 0;
        for(i = 1; i <= n; i++ )
        {
            //printf("%d  %lf\n", i, f[i][lt]);
            ans += f[i][lt];
        }
        printf("%.2f%%\n", ans * 100);
    }


    return 0;
}
