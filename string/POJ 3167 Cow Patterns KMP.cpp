#include <stdio.h>
#include <string.h>
#define MAXP 25005
#define MAXW 100005
struct point
{
    int num, equ, les;   //值 前方比他小（等于）的 前方比他小的
};
point p[MAXP], w[MAXW];
int next[MAXP], c[30] = {0}, n, k, s, ct = 0, record[MAXW];

int lowbit(int x)
{
    return x & (-x);
}

void modify(int x, int t)
{
    for(; x < s + 1; x += lowbit(x))
        c[x] += t;
}

int getsum (int x)
{
    int sum = 0;
    for(; x > 0; x -= lowbit(x))
        sum += c[x];
    return sum;
}

void getnext()
{
    int i = 1, j = 0, st;
    next[1] = 0;

    while(i <= k)
    {
        if(j == 0 || (getsum(p[i].num) == p[j].equ && getsum(p[i].num - 1) == p[j].les))
        {
            i++;    j++;
            next[i] = j;
            if(i <= k)
                modify(p[i].num, 1);        //更新之后
        }
        else
        {
            for(st = i - j + 1; st <= i - next[j]; st++)
                modify(p[st].num, -1);
            j = next[j];
        }
    }
}

void kmp(void)
{

    int i = 1, j = 1, st;
    modify(w[1].num, 1);
    while(i  <= n )
    {
        if(j == 0 || (getsum(w[i].num) == p[j].equ && getsum(w[i].num - 1) == p[j].les))
        {
            i++;    j++;
			if(i <= n)
                modify(w[i].num, 1);
        }
        else
        {
            for(st = i - j + 1; st <= i - next[j]; st++)
                modify(w[st].num, -1);
            j = next[j];
        }
        if(j == k + 1)
        {
            record[++ct] = i-j + 1;
            for(st = i - j + 1; st <= i -next[j]; st++)
                modify(w[st].num, -1);

            j = next[j];
        }
    }
}
int main(void)
{
    //freopen("in.txt", "r", stdin);
    int i;
    scanf("%d%d%d", &n, &k, &s);

    for(i = 1; i <= n; i++)  scanf("%d", &w[i].num);
    for(i = 1; i <= k; i++)
    {
        scanf("%d", &p[i].num);
        modify(p[i].num, 1);               //增加出现的次数 后面的统计
        p[i].equ = getsum(p[i].num);          //比他小或等于的
        p[i].les = getsum(p[i].num - 1);      //比他小的
        //printf("%d  %d  %d  %d\n",i, p[i].num, p[i].equ, p[i].les);
    }

    memset(next, 0, sizeof(next));
    memset(c, 0, sizeof(c));
    getnext();
    memset(c, 0, sizeof(c));
    kmp();

    printf("%d\n", ct);
    for(i = 1; i <= ct; i++)    printf("%d\n", record[i]);
    return 0;
}
