#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXR 10004
#define MAXC 100
char s[MAXR][MAXC];
int next[MAXR],  ctr[MAXC], r, c;

void getnext(void)
{
    int i = 0, j = -1;  next[0] = -1;
    while(i < r)
    {
		//纵向寻找
        if(j == -1 || strcmp(s[i], s[j]) == 0)
        {
            i++;    j++;
            next[i] = j;
        }
        else j = next[j];
    }
}
int main(void)
{
    int i, j, k, x, y;
    scanf("%d%d", &r, &c);

    memset(ctr, 0, sizeof(ctr));
    for(i = 0; i < r; i++)
    {
        scanf("%s", s[i]);
        for(j = 1; j <= c; j++) //枚举长度
        {
            for(x = 0, y = j; y < c;x++, y++)
                if(s[i][x % j] != s[i][y])  break;
            if(y == c)  ctr[j]++;          //循环周期个数
        }
    }
    for(i = 1; i <= c; i++)
        if(ctr[i] == r) break;  //对于每一个都循环
    for(j = 0 ; j < r; j++) s[j][i] = '\0';     //截尾
    getnext();
    printf("%d\n", i * (r - next[r]));
    system("pause");
    return 0;
}
