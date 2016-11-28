#include <stdio.h>
struct line
{
    int h;  int t;  int w;
}p[15004];
int f[1002], rank[1002], max, n, m, record[15004];

void qsort(int l, int r)
{
    int i = l, j = r, s = p[(l+r)/2].w;
    struct line temp;
    while(i <= j)
    {
        while(p[i].w < s)   i++;
        while(p[j].w > s)   j--;
        if(i <= j)
        {
            temp = p[i];    p[i] = p[j];    p[j] = temp;
            i++;    j--;
        }
    }
    if(l < j)   qsort(l, j);
    if(i < r)   qsort(i, r);
}
int find(int x)
{
    if(x == f[x])   return x;
    else return f[x] = find(f[x]);
}

void get(int x, int y)
{
    if(rank[x] > rank[y])   f[y] = x;
    else
    {
        if(rank[x] == rank[y])  rank[y]++;
        f[x] = y;
    }
}
int kruskal(void)
{
    int h, t, i, ct;
    for(i = 1; i <= n; i++)
    {
        f[i] = i;   rank[i] = 0;
    }
    qsort(1, m);
    for(i = 1, ct = 0; ct < (n - 1) && i <= m; i++)
    {
        h = find(p[i].h);   t = find(p[i].t);
        if(h != t)
        {
            get(h, t);
            record[++ct] = i;
            if(max < p[i].w)    max = p[i].w;
        }
    }
    return ct;
}


int main(void)
{
    int i, ct;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &p[i].h, &p[i].t, &p[i].w);
    }
    ct = kruskal();
    printf("%d\n%d\n", max, ct);
    for(i = 1; i <= ct; i++)
        printf("%d %d\n", p[record[i]].h, p[record[i]].t);

    return 0;
}
