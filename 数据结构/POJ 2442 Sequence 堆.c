#include <stdio.h>
#include <string.h>
int a[2][2002], heap[2002];
int t, m, n;

void qsort(int *v,int l, int r)
{
    int i = l , j = r, s = v[(l+r)/2], temp;
    while(i<=j)
    {
        while(v[i] < s) i++;
        while(v[j] > s) j--;
        if(i <= j)
        {
            temp = v[i];    v[i] = v[j];    v[j] = temp;
            i++;    j--;
        }
    }
    if(l < j)   qsort(v,l, j);
    if(i < r)   qsort(v,i, r);
}
void heapify(int i)
{
    int max = i, left = 2 * i, right = 2 * i + 1, temp;
    if(left <= n && heap[max] < heap[left]) max = left;
    if(right <= n && heap[max] < heap[right])   max = right;
    if(max != i)
    {
        temp = heap[i]; heap[i] = heap[max];    heap[max] = temp;
        heapify(max);
    }
}

void insert(int x)
{
    int temp, i;
    heap[++t] = x;
    i = t;
    while(i > 1 && heap[i] > heap[i / 2])
    {
        temp = heap[i];     heap[i] = heap[i /2];   heap[i / 2] = temp;
        i /= 2;
    }
}
int main(void)
{
    int tcase, i, j, sign,k;
    scanf("%d", &tcase);
    while(tcase--)
    {
        //memset(heap,44, sizeof(heap));
        scanf("%d%d", &m, &n);
        for(i = 1; i <= m; i++)
        {
            sign = 0; t = 0;
            if(i == 1)
            {
                for(j = 1; j <= n ; j++)
                    scanf("%d", &a[0][j]);
                qsort(a[0],1,n);
                continue;
            }
            else
            {
                for(j = 1; j <= n ; j++)
                    scanf("%d", &a[1][j]);
            }


            qsort(a[1], 1, n);

            for(j = 1; j <= n; j++)
                insert(a[0][1] + a[1][j]);
            //for(j = 1; j <= n; j++) printf("%d\n", heap[j]);
            for(j = 2; j <= n ; j++)
            {
                for(k = 1; k <= n; k++)
                {
                    if(heap[1] < (a[0][j] + a[1][k]))
                    {
                        if(k == 1)  sign = 1;
                        break;
                    }
                    heap[1] = a[0][j] + a[1][k];
                    heapify(1);
                }
                if(sign)    break;
            }
            for(j = 1; j <= n; j++)
                a[0][j] = heap[j];
            qsort(a[0],1,n);
        }
        for(i = 1; i < n; i++) printf("%d ", a[0][i]);
        printf("%d\n", a[0][n]);
    }


    return 0;
}
