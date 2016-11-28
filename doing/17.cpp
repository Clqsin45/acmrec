#include <stdio.h>
#include <string.h>
#define MAX 2001
#define MAX2 4008004

char map[MAX][MAX] = {0}, inq[MAX][MAX] = {0};
int qf[MAX2][2] ={{0}}, qb[MAX2][2] = {{0}};
int ef = 0, eb = 0, stx, sty, edx, edy, n, m, num = 0;
int deepfs = 0, deepfe = 0, deepbs = 0, deepbe = 0;
int gox[4] = {0, 1, 0, -1}, goy[4] = {1, 0, -1, 0}, deepf = 0, deepb = 0;

int judge(int x, int y)
{
    if(x > n || x < 1 || y > m || y < 1)    return 1;
    else return 0;
}
int bfs(int dir)
{
    int f, r, x, y, xx, yy, i;
    if(dir)
    {
        f = deepbs; r = deepbe; deepb ++;
        while(f <= deepbe)
        {
            x = qb[f][0];   y = qb[f][1];
            for(i = 0; i < 4; i++)
            {
                xx = x + gox[i];    yy = y + goy[i];
                if(judge(xx, yy))   continue;
                if(inq[xx][yy] == 1)
                {
                    return deepf + deepb - 1;
                }
                else if(inq[xx][yy] == 2)   continue;
                else if(map[xx][yy] == 'E')
                {
                    if(ef)  return ef + deepb - 1;
                    if(eb)  continue;
                    eb = deepb;
                }
                qb[++r][0] = xx;  qb[r][1] = yy;
                inq[xx][yy] = 2;
            }
            f++;
        }
        deepbs = deepbe + 1;
        deepbe = r;
    }
    else
    {
        f = deepfs; r = deepfe; deepf ++;
        while(f<= deepfe)
        {
            x = qf[f][0];   y = qf[f][1];
            for(i = 0; i < 4; i++)
            {
                xx = x + gox[i];    yy = y + goy[i];
                if(judge(xx, yy))   continue;
                if(inq[xx][yy] == 2)
                {
                    return deepf + deepb - 1;
                }
                else if(inq[xx][yy] == 1)   continue;
                else if(map[xx][yy] == 'E')
                {
                    if(eb)  return eb + deepf - 1;
                    if(ef)  continue;
                    ef = deepf;
                }
                inq[xx][yy] = 1;
                qf[++r][0] = xx;  qf[r][1] = yy;
            }
            f++;
        }
        deepfs = deepfe + 1;
        deepfe = r;
    }
    return 0;
}

int find(void)
{
    int ans;
    qf[deepfs = deepfe = 1][0] = stx;
    qb[deepbs = deepbe = 1][0] = edx;
    qf[deepfs = deepfe = 1][1] = sty;
    qb[deepbs = deepbe = 1][1] = edy;
    inq[stx][sty] = 1;  inq[edx][edy] = 2;
    while(deepfs <= deepfe || deepbs <= deepfe)
    {
        if(deepfs <= deepfe)
        {
            ans = bfs(0);
            if(ans)    return ans;
        }
        if(deepbs <= deepfe)
        {
            ans = bfs(1);
            if(ans)    return ans;
        }
    }
    return -1;
}

int main(void)
{
    int i, j, ans;
    char ch;
    scanf("%d%d", &n, &m);
    getchar();
    for(i = 1; i <= n; i++)
    {
        scanf("%s", map[i] + 1);
        for(j = 1; j <= m; j++)
        {
            if(map[i][j] == 'M')   continue;
            if(map[i][j] == 'N')
            {
                stx = i;    sty = j;
            }
            else if(map[i][j] == 'C')
            {
                edx = i;    edy = j;
            }
        }
    }


    if( (ans == find()) == -1)
        printf("Bad Eureka\n");
    else printf("%d\n", ans);
    return 0;
}
