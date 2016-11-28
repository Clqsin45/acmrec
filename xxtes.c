#include <stdio.h>
#define MAX 11111
int heap[MAX] = {0}, n = 0, count = 0;

void swap(int x, int y)
{
    int temp = heap[x];
    heap[x] = heap[y];
    heap[y] = temp;
}

void heapify(int x)
{
    int min = x, left = x * 2, right = x * 2 + 1;
    if(left <= n && heap[min] > heap[left] )   min = left;
    if(right <= n && heap[min] > heap[right])  min = right;
    if(min != x)
    {
        swap(min, x);
        if(min * 2 <= n)   heapify(min);
    }
}

void outop(void)
{
    heap[1] = heap[n --];
    heapify(1);
    return;
}

void insert(int x)
{
    int i;
    heap[++n] = x;
    i = n;
    while(i > 1 && heap[i] < heap[i / 2])
    {
        swap(i, i / 2);
        i /= 2;
    }
}
int main(void)
{
    int i, t;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &heap[i]);
    }
    for(i = (n / 2); i >= 1; i--)   heapify(i);

    while(n > 1)
    {
        t = 0;
        t += heap[1];  outop();
        t += heap[1];  outop();
        count += t;
        insert(t);
    }
    printf("%d\n", count);
    return 0;
}
