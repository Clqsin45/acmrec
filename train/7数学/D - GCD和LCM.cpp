#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define MAX
#define N 100004
#define INF 0x3f7f7f7f
#define LL __int64

int f[N], no;
LL n, m;

void cal(void)
{
    int temp = (int)sqrt(m);
    int i;
    no = 0;
   // printf("%d\n", temp);
    for(i = 2; i <= temp; i++)
    {
        if(m % i)continue;
        f[++no] = 0;

        while(!(m % i))
        {
            f[no]++;    m /= i;
        }
       // printf("%d  %d  %I64d\n", i, f[no], m);
       if(m == 1)   break;
    }
    if(m != 1)   f[++no] = 1;    //ËØÊý
}

int main(void)
{

    int i, TC;
    LL ans;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%I64d%I64d", &n, &m);
        if(m % n)
        {
            printf("0\n");
            continue;
        }
        m /= n;
        cal();

        for(i = 1, ans = 1; i <= no; i++)
            //ans *= ((f[i]+1)*(f[i]+1)*(f[i]+1) - 2*f[i]*f[i]*f[i] + (f[i]-1)*(f[i]-1)*(f[i]-1));
            ans *= (6 * f[i]);
        printf("%I64d\n", ans);
    }
    return 0;
}
