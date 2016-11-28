#include <stdio.h>
#include <math.h>
int main(void)
{
    __int64 j, k, t, ct, sign, n;

    while(scanf("%I64d",&n)!=EOF)
    {
        ct = 0;
        while(n--)
        {
            scanf("%I64d",&t);
            sign = 1;   k = (int)sqrt(t);
            for(j = 2; j <= k; j++)
            {
                if(t % j == 0)
                {
                    sign = 0;   break;
                }
            }
            if(sign)    ct++;
        }
        printf("%I64d\n", ct);
    }
    return 0;
}
//__64int的应用
//不要打表上瘾啊喂！
