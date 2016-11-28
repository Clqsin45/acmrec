#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 505
#define UL long long
#define INF 0x3f7f7f7f
#define HA 999983
#define HB 999979
#define x 53
#define y 41
int va[HA], vb[HB], locx[HA], locy[HB];
int a[MAX][MAX];
char temp[MAX];
UL reca[MAX], recb[MAX], basa[MAX], basb[MAX], na, nb;
int n, m, ansx, ansy, now;

void init(int z)
{
    int i;
    for(i = 2; i <= z; i++)
    {
        basa[i] = basa[i - 1] * x % HA;
        basb[i] = basb[i - 1] * y % HA;
    }
}


void clear()
{
    memset(reca, 0,sizeof(reca)); memset(recb, 0, sizeof(recb));
    memset(va, 0, sizeof(va));    memset(vb, 0, sizeof(vb));
    memset(locx, 0, sizeof(locx));  memset(locy, 0, sizeof(locy));
}

bool check(int mid)
{
    int i, j;
    clear();

    for(i = 1; i <= m; i++)
    {
        for(j = 1; j < mid; j++)
        {
            reca[i] = (reca[i] * x + a[j][i]) % HA;
            recb[i] = (recb[i] * x + a[j][i]) % HB;
        }
    }
    for(i = mid; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            reca[j] -= basa[mid] * a[i - mid][j] % HA;
            if(reca[j] < 0) reca[j] += HA;
            reca[j] = (reca[j] * x + a[i][j]) % HA;

            recb[j] -= basa[mid] * a[i - mid][j] % HB;
            if(recb[j] < 0) recb[j] += HB;
            recb[j] = (recb[j] * x + a[i][j]) % HB;



            //printf("%d  %d  %lld  %lld\n", i, j, reca[j], recb[j]);
        }

        na = nb = 0;
        for(j = 1; j <= mid; j++)
        {
            na = (na * y + reca[j]) % HA;
            nb = (nb * y + recb[j]) % HB;
        }
       // printf("%d  %lld    %lld\n",i, na, nb);
        if(va[na] && vb[nb])
        {
            ansx = i; ansy = mid;
            now = na;   return true;
        }
        va[na] = 1; vb[nb] = 1;
        locx[na] = i;    locy[na] = mid;
        for(j = mid + 1; j <= m; j++)
        {
            na -= basb[mid] * reca[j - mid] % HA;
            if(na < 0)  na += HA;
            na = (na * y + reca[j]) % HA;

            nb -= basb[mid] * recb[j - mid] % HB;
            if(nb < 0)  nb += HB;
            nb = (nb * y + recb[j]) % HB;
           // printf("%d  %d  %lld %lld\n", i, j, na, nb);
            if(va[na] && vb[nb])
            {
                ansx = i; ansy = j; now = na;
               // printf("!!2\n");
                return true;
            }
            va[na] = 1; va[nb] = 1;
            locx[na] = i; locy[na] = j;
            //printf("%d %d %lld\n", i, j, na);
        }
    }
    return false;
}

int main(void)
{
    //freopen("in.txt", "r", stdin);
   // freopen("o.txt", "w", stdout);
    int i, j, ans, N, high, low, mid;
    scanf("%d%d", &n, &m);
    N = max(n, m);
    basa[1] = basb[1] = 1;
    init(N);

    for(i = 1; i <= n; i++)
    {
        scanf("%s", temp + 1);
        for(j = 1; j <= m; j++)
        {
            a[i][j] = temp[j] - 'a' + 1;
        }
    }

    low = 0;    high = min(n, m) + 1;
    while(low <= high)
    {
        mid = (low + high) >> 1;
        //printf("%d\n", mid);
        if(check(mid))
        {
            ans = mid;  low = mid + 1;
            //printf("%d\n", ans);
        }
        else high = mid - 1;
    }
    printf("%d\n", ans);
    if(ans > 0)
    {
        check(ans);
        i = locx[now] - ans + 1;   j = locy[now] - ans + 1;
        printf("%d %d\n", i, j);
        i = ansx - ans + 1; j = ansy - ans + 1;
        printf("%d %d\n", i, j);
    }
    return 0;
}
