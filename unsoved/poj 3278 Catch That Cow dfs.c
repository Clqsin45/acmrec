#include <stdio.h>
#include <string.h>
int f[110000], n , k, min;
void dfs(int x, int ct)
{

    if(x == k)  return;
    printf("¡­¡­¡­¡­¡­¡­%d %d\n", x, ct);
    if(x - 1 >= 1)
    {
        if (f[x - 1] > ct + 1)
        {
            f[x - 1] = ct + 1;
            printf("%d %d\n", x, ct);
            dfs(x - 1, ct + 1);
            printf("###%d %d\n", x, ct);        }
    }
    if(x + 1 < 110000)
    {
        if(f[x + 1] > ct + 1)
        {
            printf("%d %d\n", x, ct);   //system("pause");
            f[x + 1] = ct + 1;
            dfs(x + 1, ct + 1);
            printf("@@@%d %d\n", x, ct);   //system("pause");
        }
    }
    if(x * 2 < 110000)
    {
        if(f[x * 2] > ct + 1)
        {
            printf("%d %d\n", x, ct);   //system("pause");
            f[x * 2] = ct + 1;
            dfs(x * 2, ct + 1);

            printf("£¡£¡£¡%d %d\n", x, ct);   //system("pause");
        }
    }
}
int main(void)
{
    freopen("out.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    memset(f,44,sizeof(f));
    dfs(n, 0);
    printf("%d\n",f[k]);

    system("pause");
    return 0;
}
