#include <stdio.h>

int a[1004];

void swap(int x, int  y)
{
    int t = a[x];   a[x] = a[y];    a[y] = t;
    return;
}
void qsort(int l, int r)
{
    int i = l, j = r, s = a[(l + r) /2];
    while(i <= j)
    {
        while(a[i] < s) i++;
        while(a[j] > s) j--;
        if(i <= j)
        {
            swap(i, j);
            i++;    j--;
        }
    }
    if(l < j)   qsort(l, j);
    if(i < r)   qsort(i, r);
}
int main(void)
{
    int t, n, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 1; i <= n ; i++)    scanf("%d", &a[i]);
        qsort(1, n);
        for(i = 1; i < n; i++)  printf("%d ", a[i]);
        printf("%d\n", a[n]);
    }
    return 0;
}
