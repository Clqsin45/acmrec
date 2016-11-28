#include <stdio.h>
#include <math.h>

int main(void)
{
    int t, n;
    double d;
    scanf("%d", &t);
    while(t--)
    {
        d = 0;
        scanf("%d", &n);
        while(n > 1)
        {
            d += log10(n);
            n--;
        }
        printf("%d\n",(int)d + 1);
    }
    return 0;
}
