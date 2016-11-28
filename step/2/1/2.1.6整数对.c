#include <stdio.h>

int st[1002];
void swap(int x, int y)
{
    int t = st[x]; st[x] = st[y]; st[y] = t;
    return;
}
void qsort(int l, int r)
{
    int i = l, j = r, s =st[(l + r) / 2];
    while(i <= j)
    {
        while(st[i] < s) i++;
        while(st[j] > s) j--;
        if(i <= j)
        {
            swap(i, j);
            i++;    j--;
        }
    }
    if(l < j)   qsort(l , j);
    if(i < r)   qsort(i , r);
}
int main(void)
{
    int k = 1, a, b, c, n, ct = 0;
    while(scanf("%d", &n) && n)
    {
        ct = 0;
        for( k = 1 ; k <= n; k *= 10)
        {
            a = n / k / 11;
            b = n / k % 11;
            if((a + b) != 0 && b < 10)
            {
                c = (n - k*(11 * a + b))/2;
                if(k*(11 * a + b) + 2 * c == n)
                    st[++ct] = a * k * 10 + c + b *k;

            }
            b--;
            if((a + b) != 0 && b >= 0)
            {
                c = (n - k*(11 * a + b))/2;
                if(k*(11 * a + b) + 2 * c == n)
                    st[++ct] = a * k * 10 + c + b *k;
            }
        }

        if(!ct) printf("No solution.\n");
        else
        {
            qsort(1, ct);
            printf("%d",st[1]);
            for(k = 2; k <= ct; k++)
                if(st[k] != st[k-1])
                    printf(" %d", st[k]);
            printf("\n");
        }
    }
    return 0;
}
