#include <stdio.h>

int d[120000] ={0}, s[220000] = {0};
int main(void)
{
    int n, k, f = 1, r = 1;

    scanf("%d%d", &n, &k);
    s[1] = n;   d[n] = 0;
    if(n == k)
    {
        printf("0\n"); return 0;
    }
    while(f <= r)
    {
        if(s[f] - 1 == k || s[f] + 1 == k || s[f] * 2 == k)
        {
            printf("%d\n",d[s[f]] + 1);
            return 0;
        }
        if(s[f] - 1 >= 0 && !d[s[f]-1])
        {
            s[++r] = s[f] - 1;
            d[s[f] - 1] = d[s[f]] + 1;
        }
        if(s[f] + 1 <= 120000 && !d[s[f]+1])
        {
            s[++r] = s[f] + 1;
            d[s[f] + 1] = d[s[f]] + 1;
        }
        if(s[f] *2 <= 120000 && !d[s[f] * 2])
        {
            s[++r] = s[f] * 2;
            d[s[f]*2] = d[s[f]] + 1;
        }
        f++;
    }
    system("pause");
    return 0;
}
