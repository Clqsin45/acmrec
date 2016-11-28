#include <stdio.h>
#include <algorithm>
using namespace std;
int a[11111];
int main(void)
{
    int n, i;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    printf("%d\n", a[(1 + n) >> 1]);
    return 0;
}
