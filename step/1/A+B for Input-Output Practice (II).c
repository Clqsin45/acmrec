#include <stdio.h>

int main(void)
{
    int a, b, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n",a+b);
    }

    system("pause");
    return 0;
}
