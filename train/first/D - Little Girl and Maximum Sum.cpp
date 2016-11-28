#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 200004
#define II __int64
II a[MAX], f[MAX] = {0};
int main(void)
{
    II sum = 0;

    int n, q, i, st1, st2;
    scanf("%d%d", &n, &q);
    for(i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    while(q--)
    {
        scanf("%d%d", &st1, &st2);
        f[st1] ++;  f[st2 + 1] --;
    }
    for(i = 1; i <= n; i++)
    {
        sum += f[i];
        f[i] = sum;
    }
    sort(f + 1, f + 1 + n);
    sum = 0;
    for(i = 1; i <= n; i++)
        sum += (a[i] *f[i]);
    printf("%I64d\n", sum);
    return 0;
}
