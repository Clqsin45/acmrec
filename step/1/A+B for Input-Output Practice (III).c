#include <stdio.h>

int main(void)
{
    int a, b;
    while(scanf("%d%d", &a, &b) && (a || b))
        printf("%d\n", a+ b);
    system("pause");
    return 0;
}
