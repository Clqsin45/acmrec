#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 1000000000
#define N 10000004
#define INF 0x3f7f7f7f
#define LL __int64
int p[N];
bool flag[MAX];
void init()
{
    int i, cnt = 0, j;
    for(i = 2; i < MAX; i++)
    {

        if(!flag[i])    p[cnt++] = i;
        for(j = 0; j < cnt && i * p[j] <= MAX; j++)
        {
            flag[i * p[j]] = true;
            if(i % p[j] == 0)   break;
        }
    }
    printf("%d\n", cnt);
}

int main()
{
    init();
    return 0;
}
