#include <stdio.h>

int gcd(int x, int y)
{
    return (y == 0 ? x : gcd(y, x % y));
}
int main(void)
{
    int a, b;
    while(scanf("%d%d", &a, &b))
    {
        if(a == -1 && b == -1) break;
        if(gcd(a, b) == 1)   printf("YES\n");
        else printf("POOR Haha\n");
    }
    return 0;
}
