#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 500010
#define INF 0x7f7f7f7f

int in[MAX], fa[MAX];
struct tree
{
    int next[26], no;
    bool sign;
}t[MAX];

int num = 0, nt = 0;


void init(int x)
{
    t[x].sign = 0;
    for(int i = 0; i < 26; i++)     t[x].next[i] = -1;
}

int insert(char a[])
{
    int now = 0, la = strlen(a), i, flag = 0, temp;
    for(i = 0; i < la; i++)
    {
        temp = a[i] - 'a';
        if(t[now].next[temp] == -1)
        {
            num++;  init(num);
            flag = 1;

            t[now].next[temp] = num;
        }
        now = t[now].next[temp];
    }

    if(flag || t[now].sign == 0)
    {
        t[now].no = ++nt;
        t[now].sign = 1;
    }

    return t[now].no;
}

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void belink(int x, int y)
{
    x = find(x);    y = find(y);
    if(x == y)  return;
    fa[x] = y;
}

bool check(void)
{
    int count = 0, i;
    for(i = 1; i <= nt; i++)
        if(fa[i] == i)   count++;
    if(count > 1)   return 0;
    count = 0;
    for(i = 1; i <= nt; i++)
    {
        if(in[i]& 1)    count++;
    }
    if(count == 0 || count == 2)    return 1;
    return 0;
}

int main(void)
{
    int L, x, y;
    char s1[11], s2[11];

    memset(in, 0, sizeof(in));

    for(int i = 1; i < MAX; i++) fa[i] = i;
    init(0);

    while(scanf("%s%s", s1, s2) != EOF)
    {
        x = insert(s1);
        y = insert(s2);
        in[x]++;   in[y] ++;
        L ++;

        belink(x, y);
    }
    if(L == 0)  cout<<"Possible"<<endl;
    else if(check())    cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;

    return 0;
}
