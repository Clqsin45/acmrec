#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
int f[120][120], match[120], res[55], n;
bool v[120];
vector<int>recx[55];
vector<int>recy[55];

int dfs(int x)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        if(!v[i] && f[x][i])
        {
            v[i] = 1;
            if(match[i] == -1 || dfs(match[i]))
            {
                match[i] = x;
                return 1;
            }
        }
    }
    return 0;
}
int main(void)
{
    int k, st, i, j, ans, ct, t;
    while(scanf("%d%d", &n, &k) && (n || k))
    {
        for(i = 1; i <= 50; i++)
        {
            recx[i].clear();
            recy[i].clear();
        }
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                scanf("%d", &st);
                recx[st].push_back(i);
                recy[st].push_back(j);
            }
        }
        ct = 0;
        for(i = 1; i <= 50; i++)
        {
            //printf("~~%d    %d\n", i, recx[i].empty());
            if(recx[i].empty()) continue;
            memset(f, 0, sizeof(f));
            memset(match, -1, sizeof(match));
            t = recx[i].size();
            for(j = 0; j < recx[i].size(); j++)
            {
                f[ recx[i][j] ][ recy[i][j] ] = 1;
            }
            ans = 0;
            for(j = 1; j <= n; j++)
            {
                memset(v, 0, sizeof(v));
                ans += dfs(j);
            }
            if(ans > k) res[++ct] = i;
        }
        if(ct == 0) printf("-1\n");
        else
        {
            for(i = 1; i <= ct; i++)
                printf("%d%c", res[i], i == ct ? '\n': ' ');
        }
    }
    return 0;
}
