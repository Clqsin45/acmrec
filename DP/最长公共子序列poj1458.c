#include <stdio.h>
#include <string.h>
char a[1002], b[1002];
int f[1002][1002] = {{0};
int main(void)
{
    int x, y, i, j, max;
    while(scanf("%s %s", a + 1, b + 1) == 2)
    {
        x = strlen(a + 1);  y = strlen(b + 1);
        for(i = 1; i <= x; i++)
        {
            for(j = 1; j <= y; j++)
            {
                max = 0;
                if(a[i] == b[j])    f[i][j] = f[i - 1][j - 1] + 1;
                else
                {
                    if(f[i - 1][j - 1] > max) max = f[i - 1][j - 1];
                    if(f[i][j - 1] > max) max = f[i][j - 1];
                    if(f[i - 1][j] > max) max = f[i - 1][j];
                    f[i][j] = max;
                }
            }
        }
        printf("%d\n", f[x][y]);
        memset(f, 0, sizeof(f));
    }
    system("pause");
    return 0;
}
