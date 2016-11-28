#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 1000004
#define INF 0x7f7f7f7
#define LL __int64

const LL mod = 1000000007;
LL f[MAX];

LL quickpowm(LL x, LL a)
{
    LL temp = 1;
    x %= mod;
    while(a)
    {
        if(a & 1)   temp = temp * x % mod;
        x = x * x % mod;
        a >>= 1;
        //printf("%I64d\n", temp);
    }
    //printf("%d\n", temp);
    return temp;
}

bool check(int a, int b, int x)
{
    int temp;
    while(x > 0)
    {
        temp = x % 10;
        if(temp != a && temp != b)  return false;
        x /= 10;
    }
    return true;
}

int main(void)
{
    int i, n, a, b, x, y, sum;
    LL ans = 0, temp;
    f[0] = 1;
    scanf("%d%d%d", &a, &b, &n);
    for(i = 1; i <= n; i++)
        f[i] = f[i - 1] * i % mod;
    for(i = 0; i <= n; i++)
    {
        x = i;  y = n - i;
        sum = a * x + b * y;
        if(check(a, b, sum))
        {
            temp = f[n] * quickpowm(f[y] * f[x], mod - 2) % mod;

            ans = (ans + temp) % mod;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
