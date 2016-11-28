#include <stdio.h>
#include <string.h>
#define MAX 511
int v[MAX], match[MAX], n, no;
int like[MAX], hate[MAX], f[MAX][MAX];


int dfs(int x)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        if(!v[i] && f[x][i])
        {
            v[i] = 1;
            if(match[i] == -1 || dfs(match[i]))
            {
                match[i] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main(void)
{
    int c, d, i, j, T, a, b, ans;
    char stay, out;
    scanf("%d", &T);
    while(T--)
    {
        no = ans = 0;
        memset(f, 0, sizeof(f));
        memset(match, -1, sizeof(match));

        scanf("%d%d%d", &c, &d, &n);
        getchar();
        for(i = 1; i <= n; i++)
        {
            scanf("%c%d %c%d",&stay, &a, &out, &b);
            getchar();
            if(stay == 'D') a += c;
            if(out == 'D') b += c;
            like[i] = a;    hate[i] = b;
        }
        for(i = 1; i <= n; i++)
        {
            for(j = i + 1; j <= n; j++)
            {
                if(like[i] == hate[j])
                    f[i][j] = f[j][i] = 1;
                if(hate[i] == like[j])
                    f[i][j] = f[j][i] = 1;
            }
        }
        for(i = 1; i <= n; i++)
        {
            memset(v, 0, sizeof(v));
            ans += dfs(i);
        }
        printf("%d\n", n - ans / 2);
    }
    return 0;
}
