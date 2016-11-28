#include <stdio.h>
#include <string.h>
int a[1004],b[1004], ans[1005];
char s1[1004],s2[1004];
int main(void)
{
    /*freopen("in.txt", "r", stdin);*/
    int l1, l2, i, pos1, pos2, j, st, m, sign;
    while(scanf("%s%s", s1, s2) != EOF)
    {
        l1 = strlen(s1);    l2 = strlen(s2);
        pos1 = -1;  pos2 = -1;
        memset(ans, 0,sizeof(ans));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

        for(i = l1 - 1, j = 0; i >= 0; i--,j ++)
        {
            if(s1[j] == '.')
            {
                a[i] = -1;
                pos1 = i;
            }
            else
            {
                a[i] = s1[j]-'0';
            }
        }

        for(i = l2 - 1, j = 0; i >= 0; i--,j ++)
        {
            if(s2[j] == '.')
            {
                b[i] = -1;
                pos2 = i;
            }
            else
            {
                b[i] = s2[j]-'0';
            }
        }

        sign = 0;
        st = (pos1 > pos2 ? pos1 : pos2);
        ans[st] = -2;
        if(pos1 == pos2)
        {
            for(i = 0; i < pos1; i++)
            {
                ans[i] = sign + a[i] + b[i];
                sign = ans[i] / 10;
                ans[i] %= 10;
            }
        }

        else if(pos1 < pos2)
        {
            for(i = 0; i < pos2 - pos1; i++)
                ans[i] = b[i];
            for(j = 0; i < st; i++, j++)
            {
                ans[i] = a[j] + b[i] + sign;
                sign = ans[i] / 10;
                ans[i] %= 10;
            }
        }
        else
        {
            for(i = 0; i < pos1- pos2; i++)
            {
                ans[i] = a[i];
            }
            for(j = 0; i < st; i++, j++)
            {
                ans[i] = a[i] + b[j] + sign;
                sign = ans[i] / 10;
                ans[i] %= 10;
            }
        }
        m = l1 + l2;
       /*m = (l1> l2 ? l1 : l2);*/
        if(pos1 + pos2 == -2) ;
        else if(pos1 == -1)  m += pos2;
        else if(pos2 == -1)  m += pos1;
        for(i = pos1 + 1, j = pos2 + 1, st = st + 1; i < m || j < m; i++, j++, st++)
        {
            ans[st] = a[i] + b[j] + sign;
            sign = ans[st] / 10;
            ans[st] %= 10;
        }
        if(sign > 0)
        {
            ans[m] = sign;
            m++;
        }
        st = pos1 > pos2 ? pos1 : pos2;
        ans[st] = -2;
        for(i = 0; ans[i] == 0 && i < st; i++)
           ans[i] = -1;
        for(i = m; ans[i] == 0 && ans[i-1] != -2; i--); m = i;
        for(i = m; i >= 0 && ans[i] != -1; i--)
        {
             if(ans[i] == -2 && ans[i - 1] != -1) printf(".");
             else if(ans[i] != -2)printf("%d",ans[i]);
        }
        printf("\n");

    }

    return 0;
}
