#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define M 1008
#define INF 0x3f7f7f7f
#define eps 1e-8
int n, b, no;
int f[M], g[M];
void calb()
{
    memset(f, 0, sizeof(f));
    int i, m = (int)sqrt(b) + 1, t = b;
    no = 0;
    for(i = 2; i <= m; i++)
    {
        f[i] = 0;
        if(t % i)   continue;
        while(!(t % i))
        {
            f[i] ++;   t /= i;
        }
        if(t == 1)  break;
    }
    if(t != 1)  f[t] = 1;
   //for(i = 1; i <= b; i++) printf("%d  %d\n",i, f[i]);
}

void caln(void)
{
    int i, j, t, m;
    memset(g, 0, sizeof(g));
   // for(i = 1; i <= b; i++) printf("%d  %d\n",i, g[i]);
    for(i = 2; i <= n; i++)
    {
        t = i;  m = sqrt(i) + 1;
        for(j = 2; j <= m && j <= b; j++)
        {
            if(t % j)   continue;
            while(!(t % j))
            {
               // printf("%d %d %d\n", i, t, j);
                g[j] ++;     t /= j;
            }
            if(t == 1)  break;

        }
        if(t != 1 && t <= b)  g[t]++;
    }
    for(i = 1; i <= b; i++) printf("%d  %d\n",i, g[i]);
}
int main(void)
{
    //freopen("in.txt", "r", stdin);
    freopen("dashi.txt", "w", stdout);
    double temp, sum;
    int ans, i;
    while(scanf("%d%d", &n, &b) != EOF)
    {
        sum = 0;

        caln();
        calb();
        ans = INF;
        for(i = 2; i <= b; i++)
        {
            if(!f[i])   continue;
            ans = min(g[i] / f[i], ans);
            if(ans == 0)    break;
        }
        printf("%d", ans);
        for(i = 1; i <= n; i++)
        {
            sum += log10(i);
        }
        sum /= log10(b);
        //printf("%d\n", (int)floor(sum + eps));
        printf(" %d\n", (int)floor(sum+eps) + 1);
        // 16! 20922789888000
        //12 7
    }

    return 0;
}
