#include <stdio.h>
#include <math.h>
int main(void)
{
    int c;
    double n, st;
    scanf("%d", &c);
    while(c--)
    {
        scanf("%lf", &n);
        st = n * (log10(n));
        printf("%d\n",(int)pow(10.0,st-floor(st)));
    }
    return 0;
}
