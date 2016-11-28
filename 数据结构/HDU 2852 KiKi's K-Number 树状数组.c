#include <stdio.h>
#include <string.h>
#define MAX 100002
int a[MAX], c[MAX];

int lowbit(int x)
{
    return x & (-x);
}

void modify(int x, int k)
{
    for(; x < MAX; x += lowbit(x))
        c[x] += k;
    return;
}

int getsum(int x)
{
    int sum = 0;
    for(; x > 0; x -= lowbit(x))
        sum += c[x];
    return sum;
}

int find(int x, int y)
{
    int st, min, max, mid;
    if(getsum(MAX - 1) - getsum(x) < y)     return 0;
    st = getsum(x);
    min = 1;    max = MAX;
    while(min < max)
    {
        mid = (min + max) / 2;
        if(a[mid] && getsum(mid) - st == y)
        {
            max = mid;
            break;
        }
        if(getsum(mid) - st < y)
        {
            min = mid + 1;
        }
        else max = mid;
    }
    printf("%d\n", max);
    return 1;
}

int main(void)
{
    int t, i, op, x, y;
    while(scanf("%d", &t) != EOF)
    {
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
        for(i = 1; i <= t; i++)
        {
            scanf("%d", &op);
            if(op == 0)
            {
                scanf("%d", &x);
                a[x]++;
                modify(x, 1);
            }
            else if(op == 1)
            {
                scanf("%d", &x);
                if(a[x] == 0)   printf("No Elment!\n");
                else
                {
                    modify(x, -1);
                    a[x]--;
                }
            }
            else if(op == 2)
            {
                scanf("%d%d", &x, &y);
                if(!find(x, y)) printf("Not Find!\n");
            }
        }

    }
    return 0;
}
