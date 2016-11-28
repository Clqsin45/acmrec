#include <stdio.h>

#define MAX 304
#define INF 0x7f7f7f7f

int f[MAX][MAX], a[MAX], b[MAX];
int m, p;
int judge(int i, int j, int k)
{
    if(a[k] - a[i] + b[i] - b[j] > m || b[k] - b[i] > m)   return 1;    // ��������233333����
    return 0;
}
int main(void)
{
    int st1, st2;
    int i, j, k;
    while(scanf("%d%d", &m, &p) != EOF)
    {
        a[0] = b[0] = 0;
        for(i = 1; i <= p; i++)
        {
            scanf("%d%d", &st1, &st2);
            a[i] = a[i - 1] + st1;      //�ۼ�������i��Ԥ��
            b[i] = b[i - 1] + st2;      //i ��
        }
        for(i = 0; i <= p; i++)
            for (j = 0; j <= p; j++)    f[i][j] = INF;
        f[0][0] = 0;    //��0�ⲻ��ʱ��

        for(i = 0; i <= p; i++) //���i���� 0-p
        {
            for(j = 0; j <= i; j++)
            //for(j' = i; j' >= 0; j'--) // j' = i - j
            {
                for(k = i; k <= p; k++)     //��itok�⣬֮ǰ�ϸ�����j - i
                {
                    if(judge(i, j, k))  break;
                    f[k][k - i] = (f[k][k - i] < f[i][i - j] + 1 ? f[k][k - i] : f[i][i - j] + 1);
                }
            }
        }
        printf("%d\n", f[p][0] + 1);
    }
    return 0;
}
/*
|---j---i---k---------------|
| | | | | | | | | | | | ||
|------------------------|
*/
//��ҹ����дDP�� һ�罬��������
