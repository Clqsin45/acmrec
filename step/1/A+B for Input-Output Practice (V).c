#include <stdio.h>

int main(void)
{
    int t ,n, sum, a;
    scanf("%d", &t);
    while(t--)
    {
        sum = 0;
        scanf("%d", &n);
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
