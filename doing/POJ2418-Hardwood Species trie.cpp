#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 10005
#define INF 0x7f7f7f7

struct tree
{
    int next[140], no;
    bool sign;
}t[MAX * 100];
int num = 0;
struct point
{
    char s[34];
    int sum;
}f[MAX];

void init(int x)
{
    int i;
    for(i = 0; i < 140; i++)
        t[x].next[i] = -1;
    t[x].sign = 0;
    return;
}

bool cmp(point a, point b)
{
    return strcmp(a.s, b.s) < 0;
}
int insert(char a[], int k)
{
    int now = 0, i, la = strlen(a), temp;
    bool flag = 0;

    for(i = 0; i < la; i++)
    {
        temp = a[i];
        if(t[now].next[temp] == -1)
        {
            num++;
            init(num);

            t[now].next[temp] = num;
            flag = 1;
        }
        now = t[now].next[temp];
    }
    //printf("%s %d\n", a, flag);
    if(flag)
    {
        t[now].no = k;
        t[now].sign = true;
        return 0;
    }
    return t[now].no;
}

int main(void)
{
    int n = 0, k = 0, i, x;
    char temp[34];
    init(0);
    while(gets(temp))
    {
        x = insert(temp, k + 1);
        if( x == 0)
        {
            strcpy(f[++k].s, temp);
            f[k].sum = 1;
        }
        else
        {
            f[x].sum++;
        }
        n++;
    }
    sort(f + 1, f + k + 1, cmp);
    for(i = 1; i <= k; i++)
    {
        printf("%s %.4f\n", f[i].s, (double)f[i].sum / n * 100);
    }
    return 0;
}
