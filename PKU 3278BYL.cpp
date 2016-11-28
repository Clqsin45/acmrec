#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, t;
int d[100110]={0};
int f[100110]={0};

void bfs()
{
     int op = 1, cl = 1, x = n;   //ͷβ  x�����ڵ�λ��
     memset(d, 44, sizeof(d));
     memset(f, 0, sizeof(f));
     d[n] = 0;  //�߹��ĳ���
     f[1]=n;   //����
     while(op >= cl)
     {
         x = f[cl];
         if(x - 1 >= 0 && d[x - 1] > d[x] + 1)
         {
             d[x - 1] = d[x] +1;
             f[++ op] = x - 1;
         }
         if(x + 1 <= 100100 && d[x + 1] > d[x] + 1)
         {
             d[x + 1] = d[x] +1;
             f[++ op] = x + 1;
         }
         if(x * 2 <= 100100 && d[x * 2] > d[x] + 1)
         {
             d[x * 2] = d[x] +1;
             f[++ op] = x * 2;
         }
         cl ++;
     }
}

int main()
{
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d", &n, &m);
        bfs();
        printf("%d\n", d[m]);
    }
    return 0;
}
