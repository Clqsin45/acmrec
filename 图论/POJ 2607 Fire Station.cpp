#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
int n, m, fire[104], map[505][505], d[505];

int findmin(int a, int b)
{
    return a < b ? a : b;
}
int findmax(int a, int b)
{
    return (a > b ? a: b);
}
void floyd(void)
{
    int i, j, k;
    for(k = 0; i < m; k++)
    {
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(map[i][j] > (map[i][k] + map[k][j]))
                    map[i][j] = map[i][k] + map[k][j];
            }
        }
    }
}
int main(void)
{
    int i, j, st, st1, st2,stt, max, ans, temp;
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(i == j)
                map[i][j] = 0;
            else
                map[i][j] = INF;
        }
    }
    for(i = 0; i < n; i++)
    {
        scanf("%d", &fire[i]);
        fire[i]--;
    }
    while(~scanf("%d%d%d", &st1, &st2, &stt))
    {
        st1--;  st2--;
        map[st1][st2] = map[st2][st1] = findmin(map[st1][st2],stt);
    }
    floyd();
    for(i = 0; i < m; i++)
        d[i] = INF;
    for(i = 0;i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
             d[i] = findmin(map[i][fire[j]], d[i]);
        }
    }
    max = INF;  ans = 0;
    for(i = 0; i < m; i++)
    {
        temp = 0;
        for(j = 0; j < m; j++)
        {
            temp = findmax(temp, findmin(d[j], map[i][j]));
        }
        if(temp < max)
        {
            max = temp;
            ans = i;
        }
    }
    printf("%d\n", ans + 1);

    return 0;
}
