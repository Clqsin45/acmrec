#include <stdio.h>
#include <vector>
using namespace std;
#define MAX 100004

vector<int>p[MAX];
int f[MAX], dis;

inline int findmax(int x, int y)
{
    return x > y ? x : y;
}
void dfs(int x, int fa)
{
    int i, y, s = p[x].size(), twai = 0;
    f[x] = 0;
    for(i = 0; i < s; i++)
    {
        y = p[x][i];
        if(y == fa) continue;
        dfs(y, x);
        if(f[y] + 1 >= f[x])
        {
            twai = f[x];
            f[x] = f[y] + 1;
        }
        else if(f[y] + 1 > twai)
            twai = f[y] + 1;
    }
    dis = findmax(dis, f[x] + twai);
}
int main(void)
{
    int CT, i, m, k, n, st1, st2;
    scanf("%d", &CT);
    while(CT--)
    {
        dis = 0;
        scanf("%d%d", &n, &m);
        for(i = 1; i < n; i++)
        {
            scanf("%d%d", &st1, &st2);
            p[st1].push_back(st2);
            p[st2].push_back(st1);
        }
        dfs(1, 0);
        while(m--)
        {
            scanf("%d", &k);
            if(k <= dis)    printf("%d\n", k - 1);
            else printf("%d\n", 2 * k - dis - 2);
        }
        for(i = 1; i <= n; i++) p[i].clear();
    }
    return 0;
}
