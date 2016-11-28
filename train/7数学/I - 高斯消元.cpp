#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

#define N 104
#define M
#define LL __int64
#define INF 0x3f7f7f7f
#define eps 1e-8
double t[N], ans[N], f[N][N];
int ct[N];
int dirx[4] = {1, -1, 1, -1}, diry[4] = {1, 1, -1, -1};
int n, m, d;

void init()
{
    memset(ct, 0, sizeof(ct));
    memset(f, 0, sizeof(f));
}

bool inmap(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
void go(int x, int y)
{
    int i, j, k, xx, yy;
    int a = m * (x - 1) + y, b;
    for(i = 0; i <= d; i++)
    {
        for(j = 0; j <= d - i; j++)
        {
            for(k = 0; k < 4; k++)
            {
                xx = x + dirx[k]*i; yy = y + diry[k]*j;
                //printf("%d  %d %d %d %d %d\n", x, y, i, j, xx, yy);
                b = (xx - 1) * m + yy;

                if(!inmap(xx, yy) || f[a][b])  continue;

                ct[a] ++;
                f[a][b] = 1;//printf("f[%d][%d] = %d\n", a, b, f[a][b]);
            }
        }
    }
}

void out()
{
    int i, j;
        printf("\n");
            for(i = 1; i <= n * m; i++)
        {
            for(j = 1; j <= n * m + 1; j++)
            {
                printf("%.0f ", f[i][j]);
            }
            printf("\n");
        }
}
void gauss()
{
    int i, j, k, high, now;
    double a, b, temp;
    for(i = 1; i <= m * n + 1; i ++)
        ans[i] = 0;

    now = 1;
    for(i = 1; i <= n * m && now <= m * n; i++, now++)
    {
        high = i;
        for(j = i + 1; j <= n * m; j++)
            if(fabs(f[j][now] > fabs(f[high][now])))  high = j;
        if(i != high)
            for(k = 1; k <= n * m + 1; k++) swap(f[i][k], f[high][k]);
        for(j = n * m + 1; j >= now; j--)
            f[i][j] /= f[i][now];

        for(j = i + 1; j <= n * m; j++)
        {
            if(fabs(f[j][now]) < eps)  continue;

            a = fabs(f[i][now]);
            b = fabs(f[j][now]);
            if(f[j][now] * f[i][now] < -eps)   b = -b;
            for(k = now; k <= m * n + 1; k++)
            {
                f[j][k] = f[j][k] * a - f[i][k] * b;
            }
        }//out();
    }


    for(i = m * n; i >= 1; i--)
    {
        temp = f[i][m * n + 1];
        for(j = i + 1; j <= m * n; j++)
        {
            if(fabs(f[i][j]) > eps)    temp -= f[i][j] * ans[j];
        }
        ans[i] =  temp / f[i][i];
    }

}
void contri()
{
    int i, j;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            go(i, j);
        }
    }
}
int main(void)
{
    //freopen("orz.txt", "w", stdout);
    int i, j, TC = 1;
    while(scanf("%d%d%d", &m, &n, &d) && (n || m || d))
    {
        init();
        if(TC > 1)  printf("\n");   TC++;
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                scanf("%lf", &t[(i - 1) * m + j]);

        contri();
        for(i = 1; i <= n * m; i++)
            f[i][n * m + 1] =  t[i] * ct[i];
//        for(i = 1; i <= n * m; i++)
//        {
//            for(j = 1; j <= n * m + 1; j++)
//            {
//                printf("%.0f ", f[i][j]);
//            }
//            printf("\n");
//        }
        gauss();

    //printf("~~\n");
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                printf("%8.2f", ans[(i - 1) * m + j]+eps);
            }
            printf("\n");
        }

    }
    return 0;
}
