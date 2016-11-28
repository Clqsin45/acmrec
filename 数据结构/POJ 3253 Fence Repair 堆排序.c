#include <stdio.h>

int a[20002], n;

void swap(int x, int y)
{
    int t = a[x];   a[x] = a[y];    a[y] = t;
}

int heapify(int i)
{
    int min = i, right = 2 * i + 1, left = 2 * i;
    if(left <= n && a[min] >= a[left])    min = left;
    if(right <= n && a[min] >= a[right])  min = right;
    if(i != min)
    {
        swap(min, i);
        heapify(min);
    }
}

void outtop(void)
{
    a[1] = a[n--];
    heapify(1);
    return;
}

void insert(int x)
{
    int i;
    a[++n] = x;
    i = n;
    while(i > 1 && a[i] < a[i / 2])
    {
        swap(i, i/2);
        i /= 2;
    }
}

int main(void)
{
    int i, t;
    __int64 cost = 0;
    scanf("%d", &n);
    for(i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(i = (n / 2); i >= 1; i--)   heapify(i);
    while(n > 1)
    {
        t = 0;

        t += a[1];     outtop();
        t += a[1];     outtop();
        cost += t;
        insert(t);
    }
    printf("%I64d\n", cost);
    return 0;
}
