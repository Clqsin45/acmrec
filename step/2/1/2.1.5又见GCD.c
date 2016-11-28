#include <stdio.h>

#define MAX 1000002

int gcd(int x, int y)
{
    return (y == 0 ? x : gcd(y, x % y));
}
int main(void)
{
    int n, a, c, t, i;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d%d", &a, &c);

        for(i = 2*c; i < MAX; i += c)
        {
            if (gcd(a, i) == c ) break;
        }
        printf("%d\n", i);

    }
    return 0;
}
