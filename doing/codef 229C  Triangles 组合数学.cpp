#include <stdio.h>
#define MAX 1000008
__int64 s[MAX] = {0};
int main(void)
{
    int  x, y, i;
    __int64 ans, total, n, m, sum = 0;
    scanf("%I64d%I64d", &n, &m);
    while(m--)
    {
        scanf("%d%d", &x, &y);
        s[x] ++;    s[y] ++;
    }
    if(n >= 3) ans = n * (n - 1) * (n - 2) / 6;     //�ܹ����������ô�������������� cn3
    else n = 0;
    for(i = 1; i <= n; i++)
    {
        sum += s[i] * (n - 1 - s[i]);     //��������һ���㣬 ����n - 1�������� ��mͼ�еı�*����m�еı߼�Ϊ�õ�ı���ɵķ�ͬɫ�Ǹ���
    }
    sum /= 2;      //ÿ���߱�����������
    ans -= sum;
    printf("%I64d\n", ans);
    return 0;
}
