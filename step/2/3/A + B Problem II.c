#include <stdio.h>
#include <string.h>
int a[1002], b[1002];
char st1[1002], st2[1002];
int main(void)
{
    int t, ct = 1, i, j, max, sign;
    scanf("%d", &t);
    while(ct <= t)
    {
        if(ct != 1) printf("\n");
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        scanf("%s%s", st1, st2);
        for(i = strlen(st1) - 1, j = 0; i >= 0;  i--)
        {
            a[j] = st1[i] - '0';
            j++;
        }

        for(i = strlen(st2) - 1, j = 0; i >= 0;  i--)
        {
            b[j++] = st2[i] - '0';
        }
        max = strlen(st1);  if(max < strlen(st2)) max = strlen(st2);
        sign = 0;

        for(i = 0; i < max; i++)
        {
            a[i] = a[i] + b[i] + sign;
            sign = a[i] / 10;
            a[i] %= 10;
        }
        if(sign)
        {
            a[max++] = sign;
        }
        printf("Case %d:\n%s + %s = ", ct, st1,st2);
        for(i = max - 1;  i >= 0; i--)   printf("%d",a[i]);
        printf("\n");
        ct++;

    }
    return 0;
}
