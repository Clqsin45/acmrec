#include <stdio.h>

char a[1002],s[1004] = {'\0'};
int main(void)
{
    int top = 0, st, i;

    while(scanf("%s", a) != EOF)
    {
        top = 0; i = 1;
        s[top] = a[0];
        while(1)
        {
            if(a[i] == 'B') break;
            else if(s[top] == '(' && a[i] == ')')
            {
                top--;  i++;
            }
            else
            {
                s[++top] = a[i];
                i++;
            }
        }
        printf("%d\n",top + 1);
    }
    return 0;
}

