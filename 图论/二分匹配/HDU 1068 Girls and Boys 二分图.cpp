#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 555

int match[MAX], n;
bool v[MAX];
vector<int>f[MAX];

int dfs(int x)
{
    int i, u;
    for(i = 0; i < f[x].size(); i++)
    {
        u = f[x][i];
        if(!v[u])
        {
            v[u] = 1;
            if(match[u] == -1 || dfs(match[u]))
            {
                match[u] = x;
                return 1;
            }
        }
    }
    return 0;
}
int main(void)
{
    int i, st1, st2, stt, ans;
    while(scanf("%d", &n) != EOF)
    {
        memset(match, -1, sizeof(match));

        for(i = 0; i <= n; i++) f[i].clear();
        for(i = 1; i <= n; i++)
        {
            scanf("%d: (%d)", &st1, &stt);
            while(stt--)
            {
                scanf("%d", &st2);
                f[st1].push_back(st2);
            }
        }
        ans = 0;
        for(i = 0; i < n; i++)
        {
            memset(v, 0, sizeof(v));
            ans += dfs(i);
        }
        printf("%d\n", n - ans / 2);
    }
    return 0;
}
