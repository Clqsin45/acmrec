#include <stdio.h>
#define INF 100000
struct line
{
    int head;   int tail;   int weight;
}edge[INF];
int n, m, dist, set[30];

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
void kruskal(void)
{
    int i, ct, st, j;
    for(i = 1; i <= n; i++) set[i] = i;
    qsort(1, m);
    //for(i = 1; i <= m; i++) printf("%d  %d  %d\n", edge[i].head,edge[i].tail,edge[i].weight);
    for(ct = 0, i = 1; i <= m && ct < (n - 1); i++)
    {
        if(set[edge[i].head] != set[edge[i].tail])
        {
            st = set[edge[i].tail];
            for(j = 1; j <= n; j++)
            {
                if(set[j] == st)
                {
                    set[j] = set[edge[i].head];
                }
            }
            ct++;   dist += edge[i].weight;
           // printf("%d  %d\n", edge[i].head, edge[i].tail);
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
