#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 711
#define INF 0x3f7f7f7f

bool f[MAX][MAX], v[MAX];
int match[MAX], rec[MAX][MAX], n, no;
char c[MAX][MAX];
int gox[4] = {0, 1, 0, -1}, goy[4] = {1, 0, -1, 0};

bool inmap(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= n;
}
void init()
{
    memset(rec, 0, sizeof(rec));
    memset(match, -1, sizeof(match));
    memset(f, false, sizeof(f));
    no = 0;
}

bool dfs(int x)
{
    int i;
    for(i = 1; i <= no; i++)
    {
        if(!v[i] && f[x][i])
        {
            v[i] = true;
            if(match[i] == -1 || dfs(match[i]))
            {
                match[i] = x;   return true;
            }
        }
    }
    return false;
}
int main(void)
{
    int T, TC, i, j, k, x, y, ans;

    scanf("%d", &TC);
    for(T = 1; T <= TC; T++)
    {
        scanf("%d", &n);
        init();

        for(i = 1; i <= n; i++)
        {
            scanf("%s", c[i] + 1);
            for(j = 1; j <= n; j++)
            {
                if(c[i][j] == '#')  rec[i][j] = ++no;
            }
        }
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(rec[i][j] == 0)  continue;
                for(k = 0; k < 4; k++)
                {
                    x = i + gox[k]; y = j + goy[k];
                    if(!inmap(x, y))    continue;
                    if(rec[x][y])   f[rec[i][j]][rec[x][y]] = true;
                }
            }
        }
        ans = 0;
        for(i = 1; i <= no; i++)
        {
            memset(v, false, sizeof(v));
            ans += dfs(i);
        }
        printf("Case %d: %d\n", T, ans / 2);
    }
    return 0;
}
