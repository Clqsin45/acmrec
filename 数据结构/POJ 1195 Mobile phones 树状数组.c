#include <stdio.h>
#include <string.h>
#define MAX 1044
int map[MAX][MAX], a[MAX][MAX], n;

int lowbit(int x)
{
    return x & (-x);
}
long long getsum(int x, int y)
{
    int a, b;
    long long sum = 0;
    for(a = x; a > 0; a -= lowbit(a))
        for(b = y; b > 0; b -= lowbit(b))
            sum +=map[a][b];
    return sum;
}
void modify(int x, int y, int k)
{
    int a, b;
    for(a = x; a <= n; a += lowbit(a))
        for(b = y ; b <=n ; b += lowbit(b))
            map[a][b] += k;
}
int main(void)
{
    int op, x1, y1, x2, y2, m, i, j;
    long long sum;
    scanf("%d%d",&op, &n);
    memset(map, 0, sizeof(map));
    memset(a, 0, sizeof(a));
    while(scanf("%d", &op))
    {
        if(op == 3) break;
        else if(op == 1)
        {
            scanf("%d%d%d", &x1, &y1, &m);
            x1++;    y1++;
            if(a[x1][y1] + m < 0)
            {
                a[x1][y1] = 0;
                modify(x1, y1, -a[x1][y1]);
            }
            else
            {
                a[x1][y1] += m;
                modify(x1, y1, m);
            }
        }
        else if(op == 2)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            sum = 0;
            x1++;   x2++;   y1++;   y2++;
            sum += getsum(x2, y2);
           // printf("%lld\n", sum);
            sum -= getsum(x2, y1 - 1);
           // printf("%lld\n", sum);
            sum -= getsum(x1 - 1, y2 );
           // printf("%lld\n", sum);
            sum += getsum(x1 -1, y1 - 1);
            printf("%lld\n", sum);
        }
    }
    return 0;
}
