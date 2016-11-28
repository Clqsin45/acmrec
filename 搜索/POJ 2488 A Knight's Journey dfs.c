#include <stdio.h>
#include <string.h>
int gox[10] = {0, -1, 1, -2, 2, -2, 2, -1, 1}, goy[10] = {0, -2, -2, -1, -1, 1, 1,2 ,2};
int v[30][30], pt[38][3], ed, m, n;

int judge(int x, int y)
{
    if(x < 1 || y < 1)   return 0;
    if(x > m || y > n)   return 0;
    return 1;
}

int dfs(int x, int y, int ct)
{
    int xx, yy, sign = 0, i;
    pt[ct][1] = x;  pt[ct][2] = y;
    v[x][y] = 1;
    if(ct == ed) return 1;

    for(i = 1; i <= 8; i++)
    {
        xx = x + gox[i];    yy = y + goy[i];
        if(!v[xx][yy] && judge(xx, yy))
        {
            v[xx][yy] = 1;
            sign = dfs(xx, yy, ct + 1);
        }
    }
    if(!sign)
    {
        v[x][y] = 0;
        return 0;
    }
    return 1;
}
int main(void)
{
    int t, i ,j, sign, k, s = 1;
    scanf("%d", &t);
    while(t--)
    {
        sign = 0;
        scanf("%d%d", &m, &n);  ed = m * n;
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {

                memset(v, 0, sizeof(v));
                if(dfs(j, i, 1))
                {
                    sign = 1;
                    break;
                }
            }
            if(sign)    break;
        }
        if(sign)
        {
            printf("Scenario #%d:\n",s);
            for(k = 1;k <= ed ; k++)   printf("%c%d",'A' + pt[k][2] - 1, pt[k][1]);
            printf("\n");
        }
        else printf("Scenario #%d:\nimpossible\n",s);
        if(t)  printf("\n");
        s++;
    }
    system("pause");
    return 0;
}
