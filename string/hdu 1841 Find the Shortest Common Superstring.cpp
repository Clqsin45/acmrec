#include <stdio.h>
#include <string.h>
#define MAX 1000005
int nextp[MAX], nextw[MAX];
char p[MAX], w[MAX], lenw, lenp;

void getnext(char *x, int *s, int len)
{
    int i = 0, j = -1;
    s[0] = -1;
    while(i < len)
    {
        if(j == -1 || x[i] == x[j])
        {
            i++;    j++;
            if(x[i] == x[j])    s[i] = j;
            else s[i] = s[j];
        }
        else j = s[j];
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
    int t, st1, st2;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s%s", w, p);
        lenp = strlen(p);
        lenw = strlen(w);
        getnext(w, nextw, lenw);
        getnext(p, nextp, lenp);
        st1 = kmp(w, p, nextp, lenw);
        st2 = kmp(p, w, nextw, lenp);
        printf("%d\n", lenw+lenp- (st1 > st2 ? st1 : st2));
    }
    return 0;
}
