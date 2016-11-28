#include <stdio.h>

int max(int x, int y)
{
    return x > y ? x : y;
}

int v[1000002], a[55], b[55], f[280004];

int main(void)
{
    int n, i , j , m, st, ct, t;
    while(scanf("%d", &n) && ( n >= 0))
    {
        ct = 1;     m = 0;
        for(i = 1; i <= n; i++)
        {
            st = 1;
            scanf("%d%d", &b[i], &a[i]);    m += a[i] * b[i];
            while(a[i] >= st*2)
            {
                v[ct++] = st * b[i];

                a[i] -= st; st *= 2;
            }
            if(a[i] > 0)
            {
                v[ct++] = a[i] * b[i];
            }
        }
        t = m / 2;
        for(i = 0; i <= t; i++) f[i] = 0;
        for(i = 1; i < ct; i++)
        {
            for(j = t; j >=v[i]; j--)
            {
                f[j] = max(f[j], f[j - v[i]] + v[i]);
            }
        }
        printf("%d %d\n",m - f[t], f[t]);
    }

    system("pause");
    return 0;
}
