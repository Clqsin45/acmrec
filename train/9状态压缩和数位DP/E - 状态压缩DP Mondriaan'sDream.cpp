#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 14
#define M 2056
#define LL __int64
#define INF 0x3f7f7f7f

LL f[M][N], val[M];


void init(int x)
{
    int i, temp, lig;
    for(i = 0; i <= x; i++)
    {
        temp = i;   lig = 0;
        while(temp)
        {
            if(temp & 1)    lig ++;
            else
            {
                if(lig & 1)   break;
                lig = 0;
            }
            temp /= 2;
        }
        if(lig & 1) val[i] = 0;
        else {val[i] = 1; f[i][1] = 1;}
    }
}

int main(void)
{
    int n, m, temp, x, i, j , k;
    while(scanf("%d%d", &n, &m) && (n || m))
    {
        x = (1 << m) - 1;
        memset(f, 0, sizeof(f));
        init(x);
        for(i = 2; i <= n; i++)
        {
            for(j = 0; j <= x; j++)
            {
                for(k = 0; k <= x; k++)
                {
                    if((j | k) != x)   continue;
                    if(!val[j & k])    continue;
                    f[j][i] = f[j][i] + f[k][i - 1];
                }
            }
        }

        printf("%I64d\n", f[x][n]);
    }
    return 0;
}
