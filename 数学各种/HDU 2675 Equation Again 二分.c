#include <stdio.h>
#include <math.h>
#define e 2.718281828459
#define min 0.00000001
double k;

int main(void)
{
    double y, x, left, right, mid, mid1, mid2;
    while(scanf("%lf", &y) != EOF)
    {
        k = (1+log(y))/(e *  y);

        left = 0;   right  = e;
        while(right - left > min)
        {
            mid1 = (left + right) / 2;
            if(log(mid1) / mid1 < k )
            {
                left = mid1;
            }
            else right = mid1;
        }
        left = e;   right = 1000000;
        while(right - left > min)
        {
            mid2 = (left + right) / 2;
            if(log(mid2) / mid2 - k > 0)
                left = mid2;
            else right = mid2;
        }
        if(y == 1)   printf("%.5f\n", mid2);
        else if(mid2 > mid1) printf("%.5f %.5f\n",mid1, mid2);
        else if(mid2 < mid1) printf("%.5f %.5f\n", mid2, mid1);
    }
    return 0;
}
