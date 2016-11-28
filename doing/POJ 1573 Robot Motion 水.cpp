#include <stdio.h>
#include <string.h>
int v[440][44], map[440][44];
int gox[5] = {1, 0, -1, 0}, goy[5] = {0, 1, 0, -1};
int main(void)
{
    int m, n, nx, ny, stn, dir, flag, ctloop, ctout, i, j;
    char mst[44];
    while(scanf("%d%d%d", &m, &n, &nx) && (m || n || nx))
    {
        memset(v, 0, sizeof(v));
        flag = 1;
        ctloop = 0; ctout = 0;
        for(i = 1; i <= m; i++)
        {
            scanf("%s", mst + 1);
            for(j = 1; j <= n; j++)
            {
                switch(mst[j])
                {
                    case 'E':  map[i][j] = 0; break;
                    case 'S':  map[i][j] = 1; break;
                    case 'W':  map[i][j] = 2; break;
                    case 'N':  map[i][j] = 3; break;
                }
            }
        }

        ny  = 1;
        v[ny][nx] = 1;  dir = map[ny][nx];
        while(1)
        {
            nx += gox[dir]; ny += goy[dir];
            v[ny][nx]++;    ctout++;
            dir = map[ny][nx];
            if(nx < 1 || nx > n || ny < 1 || ny > m)    break;
            if(v[ny][nx] == 2 && flag)
            {
                stn = ctout;
                flag = 0;
            }
            else if(v[ny][nx] == 2 )
            {
                ctloop++;
            }
            else if(v[ny][nx] == 3)
            {
                break;
            }

        }
        if(flag) printf("%d step(s) to exit\n", ctout);
        else printf("%d step(s) before a loop of %d step(s)\n", stn - ctloop - 1, ctloop + 1);

    }
    return 0;
}
