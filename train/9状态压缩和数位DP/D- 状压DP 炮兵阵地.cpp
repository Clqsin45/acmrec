#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 104
#define M 68
#define LL __int64
#define INF 0x3f7f7f7f

int f[M][M][N], dab[N], val[M], num[M], no = 0;

bool ok(int x)
{
    if(x & (x << 1))    return true;
    if(x & (x << 2))    return true;
    return false;
}

void init(int x)
{
    int i, temp;
    for(i = 0; i <= x; i++)
    {
        if(ok(i))   continue;
        val[++no] = i;  num[no] = 0;
        temp = i;
        while(temp)
        {
            num[no] += (temp & 1);
            temp /= 2;
        }
        if(i & dab[1])  continue;
        f[no][1][1] = num[no];
        //printf("f[%d][0][1] = %d\n", val[no], f[no][0][1]);
    }

}

int main(void)
{
    int i, j, k, t, n, m, x, ans;
    char s[N];
    scanf("%d%d", &n, &m);
    memset(f, 0, sizeof(f));
    for(i = 1; i <= n; i++)
    {
        dab[i] = 0;
        scanf("%s", s + 1);
        for(j = 1; j <= m; j++)
            dab[i] = (dab[i] * 2 + (s[j] == 'H'));
    }
    x = (1 << m) - 1;
    init(x);
    //printf("%d\n", no);
    //printf("%d\n", f[2][0][1]);
    for(i = 2; i <= n; i++)
    {
        for(j = 1; j <= no; j++)
        {
            if(val[j] & dab[i]) continue;
            for(k = 1; k <= no; k++)
            {
                if(val[k] & dab[i - 1]) continue;
                if(val[j] & val[k]) continue;
                for(t = 1; t <= no; t++)
                {
                    if(val[t] & dab[i - 2]) continue;
                    if(val[j] & val[t]) continue;
                    if(val[k] & val[t]) continue;

                    f[j][k][i] = max(f[j][k][i], f[k][t][i - 1] + num[j]);
                }
            }
        }
    }
    ans = 0;
    for(i = 1; i <= no; i++)
        for(j = 1; j <= no; j++)
            ans = max(f[i][j][n], ans);
    printf("%d\n", ans);
    return 0;
}
