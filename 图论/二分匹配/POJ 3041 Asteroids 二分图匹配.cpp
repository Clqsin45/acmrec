#include <stdio.h>
#include <string.h>
#define MAX 555

int f[MAX][MAX] = {0}, v[MAX], match[MAX], n, k;

int dfs(int x)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        if(f[x][i] && !v[i])       //�б����� ��δ������
        {
            v[i] = 1;
            if(match[i] == -1 || dfs(match[i]))  //�����һ��δ��� �����������ҵ�δ���
            {
                match[i] = x;                   //�ı����ӷ�ʽ
                return 1;
            }
        }
    }
    return 0;
}
int main(void)
{
    int i, ans = 0, st1, st2;
    scanf("%d%d", &n, &k);
    for(i = 1; i <= k; i++)
    {
        scanf("%d%d", &st1, &st2);
        f[st1][st2] = 1;           //����ΪX�� ��ΪY�� ����������һ��
    }
    memset(match, -1, sizeof(match));  //���б���δƥ��
    for(i = 1; i <= n; i++)
    {
        memset(v, 0, sizeof(v));        //���еı߶�δ�ѹ�
        if(dfs(i))  ans++;              //ͳ��ƥ��
    }
    printf("%d\n", ans);
    return 0;
}
