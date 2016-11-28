#include <stdio.h>
#include <map>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f

map<string, int>p;
double f[40][40];

int floyd(int n)
{
    int i, j, k;
    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(f[i][j] < f[i][k] * f[k][j]) f[i][j] = f[i][k] * f[k][j];
            }
        }
    }
    for(i = 1; i <= n; i++)
        if(f[i][i] > 1) return 1;
    return 0;
}
int main(void)
{
    int n, m, no, i, j, cs = 1;
    double st;
    char ch[100], cd[100];
    while(scanf("%d", &n) && n)
    {
        for(i = 0; i <= n; i++)
        {
            for(j = 0; j <= n; j++)
            {
                if(i == j)  f[i][j] = 1;
                else f[i][j] = -INF;
            }
        }
        no = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%s", ch);
            p[ch] = i;
        }
        scanf("%d", &m);
        for(i = 1; i <= m; i++)
        {
            scanf("%s%lf%s", ch,&st,cd );
            f[p[ch]][p[cd]] = st;
        }
        no = floyd(n);
        if(no)  printf("Case %d: Yes\n", cs++);
        else printf("Case %d: No\n", cs++);
    }
    return 0;
}
