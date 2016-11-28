#include <stdio.h>
#include <string.h>

int map[102][102], m, n;
int lowbit(int x)
{
    return x & (-x);
}
void modify(int x, int y)
{
    int a, b;
    for(a = x; a <= m; a += lowbit(a))
        for(b = y; b <= n; b += lowbit(b))
            map[a][b]++;
    return;
}
int getsum(int x, int y)
{
    int a, b, sum = 0;
    for(a = x; a > 0; a -= lowbit(a))
        for(b = y; b > 0; b -= lowbit(b))
            sum+=map[a][b];
    return sum;
}
int main(void)
{
    int i, t, x, y, sum, max;
    int x1, x2, y1, y2;
    while(scanf("%d", &t) && t)
    {
        scanf("%d%d", &n, &m);
        max = 0;
        memset(map, 0, sizeof(map));
        for(i = 1; i <= t; i++)
        {
            scanf("%d%d", &y, &x);
            modify(x, y);
        }
        scanf("%d%d", &y, &x);
        for(x1 = 1; x1 <= m + 1 - x; x1++)
        {
            for(y1 = 1; y1 <= n + 1 - y; y1++)
            {
                x2 = x1 + x - 1;
                y2 = y1 + y - 1;
                sum = 0;
                sum += getsum(x2, y2);
                sum -= getsum(x2, y1 - 1);
                sum -= getsum(x1 - 1, y2 );
                sum += getsum(x1 -1, y1 - 1);
                if(sum > max)   max =sum;
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
