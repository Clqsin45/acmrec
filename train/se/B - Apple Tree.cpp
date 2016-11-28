#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define MAX 110
vector<int>p[MAX];
int go[MAX][MAX << 1], rt[MAX][MAX << 1], ap[MAX], son[MAX];

int findmax(int x, int y)
{
    return x > y ? x : y;
}

void findson(int x, int fa)
{
    son[x] = 0;
    int i, sum = 0,  y, s = p[x].size();
    for(i = 0; i < s; i++)
    {
        y = p[x][i];
        if(y == fa) continue;
        findson(y, x);
        sum += (son[y] + 1);
    }
    son[x] = sum;
}

void dfs(int x, int fa)
{
    int i, y, s = p[x].size(), flag = 1;
    //printf("%d  %d\n", x, s);
    int j, k;
    rt[x][0] = go[x][0] = ap[x];
    //printf("%d  %d\n", x, go[x][0]);
    for(i = 0; i < s; i++)
    {

        y = p[x][i];
        if(y == fa) continue;
        dfs(y, x);
        //printf("!!!%d\n", x);
        flag = 0;
        for(j = son[x] * 2; j >= 0; j--)        ////only ones
        {
            for(k = 1; k <= j; k++)         //ÒÔÐ¡ÎªÆ¾
            {
                go[x][j] = max(go[x][j],
                                max(rt[x][j - k] + go[y][k - 1], go[x][j - k] + rt[y][k - 2]));
                if(k >= 2)
                    rt[x][j] = max(rt[x][j], rt[x][j - k] + rt[y][k - 2]);
            }
            //printf("go[%d][%d] = %d\n", x, j, go[x][j]);
        }
    }
    /*if(flag)
    {
        rt[x][0] = go[x][0] = ap[x];
        //printf("%d  %d\n", x, go[x][0]);
    }
    */
}

int main(void)
{
    int n, k, i, st1, st2, max = 0;
    while(scanf("%d%d", &n, &k) != EOF)
    {
        memset(go, 0, sizeof(go));
        memset(rt, 0, sizeof(rt));
        max = 0;
        for(i = 1; i <= n; i++) scanf("%d", &ap[i]);
        for(i = 1; i < n; i++)
        {
            scanf("%d%d", &st1, &st2);
            p[st1].push_back(st2);
            p[st2].push_back(st1);
        }

        findson(1, 0);
        //for(i = 1; i <= n; i++) printf("%d\n", son[i]);
        dfs(1, 0);

        for(i = 0; i <= k; i++)
            max = findmax(max, go[1][i]);
        for(i = 1; i <= n; i++) p[i].clear();
        printf("%d\n", max);
    }
    return 0;
}

