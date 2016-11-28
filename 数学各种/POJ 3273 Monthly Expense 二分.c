#include <stdio.h>
#define INF 10000000

int a[100005], n, m, max, min;

int count(int l)
{
    int i, sum = 1, st = 0;  //这里！sum的初始化！！！！！
    for(i = 1; i <= n; i++)
    {
        st += a[i];
        if(st > l)
        {
            sum ++;
            st = a[i];
        }
    }
    return sum;
}

int slove(int sum)
{
    int left = max, right = sum,  mid, ret = -1;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(count(mid) <= m && mid >= min)
        {
            ret = mid;
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
int main(void)
{
    int i, sway, sum = 0;
    scanf("%d%d", &n, &m);
    max = 0;    min = INF;
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
        min = (min < a[i] ? min : a[i]);
        max = (max > a[i]? max: a[i]);
    }
    sway = slove(sum);
    printf("%d\n",sway);
    return 0;
}
