#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX 10050
struct directory
{
    char di[20];
    int pos;
}dir[MAX], ans[MAX];
char st[20];
int l[MAX], s[MAX], e[MAX], total;  // s��¼������ȵĿ�ʼλ�� e ����λ�� total�𰸸���
bool cmp(directory a, directory b)  //�������������
{
    if(strlen(a.di) == strlen(b.di))  return strcmp(a.di, b.di) > 0;
    return strlen(a.di) < strlen(b.di);
}

bool out(directory a, directory b)  //�����ֵ��еĳ���˳������
{
    return a.pos < b.pos;
}

int find(int f, int sd)    //д��shiһ���ıȽϡ������ϴ��ں�С�ڿ����ٸĵü��һЩ������
{
    int dif, i, j, ct = 0, k;    //���鴮�Ĳ�ͬ�ַ�����
    if(f == sd)
    {
        for(i = s[f]; i <= e[f]; i++)
        {
            dif = 0;
            for(j = 0; j < f; j++)
            {
                if(st[j] != dir[i].di[j])       //������ͬ��dif++ �������1�Ļ�˵�������滻һ���ַ����������
                {
                    dif++;
                    if(dif > 1) break;
                }
            }
            if(dif == 1)       //���Һ�ֻ��һ���ַ���ͬ �������
            {
                ct ++;
                strcpy(ans[total].di, dir[i].di);
                ans[total++].pos = dir[i].pos;
            }
        }
        return ct;    //���ر��ָ���
    }
    if(f < sd)        //���Ҵ�����һ���ַ���
    {
        for(i = s[f]; i <= e[f]; i++)
        {
            dif = 0;
            for(j = k = 0; j < sd; )
            {
                if(dir[i].di[j] == st[k])    //��ͬʱ�Ƚ���һ��
                {
                    k++;    j++;
                }
                else                   //��ͬʱ���Ҵ�������һ�� ͬʱ���Ӳ����ַ����� ����һ�򲻷���
                {
                    k++;
                    dif++;
                    if(dif > 1)
                        break;
                }
            }
            if(dif == 1)
            {
                ct++;   strcpy(ans[total].di, dir[i].di);
                        ans[total++].pos = dir[i].pos;
            }
        }
        return ct;
    }
    if(f > sd)
    {
        for(i = s[f]; i <= e[f]; i++)
        {
            dif = 0;
            for(j = k = 0; j < f; )
            {
                if(dir[i].di[j] == st[k])
                {
                    k++;    j++;
                }
                else        //ͬ�� ���ֵ��е���һ��
                {
                    j++;
                    dif++;
                    if(dif > 1)
                        break;
                }
            }
            if(dif == 1)
            {
                ct++;   strcpy(ans[total].di, dir[i].di);
                                ans[total++].pos = dir[i].pos;
            }
        }
        return ct;
    }
}

int main(void)
{
    int no = 0, lt, ct, i, j;
    bool sign;
    memset(s, -1, sizeof(s));
    while(scanf("%s", dir[++no].di) )
    {
        dir[no].pos = no;           //��¼���ֵ��е�λ��
        if(dir[no].di[0]== '#')   break;
    }

    sort(dir + 1, dir + no, cmp);  //�Գ�������
    l[0] = 0;

    for(i = 1; i < no; i++)      //�����ֵ� ��¼ÿ�����ȵ���ʼλ�úͽ���λ��
    {
        l[i] = strlen(dir[i].di);
        if(l[i] != l[i - 1])    s[l[i]] = i;    e[l[i-1]] = i - 1;
    }
    e[l[no - 1]] = no - 1;

    while(scanf("%s", st))      //���Ҵ� ��д��shi��  sad
    {
        total = 0;
        if(st[0] == '#')    break;
        lt = strlen(st);
        if(s[lt] == -1)         //���û�г�����ͬ�Ĵ�
        {
            ct = 0;
            if(s[lt - 1] != -1) ct += find(lt - 1, lt);
            if(s[lt + 1] != -1) ct += find(lt + 1, lt);
            //��¼�𰸸���
            printf("%s:", st);
            //for(i = 0; i < ct; i++) printf("%d\n", ans[i].pos); ��ʾ��ʵ֤��û�г��Ȳ����ֵ��еģ���Ϊ��С�Ľ�������ȻҲAC��
            sort(ans, ans + ct, out);    //�����ֵ�ʱ������
            for(i = 0; i < ct; i++)
            {
                printf(" %s", ans[i].di);
            }
            printf("\n");
            continue;
        }
        sign = false;
        for(i = s[lt]; i <= e[lt]; i++)        //����ʱ���Ƿ����ֵ��г�����
        {
            if(strcmp(dir[i].di, st) == 0)
            {
                printf("%s is correct\n", st);
                sign = true;
                break;
            }
        }

        if(sign)    continue;

        ct = 0;
        ct += find(lt, lt);
        if(s[lt - 1] != -1) ct += find(lt - 1, lt);
        if(s[lt + 1] != -1) ct += find(lt + 1, lt);
        sort(ans, ans + ct, out);
        printf("%s:", st);
        for(i = 0; i < ct; i++)
        {
            printf(" %s", ans[i].di);
        }
        printf("\n");
    }
    return 0;
}
