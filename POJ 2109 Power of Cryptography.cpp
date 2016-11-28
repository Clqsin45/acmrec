#include <cstdio>
#include <cmath>
int main(void)
{
    double d, n;
    while(scanf("%lf%lf", &d, &n) != EOF)
    {
        printf("%.0lf\n",exp(log(n)/d));
    }
    return 0;
}
