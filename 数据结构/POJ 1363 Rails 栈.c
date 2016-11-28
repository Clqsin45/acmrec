#include <stdio.h>
#include <string.h>
int s[1004];
int main(void)
{
    int n, i, st , top, t, flag;
    while(scanf("%d", &n) && n)
    {
        while(1)
        {
            top = 0;    s[++top] = 1;
            scanf("%d", &t);
            st = 2;     flag = 1;
            if(t == 0)  break;
            for(i = 2; i <= n; i++)
            {
                while(s[top] != t)
                {
                    if(st > n)
                    {
                        flag = 0;   break;
                    }
                    s[++top] = st;  st++;
                }
                top --;
                scanf("%d", &t);
            }
            if(flag)    printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
