#include <stdio.h>
#include <string.h>
#define MAX 100005
char w[MAX], p[MAX];
int nextw[MAX], nextp[MAX], lenw, lenp;

void getnext(char *s, int *x, int len)
{
    int i = 0, j = -1;
    x[0] = -1;
    while(i < len)
    {
        if(j == -1 || s[i] == s[j])
        {
            i++;    j++;
            if(s[i] != s[j])    x[i] = j;
            else x[i] = x[j];
        }
        else j = x[j];
    }
}
int kmp(char *x, char *y, int *s, int len)
{
    int i = 0, j = 0;
    while(i < len)
    {
        if(j == -1 || x[i] == y[j])
        {
            i++;    j++;
        }
        else j = s[j];
    }
    return j;
}
int main(void)
{
    int st1, st2;
    while(scanf("%s%s", w, p) != EOF)
    {
        lenw = strlen(w);
        lenp = strlen(p);
        getnext(w, nextw, lenw);
        getnext(p, nextp, lenp);
        st1= kmp(w, p, nextp, lenw);
        st2 = kmp(p, w, nextw, lenp);
        if(st2 == st1)
        {
            if(strcmp(w, p) < 0)    printf("%s%s\n", w, p + st2);
            else printf("%s%s\n",p, w+st1);
        }
        else if(st2 > st1)
        {
            printf("%s%s\n", p, w + st2);
        }
        else printf("%s%s\n", w, p + st1);
    }
    return 0;
}
