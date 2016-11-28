#include <stdio.h>

int gcd(int x, int y)
{
    return (y == 0 ? x : gcd(y, x % y));
}
int fd(int x, int y)
{
    return x / gcd(x, y) * y;
}
int main(void)
{
    int n, t, a, b, c, d;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d/%d %d/%d",&a, &b, &c, &d);
        t = gcd(a, b);
        a /= t;     b /= t;
        t = gcd(c, d);
        c /= t;     d /= t;

        if(gcd(b, d) == 1)  printf("%d\n",fd(a, c));
        else printf("%d/%d\n", fd(a, c), gcd(b,d));
    }
    return 0;
}
