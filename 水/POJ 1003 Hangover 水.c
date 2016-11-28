#include <stdio.h>
double t[300];
int main(void)
{
    int i;
    double sum = 0;
    for(i = 1; i <= 300; i++)
    {
        sum += 1.0 / (i + 1);
        t[i] = sum;
    }
    while(scanf("%lf", &sum))
    {
        if(sum == 0.0)  break;
        for(i = 1; t[i] < sum; i++);
            printf("%d card(s)\n",i);
    }
    system("pause");
    return 0;
}
