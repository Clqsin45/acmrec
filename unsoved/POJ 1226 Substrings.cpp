#include <stdio.h>
#include <string.h>
char s[102][102], ps[102], ns[102];
int l[102];
int main(void)
{
    int t, num, shor, min, ans, sign, flag;
    int i, j, k;
    scanf("%d", &t);
    while(t--)
    {
        min = 0x3f3f3f3f;
        flag = 0;
        scanf("%d", &num);
        for(i = 0; i < num; i++)
        {
            scanf("%s",s[i]);
            l[i] = strlen(s[i]);
            if(l[i] < min)
            {
                min = l[i]; shor = i;
            }
        }
        ans = min;

        while(ans > 0)
        {
            for(i = 0; i <= min - ans; i++)
            {
                strncpy(ps, s[shor] + i, ans);
                for(k = 0, j = ans - 1; k < ans; k++,j--)
                {
                    ns[j] = ps[k];
                }
                ps[ans] = ns[ans] = '\0';
                for(j = 0, sign = 1; j < num; j++)
                {
                    //printf("%s  %s  %d\n", s[j], ps, ans);
                    if(!strstr(s[j], ps) && !strstr(s[j], ns))
                    {
                        sign = 0;   break;
                    }
                }
                if(sign)    flag =1;
            }
            if(flag) break;
            ans--;
        }
        printf("%d\n", ans);
    }
    return 0;
}
