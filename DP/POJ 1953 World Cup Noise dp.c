#include <stdio.h>
#include <string.h>

__int64 f[50];
int main(void)
{
    int i, n, ct = 1, t;
    f[1] = 2;   f[0] = 0;   f[2] = 3;
    for(i = 3; i <= 45; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        //printf("%I64d\n", f[i]);
    }
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("Scenario #%d:\n%I64d\n\n",ct, f[n]);
        ct++;
    }
    return 0;
}
