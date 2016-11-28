#include <stdio.h>
#include <string.h>
#define MAX 100004
char p[MAX];
int next[MAX], len;

void getnext(void)
{
    int i = 0, j = -1;
    next[0] = -1;
    while(i < len)
    {
        if(j == -1 || p[j] == p[i])
        {
            i++;    j++;
            if(p[i] != p[j])    next[i] = j;
            else next[i] = next[j];
        }
        else j = next[j];
    }
}
int main(void)
{
    int t, st;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", p);
        memset(next, 0, sizeof(next));
        len = strlen(p);
        getnext();
        st = len / (len - next[len]);
        printf("%d\n", next[len]);
        if(st > 1)  printf("%d\n", len % (len - next[len]));
        else printf("%d\n", len);
    }
    return 0;
}
