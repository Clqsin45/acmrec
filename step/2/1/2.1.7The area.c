#include <stdio.h>
#include <math.h>
#define sp 100002;
struct point
{
    double x ;  double y;
}p[3];

int main(void)
{
    int n, i;
    double k, a, j, gp, sum;
    scanf("%d", &n);
    while(n--)
    {
        sum = 0;
        for(i = 0; i < 3; i++)  scanf("%lf%lf", &p[i].x, &p[i].y);
        k = (p[2].y - p[1].y)/(p[2].x - p[1].x);
        a = (p[1].y - p[0].y)/((p[1].x - p[0].x) * (p[1].x - p[0].x));
        gp = (p[2].x - p[1].x)/sp;

        for(j = p[1].x; j <= p[2].x; j += gp)
        {
            sum += gp*(a*pow(j-p[0].x,2.0)+p[0].y-k*j+p[1].x*k-p[1].y);
        }
        printf("%.2f\n",sum);

    }

    return 0;
}
