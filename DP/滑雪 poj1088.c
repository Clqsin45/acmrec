#include <stdio.h>

int a[102][102], f[102][102] = {-1};
int m, n;
int find(int i, int j)
{
    if(f[i][j] > 0) return f[i][j];
    
    if((i + 1 <= m) && a[i][j] > a[i + 1][j])
        f[i][j] = f[i][j] > find(i + 1, j)? f[i][j]:find(i + 1, j);
        
    if((i - 1 >= 1) && a[i][j] > a[i - 1][j])
        f[i][j] = f[i][j] > find(i - 1, j)? f[i][j]:find(i - 1, j);
        
    if((j + 1 <= n) && a[i][j] > a[i][j + 1])
        f[i][j] = f[i][j] > find(i, j + 1)? f[i][j]:find(i, j + 1);
        
    if((j - 1 >= 1) && a[i][j] > a[i][j - 1])
        f[i][j] = f[i][j] > find(i, j - 1)? f[i][j]:find(i, j - 1);
        
    f[i][j] += 1;
    return f[i][j];
}
int main(void)
{
    int i , j, max = 0;
    while(scanf("%d%d",&m, &n) == 2)
    {
        max = 0;
        for(i = 1; i <= m; i++)
        {
            for(j = 1; j <= n; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
		
        for(i = 1; i <= m ; i++)
        {
            for(j = 1; j <= n ; j++)
            {
				f[i][j] = find (i,j);
                if(max < f[i][j]) max = f[i][j];
            }
        }
        printf("%d\n",max);
        memset(f, 0, sizeof(f));
    }
    return 0;
}
