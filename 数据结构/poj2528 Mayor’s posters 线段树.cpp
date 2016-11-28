#include <stdio.h>
#include <algorithm>
using namespace std;
#define lson l, m, rt << 1
#define rson m+1, r, rt<<1|1
#define MAX 10005
int lside[MAX], rside[MAX], way[MAX << 2];
int f[MAX << 2], cl[MAX << 2];

int main(void)
{
    int t, i, n, nn;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d", &lside[i], &rside[i]);

        }
    }
    return 0;
}
