#include <stdio.h>
#define min 1e-10
#define INF 100000
double a[10002], b[10002], c[10002];
int n;
double cal(double x)
{
    int i;
    double max =-0x7FFFFFFF, y;
    for(i = 1; i <= n; i++)
    {
        y = a[i]*x*x+b[i]*x+c[i];
        if(y > max) max = y;
    }
    return max;
}

int main(void)
{
    int t, i;
    double right, left, mid1, mid2;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
        {
            scanf("%lf%lf%lf", &a[i], &b[i], &c[i]);
        }
        left = 0;    right = 1000;
        while(right - left > min)
        {
            mid1 = (2*left + right) / 3;
            mid2 = (right*2 + left) / 3;
            if(cal(mid1) > cal(mid2))   left = mid1;
            else right = mid2;
        }

        printf("%.4f\n",cal(left));
    }

    return 0;
}
