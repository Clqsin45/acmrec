#include <stdio.h>
int main(void)
{
    int n, x, st;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &x);    st = x & (-x) ;
        printf("%d %d\n", x - st + 1, x + st - 1);
    }
    return 0;
}
