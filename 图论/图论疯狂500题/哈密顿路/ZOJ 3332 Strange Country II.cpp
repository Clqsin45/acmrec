#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 104
#define M
#define LL __int64
#define INF 0x3f7f7f7f

int f[N][N];
int l[N], r[N];

int main(void)
{
    int TC, i, j, x, y, n, m;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &n);
        m = (n - 1) * n / 2;

        memset(f, false, sizeof(f));
        for(i = 0; i <= n; i++){
            r[i] = n + 2;
        }
        while(m--){
            scanf("%d%d", &x, &y);
            f[x][y] = true;
        }
        for(i = 1; i <= n; i++){
            f[0][i] = f[i][n + 2] = true;
        }
        r[0] = n + 2;
        for(i = 1; i <= n; i++){
            for(j = 0; j != n + 2; j = r[j]){
                if(f[j][i] && f[i][r[j]]){
                    l[r[j]] = i;
                    r[i] = r[j];
                    r[j] = i;
                    l[i] = j;
                    break;
                }
            }
        }
        for(i = r[0]; i != n + 2; i = r[i]){
            printf("%d%c", i, r[i] == n + 2 ? '\n' : ' ');
        }
    }
    return 0;
}
