#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N
#define M
#define LL __int64
#define INF 0x3f7f7f7f


int main(void)
{
    int n, a, s;
    while(scanf("%d", &n) != EOF)
    {
        s = 0;
        while(n--)
        {
            scanf("%d", &a);
            s ^= a;
        }
        if(s)   printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
