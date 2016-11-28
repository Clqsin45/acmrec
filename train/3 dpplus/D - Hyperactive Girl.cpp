#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 111
#define MO 100000000
int f[MAX][MAX];
struct point
{
    int s, e;
}w[MAX];

bool cmp(point a, point b)
{
    if(a.e == b.e)  return a.s > b.s;
    return a.e < b.e;
}
int main(void)
{
    int m, n, i, j, st1, st2, ans, k;
    while(scanf("%d%d", &m, &n) && (m || n))
    {
        ans = 0;    k = 0;
        memset(f, 0, sizeof(f));
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d", &st1, &st2);
            if(st1 == 0 &&  st2 == m)
                ans++;
            else
            {
                w[++k].s = st1;
                w[k].e = st2;
            }
        }
        sort(w + 1, w + k + 1, cmp);

        n = k;
        for(i = 1; i <= n; i++)
        {
            for(j = i - 1; j >= 1; j--)
            {
                if(w[j].e < w[i].s ) break;
                if((w[i].s <= w[j].s&& w[i].e >= w[j].e))   continue;
                if(w[j].s == 0 ) f[j][i] = 1;
                for(k = j - 1; k >= 1; k--)
                {
                    if(w[k].e < w[j].s) break;
                    if((w[j].s <= w[k].s&& w[j].e >= w[k].e))   continue;
                    if(w[k].e < w[i].s)
                    {
                        f[j][i] += f[k][j];
                        //printf("k = %d  f[%d][%d] = %d\n", k, j, i, f[j][i]);
                    }
                }
                //printf("f[%d][%d] = %d\n",j, i, f[j][i]);
                if(w[i].e == m) ans += f[j][i];
            }
        }
        printf("%d\n", ans % MO);

    }
    return 0;
}
