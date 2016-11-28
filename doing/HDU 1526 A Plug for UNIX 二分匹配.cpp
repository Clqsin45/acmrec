#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<string, int>g;
#define MAX 555
#define INF 0x7f7f7f7
int f[MAX][MAX], match[MAX], n, m, nx;
bool v[MAX];
char a[MAX][30];

void floyd(int n)
{
    int i, j, k;
    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(f[i][j] == 0 && f[i][k] && f[k][j])
                    f[i][j] = 1;
            }
        }
    }
}
bool dfs(int x)
{
    int i;
    for(i = m + 1; i <= m + nx; i++)
    {
        if(f[x][i] && !v[i])
        {
            v[i] = 1;
            if(match[i] == -1 || dfs(match[i]))
            {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}
int main(void)
{
    int TC, i, k, ans;
    char ch[30], te[MAX];
    scanf("%d", &TC);
    while(TC--)
    {

        g.clear();
        memset(f, 0, sizeof(f));
        memset(match, -1, sizeof(match));
        ans = 0;

        scanf("%d", &n);
        nx = n;
        for(i = 1; i <= n; i++)
        {
            scanf("%s", ch);
            g[ch] = i;
        }
        scanf("%d", &m);
        for(i = 1; i <= m; i++)
        {
            scanf("%s%s", te, a[i]);
            if(g[a[i]] != 0)
            {
                int x = g[a[i]];
                f[i][x + m] = 1;
            }
            else
            {
                n ++;
                g[a[i]] = n;
                f[i][n + m] = 1;
            }
        }
       //printf("~!!!");
        scanf("%d", &k);
        for(i = 1; i <= k; i++)
        {
            scanf("%s%s", ch, te);
            if(g[ch] == 0)
            {
                n++;    g[ch] = n;
            }
            if(g[te] == 0)
            {
                n++;
                g[te] = n;
            }
            f[g[ch] + m][g[te] + m] = 1;
        }
        floyd(n + m);
        for(i = 1; i <= m; i++)
        {
            memset(v, 0, sizeof(v));
            ans += dfs(i);
        }
        printf("%d\n", m - ans);
        if(TC)  printf("\n");
    }
    return 0;
}
