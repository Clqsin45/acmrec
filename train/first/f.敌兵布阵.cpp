#include <stdio.h>
#include <string.h>
int c[50005], n;
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
    for(; x <= n; x += lowbit(x))
        c[x] += k;
}
int main(void)
{
    int t, st, i,x ,y, ct = 1;
    char op[10];
    scanf("%d", &t);
    while(t--)
    {
        memset(c, 0, sizeof(c));
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &st);
            modify(i, st);
        }
        printf("Case %d:\n",ct);
        while(scanf("%s",op))
        {
            if(strcmp(op,"End") == 0)
                break;
            scanf("%d%d", &x, &y);
            if(strcmp(op,"Query") == 0)
            {
                printf("%d\n",getsum(y) - getsum(x - 1));
            }
            else if(strcmp(op, "Add") == 0)
                modify(x, y);
            else if(strcmp(op, "Sub") == 0)
                modify(x, -y);
        }
        ct++;
    }
    return 0;
}
