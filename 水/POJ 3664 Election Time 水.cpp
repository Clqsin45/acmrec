#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 51111
struct point
{
    int a, b, no;
}c[MAX];

bool cmp(point x, point y)
{
    return x.a > y.a;
}
int main(void)
{
    int n, k, max= 0, i;
    scanf("%d%d", &n, &k);
    for(i = 1; i <= n; i++)
    {
        scanf("%d%d", &c[i].a, &c[i].b);
        c[i].no = i;
    }
    sort(c + 1, c + 1 + n, cmp);
    max = 1;
    for(i = 1; i <= k; i++)
    {
        max = c[max].b > c[i].b ? max : i;
    }
    printf("%d\n", c[max].no);
    return 0;
}
