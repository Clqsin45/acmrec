#include <stdio.h>
#include <string.h>
int d[1000000];
int main(void)
{
    int n, t, i;
    while(scanf("%d", &n) && n)
    {
        d[1] = 1;  i = 2;
        while(d[i - 1] != 0)
        {
            d[i] = (d[i / 2] * 10 + i % 2) % n;
            i++;
        }
        i--;
        t = 0;
        while(i)
        {
            d[t++] = i % 2;
            i /= 2;
        }
        for(i = t - 1; i >= 0; i--)
            printf("%d",d[i]);
        printf("\n");
    }
    system("pause");
    return 0;
}
