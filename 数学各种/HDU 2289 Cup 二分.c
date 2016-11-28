#include <stdio.h>
#define pai 3.14159265
#define min 1e-12

int main(void)
{
    int t;
    double rb, rt, v, height, left, right, dr, mid, rn;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf", &rb, &rt, &height, &v);
        dr = (rt - rb) / height;
        left = 0;   right = height;
        while(right - left > min)
        {
            mid = (left + right) / 2;
            rn = rb + mid * dr;
            if((rb*rb + rn*rn + rn*rb)*mid*pai/3 > v)   right = mid;
            else left = mid;
        }
        printf("%f\n", mid);
    }

    return 0;
}
