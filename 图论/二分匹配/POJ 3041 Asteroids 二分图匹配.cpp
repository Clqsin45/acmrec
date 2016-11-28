#include <stdio.h>
#include <string.h>
#define MAX 555

int f[MAX][MAX] = {0}, v[MAX], match[MAX], n, k;

int dfs(int x)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        if(f[x][i] && !v[i])       //有边链接 且未被访问
        {
            v[i] = 1;
            if(match[i] == -1 || dfs(match[i]))  //如果是一个未配点 或者最终能找到未配点
            {
                match[i] = x;                   //改变链接方式
                return 1;
            }
        }
    }
    return 0;
}
int main(void)
{
    int i, ans = 0, st1, st2;
    scanf("%d%d", &n, &k);
    for(i = 1; i <= k; i++)
    {
        scanf("%d%d", &st1, &st2);
        f[st1][st2] = 1;           //把行为X集 列为Y集 将行列连在一起。
    }
    memset(match, -1, sizeof(match));  //所有边仍未匹配
    for(i = 1; i <= n; i++)
    {
        memset(v, 0, sizeof(v));        //所有的边都未搜过
        if(dfs(i))  ans++;              //统计匹配
    }
    printf("%d\n", ans);
    return 0;
}
