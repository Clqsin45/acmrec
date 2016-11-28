#include <stdio.h>
#include <string.h>
bool v[44][44];
int d[44], n, m;
char c[44];
int topo()
{
    int i, j, k;
    bool flag = true;
    memset(d, 0, sizeof(d));
    memset(c, '\0', sizeof(c));
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(v[i][j]) d[j]++;
        }
    }
    for(i = 1; i <= n; i++)
    {
        k = 0;
        for(j = 1; j <= n; j++)
        {
            if(d[j] != 0)   continue;
            if(k == 0)  k = j;
            else flag = false;
        }
        if(k == 0)  return 0;
        d[k] = -1;
        c[i] = 'A' + k - 1;
        for(j = 1; j <= n; j++)
        {
            if(v[k][j])     d[j]--;
        }

    }
    if(flag)    return 1;
    else return 2;
}
int main(void)
{
    int i, j, ans;
    char a, b, s[10];
    bool sign;
    while(scanf("%d%d", &n, &m) && (n || m))
    {
        sign = false;
        memset(v, 0, sizeof(v));
        for(i = 1;  i <= m; i++)
        {
            scanf("%s", s);
            a = s[0] - 'A' + 1;   b = s[2] - 'A' + 1;
            v[a][b] = true;
            if(sign)    continue;
            ans = topo();
            if(ans == 1)
            {
                printf("Sorted sequence determined after %d relations: %s.\n", i, c+1);
                sign = true;
            }
            else if(ans == 0)
            {
                printf("Inconsistency found after %d relations.\n", i);
                sign = true;
            }
        }
        if(!sign)
            printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
