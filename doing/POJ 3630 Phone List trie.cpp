#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 70000
#define INF 0x7f7f7f7

struct trie
{
    int next[11], num;
    bool sign;
}t[MAX];
int num = 0;

bool insert(char a[])
{
    int now = 0, i, j, la = strlen(a);
    bool flag = 1;
    char temp;
    for(i = 0; i < la; i++)
    {
        temp = a[i] - '0';
        if(t[now].sign) return 0;
        if(t[now].next[temp] == -1)
        {
            num++;  flag = 0;
            for(j = 0; j < 10; j++)
                t[num].next[j] = -1;
            t[num].sign = 0;
            t[now].next[temp] = num;
        }
        now = t[now].next[temp];
    }
    t[now].sign = 1;
    return !flag;
}
int main(void)
{
    int TC, i, n, flag = 1;
    char a[11];
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d", &n);
        num = 0;    flag = 1;
        for(i = 0; i < 10; i++)
            t[0].next[i] = -1;
        t[0].sign = 0;
        while(n--)
        {
            scanf("%s", a);
            if(!flag)   continue;
            if(!insert(a))
            {

                flag = 0;
            }
        }

        if(flag)    printf("YES\n");

        else printf("NO\n");

    }
    return 0;
}
