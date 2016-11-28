#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 100005
#define M 10000019
#define INF 0x3f7f7f7f
#define LL long long
int f[MAX] = {0}, p[MAX], m[MAX], TC;
struct rec
{
    int no, num, t;
    LL ans;
    bool operator <(const rec& I)const
    {
        if(num == I.num)    return no<I.no;
        return num < I.num;
    }
}r[4004];
bool flag[MAX] = {false};
/**********8
            mx = 0; a = false;
        ans = 1;
        scanf("%d%d", &n, &t);
        cal();
        //printf("orz\n");
        for(i = 0; i <= mx; i++)
        {
            if(f[i] < t)   break;
            a = true;
            ans = (ans * quick(p[i], f[i] / t )) % M;
        }
**********/

LL quick(LL m, int p)
{
    LL ans = 1;
    for(; p; p >>= 1)
    {
        if(p & 1)   ans = (ans * m) % M;
        m = m * m % M;
    }
    return ans;
}
void cal(int n)
{
    int i, j, ct, no = 1, m, t, mx = -1;
    LL ans; bool a;
    for(i = 2; i <= n; i++)
    {
        t = i;
        for(j = 0; p[j] <= t; j++)
        {
            if(t % p[j])    continue;
            while(!(t % p[j]))
            {
                f[j]++;
                t /= p[j];
                mx = max(mx, j);
            }
        }
        if(r[no].num < i)continue;
        while(r[no].num == i)
        {
            ans = 1;    a = false;
            for(j = 0; j <= mx; j++)
            {
                if(f[j] < r[no].t)    break;
                a = true;
                ans = (ans * quick(p[j], f[j] / r[no].t )) % M;
            }
            if(a)   r[no].ans = ans;
            no++;
        }
    }

}
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
        for(i = 1; i <= 13; i++){
        printf("%d %d\n", i, flag[i] ? 1 : 0);
    }
}



int main(void)
{
    int tc, i;
    LL ans;
    bool a;
    init();
    scanf("%d", &TC);
    for(tc = 1; tc <= TC; tc++)
    {
        scanf("%d %d", &r[tc].num, &r[tc].t);
        r[tc].no = tc;      r[tc].ans = -1;
    }
    sort(r + 1, r + 1 + TC);
    for(i = 1; i <= TC; i++)
        m[r[i].no] = i;
    cal(r[TC].num);
    for(i = 1; i <= TC;i ++)
    {
        printf("Case %d: %lld\n", i, r[m[i]].ans);
    }

    return 0;
}
