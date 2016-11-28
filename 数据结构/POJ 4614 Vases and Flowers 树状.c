#include <stdio.h>
#include <string.h>
//TIME LIMIT
int a[50005], c[50005], n, m;

int lowbit(int x)
{
    return x & (-x);
}
int getsum(int x)
{
    int sum = 0;
    for(; x > 0; x -= lowbit(x))
        sum += c[x];
    return sum;
}

void modify(int x, int k)
{
    for(; x <=n; x += lowbit(x))
    {
        c[x] += k;
    }
}

void find(int x, int y)
{
    int min, max, mid, i, st, j, cp;

    cp = n - x + 1 - getsum(n) + getsum(x - 1);
    if(cp <= 0)
    {
        printf("Can not put any one.\n");
        return;
    }
    if(cp >= y)
        cp = y;
    for(i = x; a[i] != 0; i++);
    printf("%d",i - 1);
    st = getsum(i - 1);
    max = n ;    min = i;
    while(min < max)
    {
        mid = (max + min) / 2;
        if(!a[mid] && (mid - i + 1 - getsum(mid) + st) == cp)
        {
            max = mid;
            break;
        }
        if(mid - i + 1 - getsum(mid) + st < cp)
            min = mid + 1;
        else
            max = mid;
    }
    for(j = i; j <= max; j++)
    {
        if(!a[j])
        {
            a[j] = 1;
            modify(j, 1);
        }
    }
    printf(" %d\n", max - 1);

}
int main(void)
{
    int t, x, y, op, i, j, st;
    scanf("%d", &t);
    while(t--)
    {
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
        scanf("%d%d", &n, &m);

        for(i = 1; i <= m; i++)
        {
            scanf("%d%d%d",&op, &x, &y);
            if(op == 1)
            {
                x++;
                find(x, y);
            }
            else if(op == 2)
            {
                x ++;   y++;
                st = getsum(y) - getsum(x -1);
                printf("%d\n", st);
                for(j = x; j <= y; j++)
                {
                    if(a[j])
                    {
                        a[j] = 0;
                        modify(j, -1);
                    }
                }
            }

        }
    }
    return 0;
}
