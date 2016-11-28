#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 100002

int f[MAX], id[MAX], num[MAX], n;
struct point
{
    int no, val;
}p[MAX];

inline int lowbit(int x)
{
    return x & (-x);
}
inline int findmax(int x, int y)
{
    return x > y ? x : y;
}

bool cmp(point a, point b)
{
    if(a.val == b.val)  return a.no > b.no ;
    return a.val < b.val;
}


int require(int l)
{
    int ans = 0;
    while(l > 0)
    {
        if(id[l] > ans) ans = id[l];
        l -= lowbit(l);
        //printf("!!%d\n", l);
    }
    return ans;
}
void modify(int loc, int v)
{
    int i, j;
    while(loc <= n)
    {
        if(id[loc] < v) id[loc] = v;
        loc += lowbit(loc);
    }
}

int main(void)
{
    int d, i, j, max, ans;
    while(scanf("%d%d", &n, &d) != EOF)
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &p[i].val);
            p[i].no = i;
            id[i] = num[i] = 0;
        }
        sort(p + 1, p + n + 1, cmp);
        for(i = 1; i <= n; i++)
            f[p[i].no] = i;

        ans = 1;

        for(i = 1; i <= n; i++)
        {
            j = f[i] - 1;
            max = require(j) + 1;

            ans = findmax(ans, max);
            num[i] = max;
            j = i - d - 1;
            //printf("%d\n", j);
            if(j >= 0)
            {
                //printf("%d\n", j);
                modify(f[j + 1], num[j + 1]);
            }

        }

        printf("%d\n", ans);
    }
    return 0;
}
