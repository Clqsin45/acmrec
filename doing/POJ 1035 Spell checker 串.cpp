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
int l[MAX], s[MAX], e[MAX], total;  // s记录这个长度的开始位置 e 结束位置 total答案个数
bool cmp(directory a, directory b)  //起初按长度排序
{
    if(strlen(a.di) == strlen(b.di))  return strcmp(a.di, b.di) > 0;
    return strlen(a.di) < strlen(b.di);
}

bool out(directory a, directory b)  //按在字典中的出现顺序排序
{
    return a.pos < b.pos;
}

int find(int f, int sd)    //写成shi一样的比较。理论上大于和小于可以再改得简短一些啊。。
{
    int dif, i, j, ct = 0, k;    //本组串的不同字符个数
    if(f == sd)
    {
        for(i = s[f]; i <= e[f]; i++)
        {
            dif = 0;
            for(j = 0; j < f; j++)
            {
                if(st[j] != dir[i].di[j])       //遇到不同的dif++ 如果大于1的话说明不能替换一个字符获得期望的
                {
                    dif++;
                    if(dif > 1) break;
                }
            }
            if(dif == 1)       //查找后只有一个字符不同 加入答案中
            {
                ct ++;
                strcpy(ans[total].di, dir[i].di);
                ans[total++].pos = dir[i].pos;
            }
        }
        return ct;    //返回本种个数
    }
    if(f < sd)        //查找串丢弃一个字符的
    {
        for(i = s[f]; i <= e[f]; i++)
        {
            dif = 0;
            for(j = k = 0; j < sd; )
            {
                if(dir[i].di[j] == st[k])    //相同时比较下一个
                {
                    k++;    j++;
                }
                else                   //不同时查找串查找下一个 同时增加差异字符个数 大于一则不符合
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
                else        //同理 看字典中的下一个
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
        dir[no].pos = no;           //记录在字典中的位置
        if(dir[no].di[0]== '#')   break;
    }

    sort(dir + 1, dir + no, cmp);  //对长度排序
    l[0] = 0;

    for(i = 1; i < no; i++)      //处理字典 记录每个长度的起始位置和结束位置
    {
        l[i] = strlen(dir[i].di);
        if(l[i] != l[i - 1])    s[l[i]] = i;    e[l[i-1]] = i - 1;
    }
    e[l[no - 1]] = no - 1;

    while(scanf("%s", st))      //查找串 又写成shi了  sad
    {
        total = 0;
        if(st[0] == '#')    break;
        lt = strlen(st);
        if(s[lt] == -1)         //如果没有长度相同的串
        {
            ct = 0;
            if(s[lt - 1] != -1) ct += find(lt - 1, lt);
            if(s[lt + 1] != -1) ct += find(lt + 1, lt);
            //记录答案个数
            printf("%s:", st);
            //for(i = 0; i < ct; i++) printf("%d\n", ans[i].pos); 表示事实证明没有长度不在字典中的，因为不小心交了这句居然也AC了
            sort(ans, ans + ct, out);    //按出现的时间排序
            for(i = 0; i < ct; i++)
            {
                printf(" %s", ans[i].di);
            }
            printf("\n");
            continue;
        }
        sign = false;
        for(i = s[lt]; i <= e[lt]; i++)        //查找时候是否在字典中出现了
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
