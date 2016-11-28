#include <stdio.h>
#include <vector>
using namespace std;
#define MAX 100004
vector<int>p[MAX];
int limit, sum;

void dfs(int x, int fa, int now)
{
    int i, s = p[x].size(), y;
    for(i = 0; i < s; i++)
    {
        y = p[x][i];
        if(y == fa) continue;
        if(now < limit) dfs(y, x, now + 1);

    }
    sum ++;
}
int main(void)
{
    int TC, n, m, i, st1, st2;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d%d", &n, &limit);
        for(i = 1; i < n; i++)
        {
            scanf("%d%d", &st1, &st2);
            p[st1].push_back(st2);
            p[st2].push_back(st1);
        }
        sum = 0;
        dfs(0, -1, 0);
        for(i = 0; i < n; i++)  p[i].clear();
        printf("%d\n", n - sum);

    }
    return 0;
}
