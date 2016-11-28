#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxf 105
#define maxn 505
#define inf 0x3f3f3f3f

int firenum, n;
int fire[maxf];
int map[maxn][maxn];
int firedist[maxn];

void input()
{
    scanf("%d%d", &firenum, &n);
    for (int i = 0; i < firenum; i++)
    {
        scanf("%d", &fire[i]);
        fire[i]--;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                map[i][j] = inf;
            else
                map[i][j] = 0;
    int a, b, c;
    while (~scanf("%d%d%d", &a, &b, &c))
    {
        a--;
        b--;
        map[a][b] = map[b][a] = min(map[a][b], c);
    }
}

void floyd()
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
}

void work()
{
    for (int i = 0; i < n; i++)
        firedist[i] = inf;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < firenum; j++)
            firedist[i] = min(firedist[i], map[i][fire[j]]);
    int ans, maxdist = inf;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < n; j++)
            temp = max(temp, min(firedist[j], map[i][j]));
        if (temp < maxdist)
        {
            ans = i;
            maxdist = temp;
        }
    }
    printf("%d\n", ans + 1);
}

int main()
{
    //freopen("t.txt", "r", stdin);
    input();
    floyd();
    work();
    return 0;
}
