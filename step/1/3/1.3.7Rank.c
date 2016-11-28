#include <stdio.h>

int a[1004], n[1004], rk[1004];

void swap(int x, int y)
{
    int t = rk[x];   rk[x] =rk[y];     rk[y] = t;
    return ;
}
void qsort(int l, int r)
{
    int i = l, j = r, s=rk[(l + r) / 2];
    while(i <= j)
    {
        while(a[rk[i]] > a[s])   i++;
        while(a[rk[j]] < a[s])   j--;
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
    int b, i, c, t , st;
    while(scanf("%d",&b) != EOF)
    {
        i = 0;
        while(scanf("%d%d", &n[i], &a[i]) && (n[i] || a[i]))
        {
            rk[i] = i;   i++;
        }
        c = i - 1;
        qsort(0, c);
        t = a[0]; st = 1;
        for(i = 0; i <= c; i++ )
        {
            if(a[rk[i]] != t)
            {
                t = a[rk[i]];   st = i + 1;
            }
            if(n[rk[i]] == b)
            {
                printf("%d\n",st);
                break;
            }
        }

    }
    return 0;
}
