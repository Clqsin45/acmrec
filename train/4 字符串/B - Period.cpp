#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 1000004

char p[MAXN];
int next[MAXN], lt;
void getnext(void)
{
    int i = 0, j = -1;
    memset(next, 0, sizeof(next));
    next[0] = -1;
    while(i < lt)
    {
        if(j == -1 || p[i] == p[j])
        {
            i++;    j++;
            next[i] = j;
        }
        else j = next[j];
    }
}
int main(void)
{
    int i, s, CT = 1;
    while(scanf("%d", &lt) && lt)
    {
        scanf("%s", p);
        getnext();
        printf("Test case #%d\n", CT++);
        for(i = 1; i <= lt; i++)
        {
            s = i - next[i];
            if(next[i] != 0 && i % s == 0)    printf("%d %d\n", i, i / s);
        }
        printf("\n");
    }
    return 0;
}
