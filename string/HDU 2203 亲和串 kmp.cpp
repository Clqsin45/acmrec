#include <stdio.h>
#include <string.h>
#define MAX 100004
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

int kmp(char *x, char *y, int *s, int la, int lb )
{
    int i = 0, j = 0;
    while(i < la)
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
        if(lenw < lenp)
        {
            printf("no\n");
            continue;
        }
        getnext(w, nextw, lenw);
        getnext(p, nextp, lenp);
        st1 = kmp(w, p, nextp, lenw, lenp);
        st2 = kmp(p, w, nextw, lenp, lenw);
        if(st1 + st2 >= lenp)   printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
