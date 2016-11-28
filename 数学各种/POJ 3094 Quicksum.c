#include <stdio.h>
#include <string.h>
int main(void)
{
    //freopen("in.txt", "r", stdin);
    char ch[300], x[4] = {'#'};
    int i, l, sum;
    while(gets(ch))
    {
        if(strcmp(x, ch) == 0) break;
        l = strlen(ch);  sum = 0;
        for(i = 0; i < l; i++)
        {
            if(ch[i] == ' ') continue;
            sum += (i + 1) * (ch[i] - 'A' + 1);
        }
        printf("%d\n", sum);
    }

    return 0;
}
