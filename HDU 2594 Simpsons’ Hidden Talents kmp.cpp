#include <stdio.h>
#include <string.h>
#define MAX 50005
char w[MAX], p[MAX], st[MAX];
int lenw, lenp, next[MAX];

void getnext(void)
{
    int i = 0, j = -1;
    next[0] = -1;
    while(i < lenp)
    {
        if(j == -1 || p[j] == p[i])
        {
            i++;    j++;
            if(p[j] != p[i])    next[i] = j;
            else next[i] = next[j];
        }
        else j = next[j];
    }
}

int kmp(void)
{
    int i = 0, j = 0;
    while(i < lenw)
    {
        if(j == -1 || w[i] == p[j])
        {
            i++;    j++;
        }
        else j = next[j];
    }
    return j;
}
int main(void)
{
    int ans;
    while(scanf("%s%s", p, w)!= EOF)
    {
        memset(next, 0, sizeof(next));
        lenp = strlen(p);
        lenw = strlen(w);
        getnext();
        ans = kmp();
        if(ans == 0)    printf("0\n");
        else printf("%s %d\n", w + lenw- ans, ans);

    }
    return 0;
}
