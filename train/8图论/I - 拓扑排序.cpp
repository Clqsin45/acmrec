#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 204
#define M
#define LL __int64
#define INF 0x3f7f7f7f

int f[N][N], in[N], v[N], ans[N], n;

bool tp()
{
    int now = n, t, i, j;
    for(i = 1; i <= n; i++)
    {
        t = -1;
        for(j = n; j >= 1; j--)
        {
            if(!v[j] && in[j] == 0)
            {
                ans[j] = now--;     t = j;
                break;
            }
        }
        if(t == -1)    return false;
        v[t] = 1;
        for(j = 1; j <= n; j++)
        {
            if(!f[t][j])    continue;
            in[j] --;   f[t][j] = 0;
        }
    }
    return true;
}

void init()
{
    memset(f, 0, sizeof(f));    memset(v, 0, sizeof(v));
    memset(in, 0, sizeof(in));
}
int main(void)
{
    int TC, m, x, y, i;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d%d", &n, &m);
        init();
        while(m--)
        {
            scanf("%d%d", &x, &y);
            if(f[y][x]) continue;
            f[y][x] = 1;    in[x] ++;
        }
        if(tp())
        {
            for(i = 1; i <= n; i++)
            {
                printf("%d%c", ans[i], i == n ?'\n' : ' ');
            }
        }
        else printf("-1\n");
    }
    return 0;
}
