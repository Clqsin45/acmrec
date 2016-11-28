#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1000002];
int main(void)
{
    int n, i;
    while(scanf("%d", &n) != EOF)
    {
        for(i = 0; i <n; i++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        printf("%d\n", a[n/2]);
    }
    return 0;
}
