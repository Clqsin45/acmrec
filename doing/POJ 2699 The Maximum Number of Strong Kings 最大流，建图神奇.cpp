#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define N 86
#define M
#define LL __int64
#define INF 0x3f7f7f7f

int f[N][N], st[M], d[N], more[N];
int no;
string ch;
int main(void)
{
    int TC, i, n, m, j, ct, a[14];
    cin >> TC;
    while(TC--)
    {
        n = 0;
        gets(ch);
        stringstream sti(ch);
        while(sti>> a[++n]);
        sort(a + 1, a + n + 1);
        m = n * (n - 1) / 2;
        for(i = 1; i <= n; i++)
        {

        }
    }
    return 0;
}
