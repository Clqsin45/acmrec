#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define MAX 222
#define INF 0x7f7f7f7f
char f[MAX][MAX];
int gox[4] = {1, 0, -1, 0}, goy[4] = {0, 1, 0, -1}, in[MAX][MAX], v[MAX][MAX];
queue<int>q;
int main(void)
{
    int n, m, i, j, stx, sty, flag, min, x, y, xx, yy;
    while(scanf("%d%d" , &n, &m) != EOF)
    {
        flag = 0;   min = INF;
        memset(in, 44, sizeof(in));
        memset(v, 0, sizeof(v));
        for(i = 1; i <= n; i++)
        {
            scanf("%s", f[i] + 1);
            for(j = 1; j <= m; j++)
            {
                if(f[i][j] == 'm')
                {
                    stx = i;    sty = j;
                }
            }
        }
        q.push(stx * 1000 + sty);
        in[stx][sty] = 0;
        v[stx][sty] = 1;
        while(!q.empty())
        {
            x = q.front() / 1000;   y = q.front() % 1000;
            q.pop();
            v[x][y] = 0;
            for(i = 0; i < 4; i++)
            {
                xx = x + gox[i];    yy = y + goy[i];
                if(x < 1 || x > n || y < 1 || y > m)    continue;
                if(f[xx][yy] =='#') continue;
                if(f[xx][yy] == 'f')
                {
                    if(in[xx][yy] > in[x][y] + 1)
                    {
                        in[xx][yy] = in[x][y] + 1;
                    }
                    flag = 1;
                    if(in[xx][yy] < min)    min = in[xx][yy];
                }
                else if(f[xx][yy] == 'g')
                {
                    if(in[xx][yy] > in[x][y] + 2)
                    {
                        in[xx][yy] = in[x][y] + 2;
                        if(!v[xx][yy])q.push(xx * 1000 + yy);
                        v[xx][yy] = 1;
                    }
                }
                else if(in[x][y] + 1 < in[xx][yy])
                {
                    in[xx][yy] = in[x][y] + 1;
                    if(!v[xx][yy])  q.push(xx * 1000 + yy);
                    v[xx][yy] = 1;
                }
            }
        }

        if(!flag)
        {
            printf("Poor Xiaoming\n");
        }
        else
        {
            printf("%d\n", min);
        }

    }
    return 0;
}
