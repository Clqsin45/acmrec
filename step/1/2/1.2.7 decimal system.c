#include <stdio.h>
#include <string.h>
char c[102];
int main(void)
{
    int n, a, d, mark, t, i;
    long long int sum = 0;
    while(scanf("%d\n", &n) != EOF)
    {
        sum = 0;
        while(n--)
        {
            t = 1;
            memset(c, '\0', sizeof(c));     gets(c);
            for(i = 0 ; c[i] != '('; i++) ; mark = i - 1;
            d = (c[i + 1] - '0') *  (c[i + 2] == ')' ? 1:10) + (c[i + 2] - '0') * (c[i + 2] != ')');
            for(i = mark ; i >=0; i--, t *= d)
            {
                sum += (c[i] - '0') * t;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
