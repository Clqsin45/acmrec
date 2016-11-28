#include <stdio.h>

#define MAX 304
#define INF 0x7f7f7f7f

int f[MAX][MAX], a[MAX], b[MAX];
int m, p;
int judge(int i, int j, int k)
{
    if(a[k] - a[i] + b[i] - b[j] > m || b[k] - b[i] > m)   return 1;    // 爆工资了233333好评
    return 0;
}
int main(void)
{
    int st1, st2;
    int i, j, k;
    while(scanf("%d%d", &m, &p) != EOF)
    {
        a[0] = b[0] = 0;
        for(i = 1; i <= p; i++)
        {
            scanf("%d%d", &st1, &st2);
            a[i] = a[i - 1] + st1;      //累加做到第i题预付
            b[i] = b[i - 1] + st2;      //i 后付
        }
        for(i = 0; i <= p; i++)
            for (j = 0; j <= p; j++)    f[i][j] = INF;
        f[0][0] = 0;    //做0题不用时间

        for(i = 0; i <= p; i++) //解决i道题 0-p
        {
            for(j = 0; j <= i; j++)
            //for(j' = i; j' >= 0; j'--) // j' = i - j
            {
                for(k = i; k <= p; k++)     //做itok题，之前上个月是j - i
                {
                    if(judge(i, j, k))  break;
                    f[k][k - i] = (f[k][k - i] < f[i][i - j] + 1 ? f[k][k - i] : f[i][i - j] + 1);
                }
            }
        }
        printf("%d\n", f[p][0] + 1);
    }
    return 0;
}
/*
|---j---i---k---------------|
| | | | | | | | | | | | ||
|------------------------|
*/
//半夜不宜写DP， 一坨浆糊。。。
