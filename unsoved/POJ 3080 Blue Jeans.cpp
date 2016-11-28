#include <stdio.h>
#include <string.h>
char s[70][70], ps[70], st[70];
int next[70], len, ans;

void getnext(void)
{
    int i = 0, j = -1;
    next[0] = -1;
    while(i < ans)
    {
        if(j  == -1 || ps[i] == ps[j])
        {
            i++;    j++;
            if(ps[i] != ps[j])  next[i] = j;
            else next[i] = next[j];
        }
        else j = next[j];
    }
}

int kmp(char *check)
{
    int i = 0, j = 0;
    while(i < len && j < ans)
    {
        if(j == -1 || check[i] == ps[j])
        {
            i++;    j++;
        }
        else j = next[j];
    }
    if(j == ans)    return -1;
    else return 0;
}
int main(void)
{
    int t, num, sign, ext, i, j, flag;
    scanf("%d", &t);
    while(t--)
    {
        flag = 0;
        scanf("%d", &num);
        for(i = 0 ; i < num; i++)
        {
            scanf("%s",s[i]);
        }

        len = strlen(s[0]);

		ans = len;
        while(ans > 0)
        {
            ext = 0;
            for(i = 0 ; i <= len - ans; i++)
            {
                strncpy(ps, i + s[0], ans);
                ps[ans] = '\0';
                memset(next, 0, sizeof(next));
                getnext();
                for(j = 1, sign = 1; j < num; j++)
                {
                    if(!kmp(s[j]))
                    {
                        sign = 0; break;
                    }
                }

                if(sign)
                {
                    flag = 1;
                    if(ext == 0 || (ext == 1 && strcmp(st, ps)))
                    {
                        strcpy(st, ps);
                        ext = 1;
                    }
                }
            }
            if(flag)    break;
            ans --;
        }
        if(ans < 3) printf("no significant commonalities\n");
        else printf("%s\n", st);

    }
    return 0;
}
