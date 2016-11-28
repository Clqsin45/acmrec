#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct cow
{
    int s;  int e;     int pos;
}p[100005];
int c[100005], n, f[100005];
bool cmp(cow a, cow b)
{
    return (a.e > b.e)||(a.e == b.e && a.s < b.s);
}
int lowbit(int x)
{
    return x & (-x);
}
void modify(int x)
{
    for(; x <= n; x += lowbit(x))
        f[x]++;
}

int getsum(int x)
{
    int sum = 0;
    for(; x > 0; x -= lowbit(x))
        sum += f[x];
    return sum;
}
int main(void)
{
    int t, i;
    while(scanf("%d", &n) && n)
    {
        memset(f, 0, sizeof(f));
        for(i = 1; i <= n ; i++)
        {
            scanf("%d%d", &p[i].s, &p[i].e);
            p[i].pos = i;
        }
        sort(p + 1, p + n + 1, cmp);
        c[p[1].pos] = 0;
        modify(p[1].s + 1);
        for(i = 2; i <= n; i++)
        {
            if(p[i].e == p[i - 1].e && p[i].s == p[i - 1].s)
                c[p[i].pos] = c[p[i-1].pos];
            else
                c[p[i].pos] = getsum(p[i].s + 1);
            modify(p[i].s + 1);
        }
        for(i = 1; i < n; i++)
            printf("%d ", c[i]);
        printf("%d\n",c[i]);


    }
    return 0;
}

}
