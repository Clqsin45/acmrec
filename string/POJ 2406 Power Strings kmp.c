#include <stdio.h>
#include <string.h>
#define MAXN 1000040
int next[MAXN], len;
char w[MAXN];

void getnext(void)
{
    int i = 0, j = -1;   next[0] = -1;
    while(i < len)
    {
        if(j == -1 || w[i] == w[j])
        {
            i++;    j++;
            if(w[i] != w[j])
                next[i] = j;
            else next[i] = next[j];
        }
        else j = next[j];
    }
    return;
}
int main(void)
{
    while(scanf("%s", w))
    {
        if(strcmp(w, ".") == 0) break;
        memset(next, 0, sizeof(next));
        len = strlen(w);
        getnext();
        if(len % (len - next[len]) == 0)    printf("%d\n", len/(len - next[len]));
        else printf("1\n");
    }
    return 0;
}
