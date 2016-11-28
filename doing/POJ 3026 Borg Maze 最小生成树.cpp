#include <stdio.h>
#include <string.h>
#define INF 0x7f7f7f7f
#define MAX 4000
char map[150][150];
int fx[150][150], d[150], v[150], node[150][150], vb[150][150], db[150][150];
int n, m, gox[5] = {0, 0, 1, 0, -1}, goy[5] = {0, 1, 0, -1, 0}, no;
struct queue
{
    int x; int y;
}q[MAX];
void bfs(int x, int y)
{
    int i, j, f = 0, r = 0, u, v, nx, ny;

    memset(vb, 0, sizeof(vb));
    memset(db, 0, sizeof(db));
    vb[x][y] = 1;
    q[r].x = x; q[r++].y = y;
    while(f < r)
    {
        u = q[f].x; v = q[f++].y;
        if(node[u][v] > 0)  fx[ node[x][y] ][node[u][v] ] = db[u][v];

        for(i = 1; i <= 4; i++)
        {
            nx = u + gox[i];    ny = v + goy[i];
            if(nx >= 1 && nx <= m && ny >= 1 && ny <= n)
            {
                if(!vb[nx][ny] && node[u][v] != -1)
                {
                    q[r].x = nx;    q[r++].y = ny;
                    db[nx][ny] = db[u][v] + 1;
                    vb[nx][ny] = 1;
                }
            }
        }
    }
    return;

}

int prim(void)
{
    int i, j, sum = 0, min, st;
    for(i = 1; i <= no; i++)
    {
        d[i] = fx[1][i]; v[i] = 0;
    }
    d[1] = 0;   v[1] = 1;
    for(i = 1; i < no; i++)
    {
        min = INF;  st = 0;
        for(j = 1; j <= no; j++)
        {
            if(!v[j] && d[j] < min)
            {
                min = d[j]; st = j;
            }
        }
        v[st] = 1;  sum += min;
        for(j =  1; j <= no; j++)
        {
            if(!v[j] && d[j] > fx[st][j])
                d[j] = fx[st][j];
        }
    }
    return sum;
}


int main(void)
{
    char orz[150], st;
    int  t, i, j;
    scanf("%d", &t);
    while(t--)
    {
        memset(node, -1, sizeof(node));
        scanf("%d%d", &n, &m);
        no = 0;
        gets(orz);
        for(i = 1; i <= m; i++)
        {
            gets(orz + 1);
            for(j = 1; j <= n; j++)
            {
                if(orz[j] == '#') node[i][j] = -1;
                else if(orz[j] == ' ')  node[i][j] = 0;
                else node[i][j] = ++no;
            }
        }
        for(i = 1; i <= m; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(node[i][j] > 0)  bfs(i, j);
            }
        }
        printf("%d\n", prim());
    }
    return 0;
}
