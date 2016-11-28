#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define MAX 1600

int f[MAX][2], v[MAX];
vector<int>head[MAX];

int findmin(int x, int y)
{
    return x < y ? x : y;
}

void dfs(int x, int fa)
{
    int v = head[x].size(), i, y;
    for(i = 0; i < v; i++)
    {
        y = head[x][i];
        if(y == fa) continue;
        dfs(y, x);
    }

    f[x][0] = 0;    f[x][1] = 1;

    for(i = 0; i < v; i++)
    {
        y = head[x][i];
        if(y == fa) continue;
        f[x][0] += f[y][1];
        f[x][1] += findmin(f[y][0], f[y][1]);
    }
}
int main(void)
{
    int n, fa, i, num, next, ans;
    while(scanf("%d", &n) != EOF)
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%d:(%d)", &fa, &num);
            while(num--)
            {
                scanf("%d", &next);
                head[fa].push_back(next);
                head[next].push_back(fa);
            }
        }
        dfs(1, 1);
        ans = findmin(f[1][0], f[1][1]);
        for(i = 0; i < n; i++)  head[i].clear();
        printf("%d\n", ans);
    }
    return 0;
}
