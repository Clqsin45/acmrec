#include <stdio.h>
#include <string.h>
#define MAX 100100
struct point
{
    int now, next, w;
}p[MAX *2], q[MAX * 2];
int headp[MAX], v[MAX], headq[MAX], dfn[MAX], ans[MAX], dis[MAX];
int n, m, no;

void add(int x, int y , int z, int *s, point *str)
{
    str[++no].next = s[x];
    s[x] = no;
    str[no].now = y;
    str[no].w = z;
}
int find(int x)             //Ѱ�Ҹ��ڵ�ͬʱѹ��·��
{
    if(dfn[x] == x)    return x;
    else return dfn[x] = find(dfn[x]);
}
void tarjan(int x, int ndis)
{
    int i, y, w;
    dfn[x] = x;
    dis[x] = ndis;
    v[x] = 1;
    for(i = headq[x]; i != -1; i = q[i].next)
    {
        y = q[i].now;   w = q[i].w;
        if(v[y])
        {
            ans[w] = dis[x] + dis[y] - 2 * dis[find(y)];      //q��洢����i,��ans[w]���Ǹõ�ľ��� ͬʱ����yδ���߹��Ͳ����£���y��ʱ��x�Ѹ��£����Ǹ��´�
                                                              //dis���������ǴӸ���i�ľ��룬��������ľ��뼴Ϊ���ǵ����ľ����ȥ���ǹ�ͬ�����ȵ����ľ��������
        }
    }
    for(i = headp[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;   w = p[i].w;
        if(!v[y])
        {
            tarjan(y, ndis + w);                              //��x���ӽڵ㣬�������ӽڵ㵽���ڵ�ľ���
            dfn[y] = x;
        }
    }
}
int main(void)
{
    int st1, st2, stt, st, i;
    char b;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(headp, -1, sizeof(headp));
        memset(headq, -1, sizeof(headq));
        memset(v, 0, sizeof(0));
        memset(dfn, -1, sizeof(dfn));
        no = 0;

        for(i = 1; i  <= m; i++)
        {
            scanf("%d%d%d %c", &st1, &st2, &stt, &b);
            add(st1, st2, stt, headp, p);
            add(st2, st1, stt, headp, p);
        }
        scanf("%d", &st);   no = 0;
        for(i = 1; i <= st; i++)
        {
            scanf("%d%d", &st1, &st2);
            add(st1, st2, i, headq, q);
            add(st2, st1, i, headq, q);
        }
        tarjan(1, 0);
        for(i = 1; i <= st; i++)    printf("%d\n", ans[i]);
    }
    return 0;
}
