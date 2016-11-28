#include <stdio.h>
#include <string.h>
int in[8002], f[8002], out[8002];
int n;

int lowbit(int x)
{
    return x & (-x);
}
int getsum(int x)
{
    int sum = 0;
    for(; x > 0; x -= lowbit(x))
        sum += f[x];
    return sum;
}
int find(int key)
{
    int left = 1, right = n + 1, mid, cnt;
    while(left < right)
    {
        mid = (left + right) / 2;
        cnt = mid - getsum(mid);
        if(cnt < key)   left = mid + 1;
        else right = mid;
    }
    return left;
}

void modify(int x)
{
    for(; x <= n; x += lowbit(x))   f[x] ++;
}

int main(void)
{
    int st, i;
    scanf("%d", &n);
    memset(f, 0, sizeof(f));
    for(i = 2; i <= n; i++) scanf("%d", &in[i]);
    in[1] = 0;
    for(i = n; i >= 1; i--)
    {
        st = find(in[i] + 1);
        out[i] = st;
        modify(st);
    }
    for(i = 1; i <= n; i++)
    {
        printf("%d\n", out[i]);
    }
    return 0;
}
