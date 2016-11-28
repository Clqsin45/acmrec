#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 100004
#define INF 0x3f7f7f7f
struct point
{
    int num, equ, les;
}p[MAX], w[MAX];

int c[30], next[MAX], n, m, k, ans, pre;

int lowbit(int x)
{
    return x & (-x);
}

int getsum(int x)
{
    int sum = 0;
    for(; x > 0; x -= lowbit(x))
    {
        sum += c[x];
    }
    return sum;
}

void modify(int x, int y)
{
    for(; x <= k; x += lowbit(x))
    {
        c[x] += y;
    }
}

void getnext()
{
    int i = 1, j = 0, t;
    bool flag = 0;
    memset(next, 0, sizeof(next));
    next[1] = 0;
    while(i <= m)
    {
        flag = (getsum(p[i].num) == p[j].equ && getsum(p[i].num - 1) == p[j].les);
        if(j == 0 || flag)
        {
            i++;    j++;
           // if(!flag)
            next[i] = j;
            //else next[i] = next[j];

            if(i <= m)
                modify(p[i].num, 1);
        }
        else
        {
            for(t = i - j + 1; t <= i - next[j]; t++)
            {
                modify(p[t].num, -1);
            }
            j = next[j];
        }
    }
}

void kmp()
{
    int i = 1, j = 1, t;
    modify(w[i].num, 1);
    while(i <= n)
    {
        if(j == 0 || (getsum(w[i].num) == p[j].equ && getsum(w[i].num - 1) == p[j].les))
        {
            i++;    j++;
            if(i <= n)
                modify(w[i].num, 1);
        }
        else
        {
            for(t = i - j + 1; t <= i - next[j]; t++)
                modify(w[t].num, -1);
            j = next[j];
        }
        if(j == m + 1)
        {
           // printf("%d  %d\n", i - j + 1, pre);
            if(i - j + 1 - pre > 0)
            {
                ans ++;
                pre = i - j + m;
            }

            for(t = i - j + 1; t <= i - next[j]; t++)
                modify(w[t].num, -1);
            j = next[j];
        }
    }
}

int main(void)
{
    int i;
    while(scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        memset(c, 0, sizeof(c));
        ans = 0;    pre = 0;

        for(i = 1; i <= n; i++)
            scanf("%d", &w[i].num);
        for(i = 1; i <= m; i++)
        {
            scanf("%d", &p[i].num);
            modify(p[i].num, 1);
            p[i].equ = getsum(p[i].num);
            p[i].les = getsum(p[i].num - 1);
        }
        memset(c, 0, sizeof(c));
        getnext();
        memset(c, 0, sizeof(c));
        kmp();
        printf("%d\n", ans);
    }
    return 0;
}
