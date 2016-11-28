#include <stdio.h>
#include <string.h>
#define MAXN 200002

char w[MAXN], map[30], a[MAXN], b[MAXN], p[MAXN];
int next[MAXN], lenw, lenp, mid;

int kmp(void)
{
    int i = 0, j = 0;
    lenw = strlen(w);
    while(i < lenw && j < lenp)
    {
        if(j == -1 || p[j] == w[i])
        {
            i++;    j++;
        }
        else j = next[j];
    }
    return j;
}
void getnext(void)
{
    int i = 0, j = - 1; next[0] = -1;
    while(i < mid)
    {
        if(j == -1 || p[i] == p[j])
        {
            i++; j++;
            if(p[i] != p[j])
            {
                next[i] = j;
            }
            else next[i] = next[j];
        }
        else j= next[j];
    }
    return;
}
int main(void)
{
    int t, i,st, lenb;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s%s", a, b);
        memset(next, 0, sizeof(next));
        lenb = strlen(b);
        for(i = 0 ; i < 26; i++)
            map[a[i] - 'a'] = 'a' + i;
        lenp = mid = (lenb + 1) / 2;
        strcpy(w, b + mid);
        for(i = 0; i <= mid; i++)
            p[i] = map[b[i] - 'a'];
        getnext();
        st = kmp();
        for(i = 0; i <lenb - st; i++)    printf("%c", b[i]);
        for(i = 0; i <lenb - st; i++)    printf("%c", map[b[i]-'a']);
        printf("\n");
    }
    return 0;
}
