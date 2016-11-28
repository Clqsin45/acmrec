#include <stdio.h>
int l[55], m[55], r[55];
char p[55][55];
void swap(int x, int y)
{
    int t = r[x];   r[x] = r[y];    r[y] = t;
    return;
}
int main(void)
{
    int t, n, i, j;
    scanf("%d", &t);
    for(i = 2; i <= 30; i++)
    {
        for(j = 2; j < i; j++)  p[i][j] = '-';
        p[i][0] = '>';  p[i][1] = '+';
        p[i][j] ='+';   p[i][j + 1] = '>';
    }
    while(t--)
    {
        scanf("%d", &n);
        for(i = 1; i <= n ; i++)
        {
            scanf("%d%d", &l[i], &m[i]);
            r[i] = i;
        }
        for(i = 1; i <=n ; i++)
        {
            for(j = 1; j <= n - i; j++)
            {
                if(l[r[j]] > l[r[j + 1]])   swap(j, j +1);
            }
        }
        for(i = 1; i <=n ; i++)
        {
            for(j = 1; j <= m[r[i]]; j++)
            printf("%s\n",p[l[r[i]]]);
            printf("\n");
        }
    }
    return 0;
}
