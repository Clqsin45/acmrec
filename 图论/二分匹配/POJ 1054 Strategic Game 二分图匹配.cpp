#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

#define MAX 1555
int match[MAX], n;
bool v[MAX];
vector<int>map[MAX];

int dfs(int x)
{
    int i, u;
    for(i = 0; i < map[x].size(); i++)
    {
        u = map[x][i];
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
        for(i = 0; i < MAX; i++)    map[i].clear();
        for(i = 0; i < n; i++)
        {
            scanf("%d:(%d)", &st1, &st2);
            while(st2--)
            {
                scanf("%d", &stt);
                map[st1].push_back(stt);
                map[stt].push_back(st1);
            }
        }
        ans = 0;
        memset(match, -1, sizeof(match));
        for(i = 0; i < n; i++)
        {
            memset(v, 0, sizeof(v));
            ans += dfs(i);
        }
        printf("%d\n", ans / 2);
    }
    return 0;
}
