#include <stdio.h>
#include <math.h>
int main(void)
{
    int x, y, a;
    scanf("%d%d%d", &x, &y, &a);
    //printf("%d\n", (int)(ceil((double)x / a)));
    printf("%I64d\n", (__int64)ceil((double)x / a) * (__int64)ceil((double)y / a));
    return 0;
}
