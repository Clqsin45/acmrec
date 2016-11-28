#include <stdio.h>

int l[5004], w[5004], v[5004], r[5004];
void swap(int x, int y)
{
    int t;
    t = r[x];   r[x] = r[y]; r[y] = t;
    return;
}
void qsort(int ll, int rr)
{

    int i = ll, j = rr, s = r[(ll + rr) / 2];
    while(i <= j)
    {
        while((l[r[i]] < l[s]) ||(l[r[i]] == l [s] && w[r[i]] < w[s]))  i++;

        while((l[r[j]] > l[s]) || (l[r[j]] == l [s] && w[r[j]] > w[s])) j--;
        if(i <= j)
        {
            swap(i , j);
            i++; j--;
        }
    }
    if(ll < j)   qsort(ll, j);
    if(i <rr)   qsort(i, rr);
}

int main(void)
{
    int t, n, i, j, temp, ct;
    scanf("%d", &t);
    while(t--)
    {
        ct = 0;
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d", &l[i], &w[i]);
            r[i] = i;      v[i] = 0;
        }

        qsort(1, n);
        for(i = 1; i <= n; i++)
        {
            if(v[r[i]]) continue;
            temp = w[r[i]];
            for(j = i + 1; j<=n ;j++)
            {
                if(!v[r[j]]&& w[r[j]] >= temp)
                {
                    v[r[j]] = 1;
                    temp = w[r[j]];
                }
            }
            ct ++;
        }
        printf("%d\n", ct);
    }
    return 0;
}
//L相同时还要让w递增
//== 时可能会碰到 i = s || j = s的死循环，要用> <
