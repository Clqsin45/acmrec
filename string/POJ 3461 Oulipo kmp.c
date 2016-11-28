#include <stdio.h>
#include <string.h>
char p[100004], w[1000004];
int next[100004], lenw, lenp;

int check(void)
{
    int ct = 0, i = 0, j = 0;
    while(i < lenw)
    {
        if(j == - 1 || w[i] == p[j])
        {
            if(j == lenp - 1 && w[i] == p[j]) ct++;
            i++;    j++;
        }
        else j = next[j];
    }
    return ct;
}
void getnext(void)
{
    int i = 0, j = -1;
    memset(next, 0, sizeof(next));  next[0] = -1;
    while(i < lenp)
    {
        if(j == -1 || p[i] == p[j])
        {
            i++;    j++;
            if(p[i] != p[j])    next[i] = j;
            else next[i] = next[j];
        }
        else
            j = next[j];
    }
}
int main(void)
{
    int t, ct, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s%s",p, w);
        lenw = strlen(w);   lenp = strlen(p);
        getnext();
        ct = check();
        printf("%d\n", ct);
        for(i = 0; i <= lenp; i++)   printf("%d\n", next[i]);
    }
    return 0;
}
