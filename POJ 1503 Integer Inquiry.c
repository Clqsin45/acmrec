#include <stdio.h>
#include <string.h>

//清数组啊少年。。。。
int a[100004] = {0}, b[104] = {0};
int main(void)
{
    char op[104];
    int i, j, l, m, sign = 0, c, fm;
    while(scanf("%s", op))
    {
        if(strcmp(op, "0") == 0)    break;
        l = strlen(op); fm = l;
        memset(b, 0, sizeof(b));
        for(i = 0; op[i] == '0'; i++, l--);
        if(!sign) m = l - 1;
        sign = 1;
        //printf("%d\n", i);
        for(j = l - 1; i < fm; i++, j--)
        {
            b[j] = op[i] - '0';
        }
        //for(i = l - 1; i >= 0; i--)
        c = 0;
        for(i = 0; i <= m; i++)
        {
            a[i] = a[i] + b[i] + c;
            c = a[i] / 10;
            a[i] %= 10;
        }
        if(c)
            a[++m] = c;
    }
    if(sign)
    {
        for(i = m; i >= 0; i--)printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}
