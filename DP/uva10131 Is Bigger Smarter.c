#include <stdio.h>

int w[1002], q[1002], f[1002] = {0}, a[1002];
void swap(int x, int y)
{
    int temp ;
    temp = a[x];
    a[x] = a[y];
    a[y] = temp;
    return;
}
void qsort(int l, int r)
{
    int i = l, j = r, s = (l + r) / 2;
    while(i <= j)
    {
        while(w[a[i]] < w[a[s]]) i++;
        while(w[a[j]] > w[a[s]]) j--;
        if(i <= j)
        {
            swap(i, j);
            i++;    j--;
        }
        if(l < j) qsort(l, j);
        if(i < r) qsort(i, r);
    }
}
int main(void)
{
    int n = 0, j, i, max = 0, res = 0;
    while(scanf("%d%d", &w[n], &q[n]) == 2)  {
        a[n] = n;
        n++;
    }
    qsort(0, n - 1);
    f[n - 1] = 1;
    for(i = n - 2; i >= 0; i--)
    {
        max = 0;
        for(j = i + 1;  j <= n - 1; j++)
            if(q[a[i]] > q[a[j]])
            {
                if(max < f[j]) max = f[j];
            }
        f[i] = max + 1;
        if(f[i] > res) res = f[i];
    }
    printf("%d\n", res);
    return 0;
}
