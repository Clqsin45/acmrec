#include <stdio.h>
#define MAX  5005
unsigned __int64 x[MAX] = {0}, y[MAX] = {0}, z[MAX] = {0};
//�����unsigned __int64�Ļ������MOD���������Ǳ������Զ������ô
void prepro(void)
{
    int i, j;
    y[3] = x[0] = x[1] = x[2] = x[3] = 1;
    for(i = 4; i <= 5000; i++)
    {
        x[i] = 0;
        for(j = 2; j < i; j++)
            y[i] += x[j] * x[i - j + 1];
        for(j = 2; j < i - 1; j++)
            z[i] += x[j] * y[i - j + 1];
        x[i] = y[i] + z[i];
    }
}
int main(void)
{
    prepro();
    int n;
    while(scanf("%d", &n) != EOF)
    {
        printf("%I64u\n", x[n]);    //unsigned���
    }
    return 0;
}
