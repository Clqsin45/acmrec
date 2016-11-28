#include <stdio.h>
#include <string.h>

int c[1002][1002], n;

int lowbit(int x)
{
    return x & (-x);
}
int getsum(int x, int y)
{
    int a, b, sum = 0;
    for(a = x; a > 0; a -= lowbit(a))
        for(b = y; b > 0; b -= lowbit(b))
            sum += c[a][b];
    return sum;
}

void modify(int x, int y, int k)
{
    int a, b;
    for(a = x; a <= n; a += lowbit(a))
        for(b = y; b <= n; b += lowbit(b))
            c[a][b] += k;
    return;
}

int main(void)
{
    int t, com, i, j, x1, x2, y1, y2, ct = 1;
    char op;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d", &n, &com);
        for(i = 0; i <= n; i++)
            for(j = 1; j <= n; j++)
                c[i][j] = 0;
        for(i = 1; i <= com; i++)
        {
            scanf(" %c",&op);
            if(op == 'C')
            {
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                x2++;   y2++;
                modify(x1, y1, 1);
                modify(x1, y2, -1);
                modify(x2, y1, -1);
                modify(x2, y2, 1);
            }
            else if(op == 'Q')
            {
                scanf("%d%d", &x1, &y1);
                printf("%d\n", getsum(x1, y1) % 2);
            }
        }
        if(t)   printf("\n");
    }

    return 0;
}
