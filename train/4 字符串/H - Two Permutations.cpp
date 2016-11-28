#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 200004
#define INF 0x3f7f7f7f

int c[MAX], next[MAX], w[MAX];
struct point
{
    int num, equ;
}p[MAX];

int n, m, ans = 0;

int lowbit(int x)
{
    return x & (- x);
}
int getsum(int x)
{
    int sum = 0;
    for(; x > 0; x -= lowbit(x))    sum += c[x];
    return sum;
}
void modify(int x, int k)
{
    for(; x <= m; x += lowbit(x))   c[x] += k;
}

void getnext()
{
    int i = 1, j = 0, t;
    memset(next, 0, sizeof(next));
    next[1] = 0;   // next[0] = -1;
    while(i <= n)
    {
        if(j == 0 || getsum(p[i].num) == p[j].equ)
        {
            i++;    j++;
            next[i] = j;

            if(i <= n)      modify(p[i].num, 1);
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

void kmp(void)
{
    int i = 1, j = 1, st;
    modify(w[1], 1);
    while(i  <= m )
    {
       // printf("%d  %d %d   %d\n", i, getsum(w[i].num), j, p[j].equ);
        if(j == 0 || getsum(w[i]) == p[j].equ)
        {
            i++;    j++;
			if(i <= m)
                modify(w[i], 1);
        }
        else
        {
            for(st = i - j + 1; st <= i - next[j]; st++)
                modify(w[st], -1);
            j = next[j];
        }
        if(j == n + 1)
        {
            ans ++;
            for(st = i - j + 1; st <= i - next[j]; st++)
                modify(w[st], -1);

            j = next[j];
        }
    }
}

int main(void)
{
    int i, t;
    scanf("%d%d", &n, &m);
    memset(c, 0, sizeof(c));
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &t);
        p[t].num = i;
    }
    for(i = 1; i <= m; i++)
    {
        scanf("%d", &t);
        w[t] = i;
    }
    memset(c, 0, sizeof(c));
    for(i = 1; i <= n; i++)
    {
        modify(p[i].num, 1);
        p[i].equ = getsum(p[i].num);
    }
    memset(c, 0, sizeof(c));

    getnext();
    //next[n + 1] = n;
    //printf("!!\n");
    //for(i = 1; i <= n + 1; i++) printf("%d\n", next[i]);
    memset(c, 0, sizeof(c));
    kmp();
    printf("%d\n", ans);
    return 0;
}
/*****8
2 5
1 2
2 5 1 3 4
********/
