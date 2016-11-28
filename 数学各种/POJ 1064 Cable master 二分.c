#include <stdio.h>
#define INF 1000000
int n, k;
double a[100002], max;

int count(int l)
{
    int i , sum = 0;
    for(i = 1; i <= n; i++)
    {
        sum +=  (int)(a[i]/l);
    }
    return sum;
}
int solve(int sum)
{
    int left = 0, right = sum, mid;
    max = 0;

    while(left <= right)
    {
        mid = (left + right) / 2;
        if(count(mid) >= k)
        {

            max = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
}
int main(void)
{
    int  i, b = 0;
    double st;
    scanf("%d%d", &n, &k);
    for(i = 1; i <= n; i++)
    {
        scanf("%lf", &st);
        a[i] = (int)((st)  * 100);
        if(b < a[i]) b = a[i];
    }
    solve(b);
    max *= 0.01;
    printf("%.2f\n", max);
    return 0;
}
