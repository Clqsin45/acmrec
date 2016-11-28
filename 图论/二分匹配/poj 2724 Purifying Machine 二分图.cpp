#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 2222

vector<int>f[MAX];
int match[MAX], num[MAX], m, n, ct;
bool v[MAX];

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
    int i, j, ans, t, k;
    char op[22];
    while(scanf("%d%d", &n, &m) && (m || n))
    {
        ct = 0;
        memset(match, -1, sizeof(match));
        memset(num, 0, sizeof(num));
        for(i = 1; i <= m; i++)
        {
            scanf("%s", op);
            ct ++;  k = -1;
            for(j = 0; j < n; j++)
            {
                if(op[j] == '*')    k = j;
                else num[ct] |= ((op[j] - '0' ) << j);
            }
            if(k != -1)
            {
                ct++;
                num[ct] == (num[ct - 1] | (1 << k));
            }
        }
        sort(num + 1, num + ct + 1);
        num[0] = -1;
        for(i = 1, j = 0; i <= ct; i++)
        {
            if(num[i] != num[j])
                num[++j] = num[i];
        }
        ct = j;
        for(i = 0; i <= ct; i++)    f[i].clear();
        for(i = 1; i <= ct; i++)
        {
            for(j = 1; j <= ct; j++)
            {
                t = num[i] ^ num[j];
                if(t && (t & (t-1)) == 0)
                {
                    f[i].push_back(j);
                    f[j].push_back(i);
                }

            }
        }
        ans = 0;
        for(i = 1; i <= ct ;i++)
        {
            memset(v, 0, sizeof(v));
            ans += dfs(i);
        }
        printf("%d\n", ct - ans / 2);
    }
    return 0;
}
