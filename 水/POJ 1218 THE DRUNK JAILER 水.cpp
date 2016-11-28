#include <stdio.h>
#include <string.h>
int f[111] = {0};
int main(void)
{
    int T, i, n, num, j;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        memset(f, 0, sizeof(f));
        num = 0;

        for(i = 1; i <= n; i++)
        {
            for(j = i; j <= n; j +=i)
            {
                f[j] = !f[j];
                num += (f[j] == 1 ? 1 : -1);
            }
        }
        printf("%d\n", num);
    }
    return 0;
}
