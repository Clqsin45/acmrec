#include <stdio.h>
#include <string.h>

int f[100002], d[4004], a[14], b[14];

int max(int x, int y) // return max
{
    return x > y ? x : y;
}

int main(void)
{
    int n, m, i , j, st = 1, ct = 1;

    while(scanf("%d", &m) != EOF)
    {
        scanf("%d",&n);
        memset(f, 0, sizeof(f));  //reset f to 0

        for(i = 1; i <= n; i++)
        {
            scanf("%d%d", &a[i], &b[i]);
            //������ѹ��
            while(a[i] >= st*2)
            {
                d[ct++] = b[i] * st;  //dΪһ������ļ�ֵ
                a[i] -= st;     st *= 2;
            }
            if(a[i] > 0)
                d[ct++]  = b[i] * a[i];
            //������ѹ������
            st = 1;
        }
        for(i = 1; i < ct; i++)
        {
            for(j = m; j >= d[i]; j--)
            {
                if(j - d[i] >= 0)
                {
                    f[j] = max(f[j], f[j - d[i]] + d[i]);   //ȷ���Ƿ������м���d[i]
                }
            }
        }
        printf("%d\n", f[m]);
        ct = 1;
    }
    system("pause");
    return 0;
}
