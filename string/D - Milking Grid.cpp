#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define M 10004
#define N 100
#define INF 0x3f7f7f7f

char c[M][N];
int next[M] = {0}, f[N], m, n;

void getnext()
{
    int i = 0, j = -1;
    next[0] = -1;

    while(i < m)
    {
        if(j == -1 || strcmp(c[i], c[j]) == 0)
        {
            i++;    j++;
            next[i] = j;
        }
        else j = next[j];
    }
}
int main(void)
{
    int i, j, k, x, y;

    scanf("%d%d", &m, &n);
    memset(f, 0, sizeof(f));

    for(i = 0 ; i  < m; i++)
    {
        scanf("%s", c[i]);
        for(j = 1; j <= n; j++)     //length
        {
            for(x = 0, y = j; y < n; x++, y++)
                if(c[i][x % j] != c[i][y])  break;
            if(y == n)  f[j] ++;
        }


    }

    for(i = 1; i <= n; i++)
        if(f[i] == m)   break;
    for(j = 0; j < m; j++)  c[j][i] = '\0';

    getnext();
    printf("%d\n", i * (m - next[m]));
    return 0;
}
