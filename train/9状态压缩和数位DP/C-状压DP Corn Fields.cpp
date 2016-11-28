#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 14
#define M  4202
#define MOD 100000000
#define LL __int64
#define INF 0x3f7f7f7f

int dab[N], f[M][N], val[M], no = 0;

bool ok(int x)
{
    return x & (x << 1);
}
void init(int x)
{
    int i;
    for(i = 0; i <= x; i++)
    {
        if(ok(i))   continue;
        //printf("%d\n", i);
        val[++no] = i;
        if(dab[1] & i)  continue;
       // printf("%d\n", i);
        f[no][1] = 1;
    }
}
int main(void)
{
    int n, m, i, j, x, k, ans;
    scanf("%d%d", &n, &m);
    memset(f, 0, sizeof(f));
    for(i = 1; i <= n; i++)
    {
        dab[i] = 0;
        for(j = 1; j <= m; j++)
        {
            scanf("%d", &x);
            dab[i] = (dab[i] * 2 + (!x));
        }
    }
    x = (1 << m) - 1;
    init(x);


    for(i = 2; i <= n; i++)
    {
        for(j = 1; j <= no; j++)
        {
            if(val[j] & dab[i])  continue;
            for(k = 1; k <= no; k++)
            {
                if(val[k] & (dab[i - 1]) )   continue;
                if(val[k] & val[j]) continue;
                f[j][i] = (f[j][i] + f[k][i - 1]) % MOD;
            }
        }
    }
    ans = 0;
    for(i = 1; i <= no; i++)
        ans = (f[i][n] + ans) % MOD;
    printf("%d\n", ans);
    return 0;
}
