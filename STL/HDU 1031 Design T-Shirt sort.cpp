#include <stdio.h>
#include <algorithm>
using namespace std;
struct T
{
    int no;    double v;
}ts[100002];

bool cmp(T a, T b)
{
    return a.v > b.v ;
}

bool ccp(T a, T b)
{
    return a.no>b.no;
}
int main(void)
{
    int n, m, k, i, j;
    double st;
    while(scanf("%d", &n) != EOF)
    {
        scanf("%d%d", &m, &k);
        for(i = 1; i <= m; i++)
        {
            ts[i].no = i;   ts[i].v = 0;
        }
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <=m; j++)
            {
                scanf("%lf", &st);
                ts[j].v += st;
            }
        }
        sort(ts + 1, ts + m+1, cmp);

        sort(ts + 1, ts + k + 1, ccp);
        for(i = 1; i < k; i++) printf("%d ", ts[i].no);
        printf("%d\n", ts[k].no);
    }
    return 0;
}
