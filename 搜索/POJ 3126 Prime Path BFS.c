#include <stdio.h>
#include <string.h>
#include <math.h>
int s[1000000], ff[10004], tb[10004] = {0}, a[5];

int main(void)
{
    int t, f, r, n, m, i, j, y, sign;
    scanf("%d", &t);    n = 0;
    for(i = 2; i <= 9999; i++)
    {
        sign = 1;
        for(m = 2; m< sqrt(i) + 1; m++)
        {
            if(i % m == 0)
            {sign = 0;
            break;}
        }
        if(sign)  tb[i] = 1;
    }
    while(t--)
    {
        scanf("%d%d", &n, &m);
        memset(ff, 0, sizeof(ff));
        f = 1;  r = 1;  s[f] = n;   ff[n] = 0;
        while(f <= r && s[f] != m)
        {

            for(i = 1; i <= 9; i += 2)
            {
                y = (s[f] / 10) * 10 + i;
                if(y != s[f] && tb[y] && !ff[y])
                {
                    s[++r] = y;
                    ff[y] = ff[s[f]] + 1;
                }
            }
            for(i = 0; i <= 9; i++)
            {
                y = (s[f] / 100) * 100 + i * 10 + s[f] % 10;
                if(y != s[f] && tb[y] && !ff[y])
                {
                    s[++r] = y;
                    ff[y] = ff[s[f]] + 1;

                }
            }

            for(i = 0; i <= 9; i++)
            {
                y = (s[f] / 1000) * 1000 + i * 100 + s[f] % 100;
                if(y != s[f] && tb[y] && !ff[y])
                {
                    s[++r] = y;
                    ff[y] = ff[s[f]] + 1;
                }
            }
            for(i = 1; i <= 9; i++)
            {
                y = s[f] % 1000 + i * 1000;
                if(y != s[f] && tb[y] && !ff[y])
                {
                    s[++r] = y;
                    ff[y] = ff[s[f]] + 1;
                }
            }
            f++;
        }
        printf("%d\n", ff[m]);
    }
    system("pause");
    return 0;
}
