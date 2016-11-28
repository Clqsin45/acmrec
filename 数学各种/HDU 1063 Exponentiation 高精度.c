#include <stdio.h>
#include <string.h>
#define INF 2004
int a[INF];

void cal(int x)
{
    int i, j, sign = 0;
    for(i = 1; i <= a[0]; i++)
    {
        a[i] = a[i] * x + sign;
        sign = a[i] / 10;
        a[i] %= 10;
    }
    while(sign)
    {
        a[i++] = sign % 10;
        sign /= 10;
    }
    a[0] = i - 1;
}

void output(int x)
{
    int i, j;
    if(x < a[0])
    {
        for(j = 0, i = a[0]; j < a[0] - x; i--, j++)
        {
            printf("%d",a[i]);
        }
        for(j = 1; a[j] == 0; j++)  a[j] = -1;
        if(a[i] == -1 || i == 0)    return;
        printf(".");
        for(; a[i] != -1 && i > 0; i--)
            printf("%d",a[i]);
    }
    else
    {
        printf(".");
        for(i = 1; i <= x - a[0] ;i++)   printf("0");
        for(j = 1; a[j] == 0; j++)  a[j] = -1;
        for(i = a[0]; a[i]!= -1 && i >= 1; i--)
        {
            printf("%d",a[i]);
        }
    }
}

int main(void)
{
    char s[12];
    int pos, i, j, base, n, l;
    while(scanf("%s%d", s, &n) != EOF)
    {
        base = 0; l = strlen(s);
        memset(a, 0, sizeof(a));
        for(i = 0, pos = 5; i < l; i++)
        {
            if(s[i] == '.') pos = i;
            else
                base = base * 10 + s[i] - '0';
        }
        a[0] = a[1] = 1;
        pos = (5 - pos) * n;
        while(n--)
        {
            cal(base);
        }
        output(pos);
        printf("\n");
    }
    return 0;
}
