#include <stdio.h>

int main(void)
{
    int l, c, num, m, s, e;
    while(scanf("%d%d", &l, &m) && (l || m))
    {
        num = (l + 1);
        while(m--)
        {
            scanf("%d%d", &s, &e);
            num -= (e - s + 1);
        }
        printf("%d\n", num);
    }
    return 0;
}
