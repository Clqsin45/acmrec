#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX
#define INF 0x3f7f7f7f
#define LL __int64

int main(void)
{
    int TC, ans, temp;
    LL n;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%I64d", &n);
        temp = n % 10;  ans = 1;
        while(n)
        {
            if(n & 1)   ans = ans * temp % 10;
            temp = temp * temp % 10;
            n >>= 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
