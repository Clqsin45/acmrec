#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 1004
#define M
#define LL __int64
#define INF 0x3f3f3f3f

int dp[N][N], sum[N], a[N], w[N];
int q[N], n, m;

void init()
{
    int i, j;
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= m; j++)
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0; dp[1][0] = 0;
}

int G(int i, int j, int x)
{
    return dp[i][x]-dp[j][x];
}
int S(int i, int j)
{
    return sum[i]-sum[j];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int i, j, ans, f, r, x, y, z ;
    while(scanf("%d%d", &n, &m) && (n || m))
    {
        sum[0] = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]); sum[i] = sum[i-1] + a[i];
            w[i] = w[i - 1] + sum[i - 1] * a[i];
        }
        init();
        for(i = 1; i <= n; i++)
        {
            dp[i][0] = a[i] * (sum[i - 1]) + dp[i - 1][0];
            //printf("dp[%d][0] = %d\n", i, dp[i][0]);
        }
       // printf("%d\n", dp[1][1]);
        for(j = 1; j <= m; j++)
        {
            f = r = 0;  q[0] = 0;
            for(i = 1; i <= n; i++)
            {
                 if(i > 1) dp[i][j] = min(dp[i - 1][j - 1] , dp[i][j]);
                 //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
                x = q[f];   y = q[f + 1];
                while(f < r && G(x, y, j) >= a[i]*S(x, y))
                {
                    f++;    x = q[f];   y = q[f + 1];
                }
                x = q[f];
                //printf("%d  %d\n", x, (sum[i-1] - sum[x - 1]));//dp[x][j]+*a[i]);
                dp[i][j] = min(dp[i][j], dp[i - 1][j] +(sum[i-1] - sum[x - 1])*a[i]);

                //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
                while(f < r)
                {
                    x = q[r - 1];   y = q[r];   z = i;
                    if(G(x, y, j) * S(y, z)  >= G(y, z, j) * S(x, y)) r--;
                    else break;
                }
                q[++r] = i;

            }
        }
        ans = INF;
        for(i = 0; i <= m; i++)
        {
            ans = min(ans, dp[n][i]);
        }
        printf("%d\n", ans);

    }
	return 0;
}
