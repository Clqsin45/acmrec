#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 505
#define LL long long

#define INF 0x3f7f7f7f
#define HA 999983
#define HB 999979
#define x 131
#define y 53
int n, m;
char ch[MAX][MAX];

LL dirx[MAX], diry[MAX], dirxx[MAX], diryy[MAX];
LL fx[MAX][MAX], gx[MAX][MAX], fy[MAX][MAX], gy[MAX][MAX];

struct as
{
    int a, aa, b, bb;
}ans;
struct point
{
    int a, b, val;
}va[HA];
void init(LL *t, LL *tt, int N, int k)
{
    int i;
    for(i = 1; i <= N; i++)
    {
        t[i] = t[i - 1] * k % HA;
        tt[i] = tt[i - 1] * k % HB;
       // printf("%d %lld\n", i, t[i]);
    }
}
//pf + a[i + len] - p^len*a[i];
/*************
  a1 a2 a3 a4 a5 a6 a7 y2
  b1 b2 b3 b4 b5 b6 b7 y1
  c1 c2 c3 c4 c5 c6 c7 y0
  x6 x5 x4 x3 x2 x1 x0
**************/

void calx(int len)
{
    int i, j;
    for(i = 1; i <= n; i++)
    {
        fx[i][0] = gx[i][0] = 0;
        for(j = 1; j < len; j++)
        {
            fx[i][j] = (fx[i][j - 1] * x + (LL)ch[i][j]) % HA;
            gx[i][j] = (gx[i][j - 1] * x + (LL)ch[i][j]) % HB;
            //printf("%d  %d  %lld\n",i, j, fx[i][j]);
        }
        for(; j <= m; j++)
        {
            fx[i][j] = (fx[i][j - 1] * x + (LL)ch[i][j] - dirx[len] * (LL)ch[i][j - len]) % HA;
            fx[i][j] = (fx[i][j] + HA) % HA;
            gx[i][j] = (gx[i][j - 1] * x + (LL)ch[i][j] - dirxx[len] * (LL)ch[i][j - len]) % HB;
            gx[i][j] = (gx[i][j] + HB) % HB;
            //printf("%d  %d  %lld    %lld\n",i, j, fx[i][j],gx[i][j]);
        }
    }
    //......(len)i  12345  5-4
}

void clear()
{
    memset(va, -1, sizeof(va));
}

bool app(int i, int j, int no, int noo)
{
    if(va[no].val == noo)
    {
        ans.a = va[no].a;   ans.aa = i; ans.b = va[no].b;   ans.bb = j;
        return true;
    }
    va[no].val = noo;
    va[no].a = i;   va[no].b = j;
    return false;

}
bool check(int len)
{
    int i, j;
    clear();
    calx(len);
   // ty = m - len + 1;   tx = n - len + 1;
    for(j = len; j <= m; j ++)
    {
        fy[0][j] = gy[0][j] = 0;
        for(i = 1; i < len; i++)
        {
            fy[i][j] = (fy[i - 1][j] * y + fx[i][j]) % HA;
            gy[i][j] = (gy[i - 1][j] * y + gx[i][j]) % HB;
            //printf("%d  %d  %lld\n",i, j, fy[i][j]);
        }
        for(; i <= n; i++)
        {
            fy[i][j] = (fy[i - 1][j] * y + fx[i][j] - fx[i - len][j] * diry[len]) % HA;
            fy[i][j] = (fy[i][j] + HA) % HA;
            gy[i][j] = (gy[i - 1][j] * y + gx[i][j] - gx[i - len][j] * diryy[len]) % HB;
            gy[i][j] = (gy[i][j] + HB) % HB;
            //printf("!!%d  %d  %lld    %lld\n",i, j, fy[i][j], gy[i][j]);
            if(app(i, j, fy[i][j], gy[i][j]))   return true;
        }
    }

    return false;
}
int main(void)
{
    //freopen("in.txt", "r", stdin);
    //freopen("in2.txt", "r", stdin);
   //freopen("o.txt", "w", stdout);
    int i, j, len = 0, high, low, mid;
    scanf("%d%d", &n, &m);
    dirx[0] = dirxx[0] = diryy[0] =  diry[0] = 1;
    init(dirx, dirxx, m, x);   init(diry, diryy, n, y);
    for(i = 1; i <= n; i++)
    {
        scanf("%s", ch[i] + 1);
        for(j = 1; j <= m; j++) ch[i][j] -= 'a';
    }

    low = 0;    high = min(n, m) + 1;
    while(low <= high)
    {
        mid = (low + high) >> 1;
        //printf("~~%d\n", mid);
        if(check(mid))
        {
            len = mid;  low = mid + 1;
        }
        else high = mid - 1;
    }
    printf("%d\n", len);
    if(len > 0)
    {
        check(len);
        printf("%d %d\n%d %d\n", ans.a - len + 1, ans.b - len + 1, ans.aa - len + 1, ans.bb - len + 1);

    }
    return 0;
}
