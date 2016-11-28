#include <stdio.h>
#include <string.h>
int f[44][44][44][44], ct[10], num[400];

int max(int x, int  y)
{
    return x > y ? x : y;
}

int dfs(int a, int b, int c, int d)
{
    int pos = a + 2 * b + 3 * c + 4 * d + 1;
    if(f[a][b][c][d] != -1) return f[a][b][c][d];
    f[a][b][c][d] = num[pos];
    if(a > 0)   f[a][b][c][d] = max(f[a][b][c][d], dfs(a-1, b, c, d) + num[pos]);
    if(b > 0)   f[a][b][c][d] = max(f[a][b][c][d], dfs(a, b-1, c, d) + num[pos]);
    if(c > 0)   f[a][b][c][d] = max(f[a][b][c][d], dfs(a, b, c-1, d) + num[pos]);
    if(d > 0)   f[a][b][c][d] = max(f[a][b][c][d], dfs(a, b, c, d-1) + num[pos]);
    return f[a][b][c][d];
}
int main(void)
{
    int temp, i, n, m, st;
    memset(ct, 0, sizeof(ct));
    memset(f, -1, sizeof(f));
    scanf("%d%d", &n,&m);
    for(i = 1; i <= n; i++) scanf("%d", &num[i]);
    for(i = 1; i <= m; i++)
    {
        scanf("%d", &st);
        ct[st]++;
    }
    f[ct[1]][ct[2]][ct[3]][ct[4]] = dfs(ct[1], ct[2], ct[3], ct[4]);
    printf("%d\n", f[ct[1]][ct[2]][ct[3]][ct[4]]);
    return 0;
}
