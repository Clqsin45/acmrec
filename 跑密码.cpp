#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <ctime>
using namespace std;

#define N
#define M
#define LL __int64
#define INF 0x3f7f7f7f

char d[100];
int main(void)
{
    int x, i, no =0 ;
    char c[13];
    srand((unsigned)time(NULL));
    for(i = 0; i < 26; i++)
        d[no++] = 'A' + i;

    for(i = 0 ; i < 26; i++)
        d[no++] = 'a' + i;
    for(i = 0; i < 10; i++)
        d[no++] = '0' + i;
    for(i = 0; i < 10; i++)
    {
        c[i] = d[rand() % no];
    }
    c[i] = '\0';
    printf("%s\n", c);
    return 0;
}
