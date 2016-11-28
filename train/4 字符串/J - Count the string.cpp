#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 200004
#define MOD 10007
#define INF 0x3f7f7f7f

char p[MAX];
int f[MAX], next[MAX], lt, sum;

void getnext()
{
    int i = 0, j = -1;
    memset(next, 0, sizeof(next));
    next[0] = -1;
    while(i < lt)
    {
        if(j == -1 || p[i] == p[j])
        {
            i ++;   j++;
            next[i] = j;
        }
        else j = next[j];
    }
}
int main(void)
{
    int TC, i;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d", &lt);
        scanf("%s", p);
        getnext();

        memset(f, 0, sizeof(f));
        sum = 0;

        for(i = 1; i <= lt; i++)
        {
           // printf("%d\n", next[i]);
            f[i] += f[next[i]] + 1;
            sum += f[i];
            sum %= MOD;
        }
        printf("%d\n", sum);
    }
    return 0;
}

// abababab       aaaaa
