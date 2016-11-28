#include <stdio.h>
#include <math.h>
#define II __int64


int main(void)
{
    int n, max = 0, temp, i;
    II cal, sum = 0;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        sum += temp;
        max = max > temp ? max : temp;
    }
    cal = ceil((double)sum / (n - 1));
    cal = max > cal ? max : cal;
    printf("%I64d\n", cal);

    return 0;
}
