#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 1004
#define INF 0x7f7f7f7f

struct point
{
    int sum;
    int next[27];
    bool sign;
}t[MAX * 100];
char s[MAX][22];
int num = 0;

inline void init(int x)
{
    int i;
    for(i = 0 ; i< 26; i++)
        t[x].next[i] = -1;
    t[x].sign = 0;  t[x].sum = 0;
}
void insert(char a[])
{
    int now = 0, i, la = strlen(a);
    int temp;
    for(i = 0; i < la; i++)
    {
        temp = a[i] - 'a';
        if(t[now].next[temp] == -1)
        {
            num++;
            init(num);

            t[now].next[temp] = num;
        }

        now = t[now].next[temp];
        t[now].sum++;
    }
    t[now].sign = 1;
    return;
}

void find(char *a)
{
    //printf("%s", a);
    int now = 0, la = strlen(a), i, temp, k = 0;
    char ans[22];
    for(i = 0; i < la; i++)
    {
        temp = a[i] - 'a';
        now = t[now].next[temp];
        ans[k++] = a[i];
        if(t[now].sum == 1) break;

    }
    ans[k] = '\0';
    printf("%s %s\n", a, ans);
    return;
}
int main(void)
{
    int i, k = 0;
    init(0);

    while(scanf("%s", s[++k]) != EOF)
    {
        insert(s[k]);
    }

    for(i = 1; i < k ; i++)
    {
        find(s[i]);
    }
    return 0;
}
