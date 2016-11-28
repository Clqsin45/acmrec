#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
struct point
{
    int next; int now;
}p[205];
int v[155], head[155], n, m, no, f[155][155], ans;

void add(int x, int y)
{
    p[++no].next = head[x];
    head[x] = no;
    p[no].now = y;
    return;
}

void dfs(int x)
{
    int i, y, j, k, temp;
    for(i = 0 ; i <= m; i++)
        f[x][i] = INF;
    f[x][1] = 0;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        dfs(y);
        for(j = m; j >= 0; j--)
        {
            temp = f[x][j] + 1;
            for(k = 0; k <= j; k++)
            {
                if(temp > f[y][j - k] + f[x][k])
                    temp = f[y][j - k] + f[x][k];
            }
            f[x][j] = temp;

        }
    }
}
int main(void)
{
    int i, st1, st2, root;    no = 0;
    memset(head, -1, sizeof(head));
    memset(v, 0, sizeof(v));
    scanf("%d%d", &n, &m);
    for(i = 1; i < n; i++)
    {
        scanf("%d%d", &st1, &st2);
        add(st1, st2);
        v[st2] = 1;
    }
    for(i = 1; i <= n; i++)
    {
        if(!v[i])   root = i;
    }
    dfs(root);  ans = f[root][m];
    //除了root本身 其他都要多砍一条到父节点的边
    for(i = 1; i <= n; i++)
    {
        if(ans > f[i][m] + 1)   ans = f[i][m] + 1;
    }
    printf("%d\n",ans);
    return 0;
}
