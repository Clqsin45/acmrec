#include <stdio.h>

int main(void)
{
    int n, sum, a;
    while(scanf("%d", &n) && n)
    {
        sum = 0;
        while(n -- )
        {
            scanf("%d", &a);
            sum += a;
        }
        printf("%d\n",sum);
    }
    system("pause");
    return 0;
}
