#include <stdio.h>

#define pai 3.1415927
#define ch 63360
int main(void)
{
    double d, t;
    int n, c = 1;
    while(scanf("%lf %d %lf", &d, &n, &t) && n)
    {
        printf("Trip #%d: %.2f %.2f\n", c, pai * d * n / ch,  pai * d * n  / (t * ch) * 3600);
        c++;
    }
    return 0;
}
