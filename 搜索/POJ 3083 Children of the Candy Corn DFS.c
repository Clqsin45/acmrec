#include <stdio.h>
#include <string.h>
int n, m , v[50][50] = {{0}}, gox[4][5] = {{0, -1, 0, 1},{0,1,0,-1},{0, 1, 0, -1}, {0 ,-1, 0,1}},
							  goy[4][5]= {{-1, 0, 1, 0},{-1, 0, 1,0 }, {1, 0, -1,0}, {1,0,-1,0}};
int sum, d;
char mp[50][50];
int judge(int x, int y)
{
    if(x < 1 || y < 1 || x > m || y > n) return 0;
    else return 1;
}
void left(int x, int y, int s)
{
    int xx, yy, i;

    for(i = 0; i < 4; i++)
    {
        xx = x + gox[d][(i + s)% 4]; yy = y + goy[d][(i + s)% 4];
        if(mp[xx][yy] == '#' || !judge(xx, yy)) continue;
        if(mp[xx][yy] == 'E')
		{
			sum++;
			return;
		}
        if(mp[xx][yy] == '.')
        {
			if(v[xx][yy]) d = 1;
			else d = 0;
			v[xx][yy] = 1;
            printf("%d	%d\n",xx, yy);
            left(xx,yy, (i + s)% 4);sum++;return;
        }
    }
}
void right(int x, int y)
{
    int xx, yy, i;

    for(i = 0; i < 4; i++)
    {
        xx = x + gox[d][i]; yy = y + goy[d][i];
        if(mp[xx][yy] == '#' || !judge(xx, yy)) continue;
        if(mp[xx][yy] == 'E')
		{
			sum++;
			return;
		}
        if(mp[xx][yy] == '.')
        {
			if(v[xx][yy]) d = 3;
			else d = 2;
			v[xx][yy] = 1;
			//printf("%d	%d	%d	%d\n",xx, yy, i);  system("pause");
            right(xx,yy);sum++;return;
        }
    }
}
int main(void)
{
    int t, st1, st2, i ,j;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for(i = 1; i <= m ; i++)
        {
			scanf("%s", mp[i] + 1);
		}
		for(i = 1; i <= m ; i++)
            for(j = 1; j <= n ; j++)
                if(mp[i][j] == 'S') {   st1 = i; st2 = j;}
        memset(v,0,sizeof(v));
   		sum = 1; d = 0;
        left(st1, st2, 0); printf("%d ,", sum);
        sum = 1; d = 2;
        memset(v, 0, sizeof(v));
        right(st1,st2);  printf("%d \n", sum);

    }
    system("pause");
    return 0;
}
