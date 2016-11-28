#include <stdio.h>

int main(void)
{
    int a, b, i = 0;
    while(scanf("%d%d", &a, &b) == 2)
    {
        //if(i)   printf("\n");
        printf("%d\n\n",a + b);
        i++;
    }
    system("pause");
    return 0;
}
