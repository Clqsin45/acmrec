#include <stdio.h>
#include <string.h>

#define MAX 1000004
int check[MAX], a[MAX], min[MAX], max[MAX];
int n, k;

int delmin(int f, int r, int x)
{
    int m;
    while(f <= r)
    {
        m = (f + r) / 2;
        if(a[check[m]] == x)    return m;
        if( a[check[m]] > x)     r = m-1;
        else    f = m + 1;
    }
    return f;
}

int delmax(int f, int r, int x)
{
    int m;
    while(f <= r)
    {
        m = (f + r) / 2;
        if(a[check[m]] == x)    return m;
        if( a[check[m]] < x)     r = m - 1;
        else    f = m + 1;
    }
    return f;
}

void findmin(void)
{
    int f, r, i;
    memset(check, 0, sizeof(check));
    f = 1; r = 1;
    check[r++] = 1;
    min[1]  = a[1];

    for(i = 2; i <= n; i++)
    {
        r = delmin(f, r, a[i]);
        //while(a[check[r - 1]] > a[i] && f < r)  r--;
        check[r] = i;
        while(check[f] < i - k + 1)  f++;
        min[i] = a[check[f]];
        if(i >= k && i < n ) printf("%d ", min[i]);
    }
    printf("%d\n", min[n]);
}

void findmax(void)
{
    int f, r, i;
    memset(check, 0, sizeof(check));
    f = 1; r = 1;
    check[r++] = 1;
    max[1]  = a[1];

    for(i = 2; i <= n; i++)
    {
        r = delmax(f, r, a[i]);
        //while(a[check[r - 1]] < a[i] && f < r)  r--;
        check[r] = i;
        while(check[f] < i - k + 1)  f++;
        max[i] = a[check[f]];
        if(i >= k && i < n) printf("%d ", max[i]);
    }
    printf("%d\n", max[n]);
}

int main(void)
{
    int i, x;
    scanf("%d%d", &n, &k);

    if(k == 1)
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
         for(i = 1; i <= n; i++)
        {
            if(i!=n)printf("%d ", a[i]);
            else printf("%d\n", a[i]);
        }

        for(i = 1; i <= n; i++)
        {
            if(i!=n)printf("%d ", a[i]);
            else printf("%d\n", a[i]);
        }
        return 0;
    }
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    findmin();
    findmax();
    return 0;
}
