#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MAX 1000002

char s[3][MAX];
int f[MAX << 2];

void pushup(int d, int x)
{
    if(f[x << 1] == d)
        f[x] = f[x << 1] + f[x << 1 | 1];
    else f[x] = f[x << 1];
}

void build(int l, int r, int rt)
{
    if(l == r)
    {
        if(s[1][l] == s[2][l])      f[rt] = 1;
        else f[rt] = 0;
        return;
    }
    int m =(l + r) >> 1;
    build(lson);    build(rson);
    pushup(m - l + 1, rt);
    return;
}

void modify(int p, int l, int r, int rt)
{
    if(l == r)
    {
        if(s[1][l] == s[2][l])  f[rt] = 1;
        else f[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m)  modify(p, lson);
    else modify(p, rson);
    pushup(m - l + 1, rt);
    return;
}

int require(int p, int l, int r, int rt)
{
    if(l == r)  return f[rt];
    int m = (l + r) >> 1, temp = 0;
    if(p <= m)
    {
        temp = require(p, lson);
        if(temp == m - p + 1)   temp += f[rt << 1 | 1];
        return temp;
    }
    else return require(p, rson);

}
int main(void)
{
    int l1, l2, T, CT, lt, m, wh, pos, op;
    char ch;
    cin>>T;
    for(CT = 1; CT <= T; CT++)
    {
        scanf("%s%s", s[1], s[2]);
        l1 = strlen(s[1]);  l2 = strlen(s[2]);
        lt = l1 < l2 ? l1 : l2;
        build(0, lt - 1, 1);
        printf("Case %d:\n", CT);

        cin>>m;
        while(m--)
        {
            scanf("%d", &op);
            if(--op)
            {
                scanf("%d", &pos);
                if(pos >= lt)
                {
                    cout<<"0"<<endl;
                }
                printf("%d\n", require(pos, 0, lt - 1, 1));
            }
            else
            {
                scanf("%d %d %c", &wh, &pos, &ch);
                if(pos >= lt)   continue;
                s[wh][pos] = ch;
                modify(pos, 0, lt - 1, 1);
            }
        }
    }
    return 0;

}
