#include <stdio.h>
#include <string.h>
#define MAX 100002

int f[MAX][11], g[11][MAX];
int ctain[11], now[11], v[11], n, m;
inline int scan_d(void)
{
    char c; int ret=0;
    while((c = getchar()) < '0' || c>'9');
    while(c >= '0' && c<= '9') ret = ret * 10+(c-'0'), c=getchar();
    return ret;
}

int dfs(int x)
{
    int i, j;
    //printf("~att%d  %d\n",x, m);
    for(i = 0; i < m; i++)
    {
        if(f[x][i] && !v[i])
        {
            v[i] = 1;
            if(now[i] < ctain[i])
            {
                g[i][++now[i]] = x;
                return 1;
            }
            for(j = 1; j <= now[i]; j++)
            {
                if(dfs(g[i][j]))
                {
                    g[i][j] = x;
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main(void)
{
    int flag;
    int i, j;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        flag = 0;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                f[i][j] = scan_d();
            }
        }

        for(i = 0; i < m; i++)
            ctain[i] = scan_d();
        memset(now, 0, sizeof(now));
        for(i = 0; i < n; i++)
        {
            memset(v, 0, sizeof(v));
            //printf("%d\n", dfs(i));
            if(dfs(i))  continue;
            flag = 1;
            break;
        }
        if(flag)    printf("NO\n");
        else printf("YES\n");
    }
}
