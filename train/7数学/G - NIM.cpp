#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 200004
#define INF 0x3f7f7f7f
int f[MAX];

int main(void)
{
    int n, i, s, t;
    while(scanf("%d", &n) && n)
    {
        for(i = 1, s = 0; i <= n; i++)
        {
            scanf("%d", &f[i]);
            s ^= f[i];
        }
        if(s)
        {
            printf("Yes\n");
            for(i = 1; i <= n; i++)
            {
                t = s ^ f[i];
                if(t < f[i])
                {
                    printf("%d %d\n", f[i], t);
                }
            }

        }
        else printf("No\n");
    }
    return 0;
}
