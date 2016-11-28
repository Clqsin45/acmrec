#include <stdio.h>
#include <string.h>
int gox[5] = {1, 0, -1, 0}, goy[5] ={0, -1, 0, 1};
struct robot
{
    int x, y;
    int dir;
}rr[140];
int main(void)
{
    int t, m, n, sign, i, opr, opt, rn, cmd, j;
    char opd;
    scanf("%d", &t);
    while(t--)
    {
        sign = 1;
        scanf("%d%d", &m, &n);
        scanf("%d%d", &rn, &cmd);
        for(i = 1; i <= rn; i++)
        {
            scanf("%d%d %c", &rr[i].x, &rr[i].y, &opd);
            switch(opd)
            {
                case 'E': rr[i].dir = 0; break;
                case 'S': rr[i].dir = 1; break;
                case 'W': rr[i].dir = 2; break;
                case 'N': rr[i].dir = 3; break;
             }
        }
        while(cmd--)
        {
            scanf("%d %c%d", &opr, &opd, &opt);
            if(sign)
            {
                switch(opd)
                {
                    case 'F':
                        for(i = 1; i <= opt; i++)
                        {
                            rr[opr].x += gox[rr[opr].dir];
                            rr[opr].y += goy[rr[opr].dir];
                            if(rr[opr].x < 1 || rr[opr].x > m || rr[opr].y < 1 || rr[opr].y > n)
                            {
                                if(sign) printf("Robot %d crashes into the wall\n", opr);
                                sign = 0;
                            }
                            for(j = 1; j <= rn; j++)
                            {
                                if(rr[opr].x == rr[j].x && rr[opr].y == rr[j].y && j != opr)
                                {
                                    if(sign) printf("Robot %d crashes into robot %d\n", opr, j);
                                    sign = 0;
                                }
                            }

                        }
                        break;
                    case 'L':
                        for(i = 1; i <= opt; i++)
                        {
                            rr[opr].dir --;
                            if(rr[opr].dir < 0) rr[opr].dir = 3;
                        }
                        break;
                    case 'R':
                        for(i = 1; i <= opt; i++)
                        {
                            rr[opr].dir ++;
                            if(rr[opr].dir > 3) rr[opr].dir = 0;
                        }
                        break;
                }

            }
        }
        if(sign)    printf("OK\n");
    }

    return 0;
}
