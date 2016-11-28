#include <string.h>
#include <stdio.h>
#include <map>
using namespace std;

int main(void)
{
    int n, max,i, x;
    map<int,int>p;

    while(scanf("%d", &n) != EOF)
    {
        p.clear(); max = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            p[x]++;
            if(p[x] > max) max = p[x];
        }
        printf("%d\n", max);
    }
    return 0;
}
