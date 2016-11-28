#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MD 1000005
#define LL long long
#define INF 0x3f7f7f7f
int f[44] = {0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575};
int v[MD] = {0}, ans[MD];
int main()
{
    int i, n,  a , b;
    __int64 sum = 0;
    scanf("%d", &n);
    for(i = n; i >= 1; i--)
    {
        if(v[i])    continue;
        a = 0;  b = i;
        while(b)
        {
            a++;    b>>= 1;
        }
        b = f[a] ^ i;
            sum += (f[a] * 2);
            v[b] = v[i] = 1;
        ans[b] = i; ans[i] = b;
    }
    printf("%I64d\n", sum);
    for(i = 0; i <= n; i++)
        printf("%d%c", ans[i], i == n ? '\n': ' ');

}
