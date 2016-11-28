#include <stdio.h>
#include <string.h>

int t, n = 0;
struct command
{
    int time;
    int no;
    int st;
}c[3004];
int heap[3004];

void swap(int x, int y)
{
    int t = heap[x]; heap[x] = heap[y]; heap[y] = t;
}

void heapify(int i)
{
    int min = i, right = i * 2 + 1, left = 2 * i;
    if(left <= n &&((c[heap[min]].time > c[heap[left]].time) ||
                     (c[heap[min]].time == c[heap[left]].time && c[heap[min]].no > c[heap[left]].no)))
        min = left;
    if(right<= n &&((c[heap[min]].time > c[heap[right]].time) ||
                     (c[heap[min]].time == c[heap[right]].time && c[heap[min]].no > c[heap[right]].no)))
        min = right;
    if(min != i)
    {
        swap(i, min);
        heapify(min);
    }
}

int insert(int x)
{
    int i;
    heap[++n] = x;
    i = n;

    while(i > 1 && ((c[heap[i]].time < c[heap[i/2]].time) ||
                    (c[heap[i]].time == c[heap[i/2]].time && c[heap[i]].no < c[heap[i/2]].no)))
    {//printf("heap[%d] = %d  heap[%d]=%d\n", i, x, i/2, heap[i/2]);
        swap(i, i/2);
        i /= 2;
    }
}

int outtop(void)
{
    int top = heap[1];
    heap[1] = heap[n--];
    heapify(1);
    return top;
}

int main(void)
{
    char a[14];
    int tno, tt, i;
    n = 0;  i = 0;
    while(1)
    {
        scanf("%s",a);
        if(strcmp(a,"#") == 0)  break;
        scanf("%d%d", &tno, &tt);
        c[++i].no = tno;    c[i].time = tt;     c[i].st = tt;
        insert(i);
    }

    scanf("%d", &t);

    while(t--)
    {

        tt = outtop();
        printf("%d\n",c[tt].no);
         //printf("###%d :%d  %d: %d\n", heap[1],c[heap[1]].time, heap[2],c[heap[2]].time);

        c[tt].time += c[tt].st;//printf("!!%d   %d\n", tt,c[tt].time);
        insert(tt);
    }

    return 0;
}
