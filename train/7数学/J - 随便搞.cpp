#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

#define N 10000000
#define M 1000000
#define LL __int64
#define INF 0x3f7f7f7f

int p[N/10];
bool flag[N] = {false};
void init()
{
    int i, cnt = 0, j;
    for(i = 2; i < N; i++)
    {
        if(!flag[i])    {
            p[cnt++] = i;
            printf("%d\n", i);
        }
        for(j = 0; j < cnt && i * p[j] <= N; j++)
        {
            flag[i * p[j]] = true;
            if(i % p[j] == 0)   break;
        }
    }
    printf("%d\n", cnt);

}

int main(void)
{
    freopen("sushu.txt", "w", stdout);
    init();
//    int TC, i, tc, ct;
//    LL n, x;
//    bool sign;
//    scanf("%d", &TC);
//    for(tc = 1; tc <= TC ; tc++)
//    {
//        scanf("%I64d", &n);
//        sign = true;
//        printf("Case %d: ", tc);
//        for(i = 0; p[i] <= n && p[i] < M && sign; i++)
//        {//printf("%d, %d\n", i, p[i]);
//            if(n % p[i])    continue;
//
//            ct = 0;
//            while(!(n % p[i]))
//            {
//                ct++;
//                n /= p[i];
//                if(ct >= 2)
//                {
//                    printf("No\n");
//                    sign = false;
//                    break;
//                }
//            }
//        }
//
//        if(sign)
//        {
//            if(n == 1)
//            {
//                printf("Yes\n");    continue;
//            }
//            x = (LL)sqrt(n);
//            if(x*x == n)
//                printf("No\n");
//            else printf("Yes\n");
//        }
//
//    }
//    return 0;
}
/*******
1000000000000000007
Case 2:
************/
