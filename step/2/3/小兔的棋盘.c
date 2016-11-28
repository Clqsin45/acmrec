#include <stdio.h>

__int64 map[36][36];
int main(void)
{
    int n, c = 1;
    int i, j;
    for(i = 0; i <= 35; i++)    map[0][i] = 1;
    for(i = 1; i <= 35; i++)
    {
        for(j = 1; j <= 35; j++)
        {
            if(i == j)  map[i][j] = map[i - 1][j];
            else map[i][j] = map[i - 1][j] + map[i][j -1];
        }
    }

    while(scanf("%d", &n))
    {
        if(n == -1)
            break;
        printf("%d %d %I64d\n",c,n,map[n][n]*2 );
        c++;
    }

    return 0;
}
