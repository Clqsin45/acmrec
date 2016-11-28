#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 10001000
using namespace std;

struct point
{
    int x;  int y;
}p[INF];

int a[INF];

bool cmp(point a, point b)
{
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

int lowbit(int x)
{
    return x & (-x);
}

long long getsum(int x)
{
    long long sum = 0;
    for(; x > 0; x -= lowbit(x))
        sum += a[x];
    return sum;
}

void modify(int x)
{
    for(; x <= INF; x += lowbit(x))
        a[x] ++;
}

int main(void)
{
    int t, n, m, k, max, i, ct = 1;
    long long sum;
    scanf("%d", &t);
    while(t--)
    {
        max = 0;
        scanf("%d%d%d", &n, &m, &k);
        memset(a, 0, sizeof(a));
        for(i = 1; i <= k; i++)
        {
            scanf("%d%d", &p[i].x, &p[i].y);
        }
        sort(p + 1, p + k + 1, cmp);
        sum = 0;
        for(i = 1; i <= k; i++)
        {
            sum += (getsum(m) - getsum(p[i].y));
            modify(p[i].y);
        }
        printf("Test case %d: %lld\n",ct ,sum);
        ct++;
    }

    return 0;
}
