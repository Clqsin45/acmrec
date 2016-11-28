#include <stdio.h>
#include <iostream>
using namespace std;
int rx[20], ry[20];
int step, sign = 0, map = 0;
int judge(void)
{
    if(map == 0xFFFF)    return 1;
    else return 0;
}
void find(int t)
{
    int x, y, i;
    map = map^(0x1<<t);
    x = t / 4;
    y = t % 4;
    for(i = 0; i < 4; i++)
        map = map ^ (0x1 << (4 * x + i));
    for(i = 0; i < 4; i++)
        map = map ^ (0x1 << (i * 4 + y));
    return;
}

void dfs(int bit, int deep)
{
    int x, y, i;
   // printf("!%d  %d\n", bit, deep);
    if(deep == step)
    {
        sign = judge();
        return;
    }
    if(sign || bit > 15)   return;
    x = rx[deep] = bit / 4;
    y = ry[deep] = bit % 4;
    find(bit);
    if(y < 4)
         dfs(bit + 1, deep + 1);
    else
        dfs((bit + 4) / 4 * 4,deep + 1);
    find(bit);
    if(y < 4)
        dfs(bit + 1, deep);
    else
        dfs((bit + 4) / 4 * 4,deep);
    return;
}
int main(void)
{
    //freopen("out.txt", "w", stdout);
    char temp;
    int i, j;
    map = 0;
    for(i = 0;i < 4; i ++)
        for(j = 0;j < 4;j ++)
        {
            cin>>temp;
            if(temp=='-')
                map=map^(0x1<<(i*4+j));
        }

    for(step = 0; step <= 16; step ++)
    {
        dfs(0, 0);
        if(sign) break;
    }
    printf("%d\n",step);
    for(i = 0 ; i < step;i ++)
    {
        printf("%d %d\n", rx[i] + 1, ry[i] + 1);
    }

    return 0;
}
