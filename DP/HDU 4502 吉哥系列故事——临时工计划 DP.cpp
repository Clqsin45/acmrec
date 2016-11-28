#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 111

struct work
{
    int s, e, c;
}w[MAX * 10];

int f[MAX];


int findmax(int x, int y)
{
    return x > y ? x : y;
}

bool cmp(work a, work b)
{
    return a.e < b.e;
}

int main(void)
{
    int TC, n, m, i, j;
    scanf("%d", &TC);
    while(TC--)
    {
        memset(f, 0, sizeof(f));
        scanf("%d%d", &m, &n);
        for(i = 1; i <= n; i++)
            scanf("%d%d%d", &w[i].s, &w[i].e, &w[i].c);
        sort(w + 1, w + n + 1, cmp);
        for(i = 1; i <= n; i++)
        {
            for(j = w[i].e; j <= m; j++)
            {
                f[j] = findmax(f[j], f[w[i].s - 1] + w[i].c);
            }
        }

        printf("%d\n", f[m]);
    }
    return 0;
}
