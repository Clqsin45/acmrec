#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define MAX 500005
#define N 500000
#define INF 0x3f7f7f7f
#define LL __int64
LL f[MAX] = {0};

int main(void)
{
    int i, j, temp = N / 2;
    int TC, n;
    for(i = 1; i <= temp; i++)
    {
        for(j = 2; j * i<= N; j++)
            f[i * j] += i;
    }
    //for(i = 1; i <= 20; i++)    printf("%d  %I64d\n",i,  f[i]);
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d", &n);
        printf("%I64d\n", f[n]);
    }
    return 0;
}
