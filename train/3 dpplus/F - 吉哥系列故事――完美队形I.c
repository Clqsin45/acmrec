#include <stdio.h>
#include <string.h>

#define MAX 220
int a[MAX], b[MAX], f[MAX];

inline int findmax(int x , int y)
{
    return x > y ? x : y;
}

int main(void)
{
    int TC, i, n, j, temp, max, st;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d", &n);
        max = 0;
        memset(f, 0, sizeof(f));
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            b[n - i + 1] = a[i];
        }

        for(i = 1; i <= n; i++)
        {
            st = 0;
            for(j = 1; j <= n - i + 1; j++)
            {
                if(a[i] == b[j])
                {
                    f[j] = findmax(f[j], st + 1);
                }
                else if(a[i] > b[j])
                {
                    st = findmax(f[j], st);
                }
                max = findmax(max, f[j] * 2 - (i + j == n + 1));
                //printf("~~%d %d %d  %d\n", st, i, j, f[j]);
            }
        }
        printf("%d\n", max);
    }
}

/***********888
*/
