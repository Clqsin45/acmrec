#include <stdio.h>

int main(void)
{
    int a, b;
    while(scanf("%d%d", &a, &b) == 2)
        printf("%d\n", a+ b);
    system("pause");
    return 0;
}
