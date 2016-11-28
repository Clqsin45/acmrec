#include <stdio.h>
struct line
{
    int head;   int tail;   int weight;
}edge[10002];
int n, m, dist, f[30], rank[30];

void qsort(int l, int r)
{
    int i = l, j = r, s = edge[(l + r) / 2].weight;
    struct line temp;
    while(i <= j)
    {
        while(edge[i].weight < s)   i++;
        while(edge[j].weight > s)   j--;
        if(i <= j)
        {
            temp = edge[i];   edge[i] = edge[j];  edge[j] = temp;
            i++;    j--;
        }
    }
    if(l < j)   qsort(l, j);
    if(r > i)   qsort(i, r);
}

int find(int x)
{
    if(x != f[x])   return f[x] = find(f[x]);
    else return x;
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
void kruskal(void)
{
    int i, ct, st, j, t, h;
    for(i = 1; i <= n; i++)
    {
        f[i] = i; rank[i] = 0;
    }
    qsort(1, m);
    for(ct = 0, i = 1; i <= m && ct < (n - 1); i++)
    {
        h = find(edge[i].head);     t=find(edge[i].tail);
        if(h != t)
        {
            get(h, t);
            ct++;   dist += edge[i].weight;
        }
    }

}

int main(void)
{
    char op;
    int t, st, i, j;
    while(scanf("%d", &n) && n)
    {
        m = 0;  dist = 0;
        for(i = 1;  i < n; i++)
        {
            scanf("\n");
            scanf("%c %d", &op, &t);
            for(j = 1; j <= t; j++)
            {
                scanf(" %c %d", &op, &st);
                edge[++m].head = i;
                edge[m].tail = op - 'A' + 1;
                edge[m].weight = st;
            }
        }

        kruskal();
        printf("%d\n", dist);
    }
    return 0;
}
