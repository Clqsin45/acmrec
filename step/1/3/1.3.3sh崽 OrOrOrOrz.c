#include <stdio.h>

int a[10004];

void swap(int x, int y)
{
    int t = a[x]; a[x] = a[y];  a[y] = t;
    return;
}

void qsort(int l, int r)
{
    int i = l, j  = r, s = a[(l + r) / 2], t;
    while(i <= j)
    {
        while(a[i] > s)  i++;
        while(a[j] < s)  j--;
        if(i <= j)
        {
            swap(i, j);
            i++;    j--;
        }
    }
    if(l < j)   qsort(l, j);
    if(r > i)   qsort(i, r);
}
int main(void)
{
    int n, i,j, t ;
    while(scanf("%d", &n) != EOF)
    {   t = 0;
        for(i = 0; i < n; i ++)    scanf("%d", &a[i]);
        qsort(0, n - 1);
        for(i = 0, j = n - 1; i <= j; i++, j--)
        {
            if(!t) t = 1;
            else printf(" ");
            if(i==j)printf("%d",a[i]);
            else printf("%d %d",a[i],a[j]);
        }
        printf("\n");
    }
    return 0;
}
