#include <stdio.h>
#include <math.h>
int f[22] = {0};
int main(void)
{
    int i;
    double x;
    f[0] = 0;     f[1] = 1;
    for(i = 2; i <= 20; i++)    f[i] = f[i - 1] + f[i - 2];

    while(scanf("%d", &i) != EOF)
    {
        if(i <= 20)
        {
            printf("%d\n", f[i]);
            continue;
        }
        x = -0.5*log10(5) + i * log10((1 + sqrt(5))/2);
        x = pow(10.0, x - floor(x));
        while(x < 1000) x *= 10;
        printf("%d\n",(int)x);
    }

    return 0;
}
