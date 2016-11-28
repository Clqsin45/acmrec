#include <stdio.h>
#include <string.h>
struct point
{
    int x;  int step;   int i;
}p[100002];

int v[100002] = {0};
void bfs(point a, int i, point& b)
{
    int x = i / 4,  y = i % 4;
    b.x = t.x;
    b.x = b.x ^ (0x1 << i);

    if(x > 0)
        b.x = b.x ^ (0x1 << (i - 4));
    if(x < 3)
        b.x = b.x ^ (0x1 << (i + 4));
    if(y > 0)
        b.x = b.x ^ (0x1 << (i - 1));
    if(y < 3)
        b.x = b.x ^ (0x1 << (i + 1));

    b.step = t.step + 1;
    b.i = i;
    return;
}
int main(void)
{
    char op[10];
    int i, j, f = 0, r = 0, sign = 1;
    p[0].x = 0;
    p[0].step = -1;
    p[0].i = 0;

    for(i = 0; i < 4; i++)
    {
        scanf("%s", op);
        for(j = 0; j < 4; j++)
        {
            if(op[j] == 'b')
            {
                p[0].x = ((0x1 << (i * 4 + j))| p[0].x);
            }
        }
    }
    while(p[r].x !=0 && p[r].x != 0xFFFF)
    {
        for(i = 0; i < 16; i++)
        {
            if(p[f].i == i)    continue;
            r ++;
            bfs(p[f], i, p[r]);
            if(v[p[r].x])   r--;
            else v[p[r].x] = 1;
            if(p[r].x == 0 || p[r].x == 0xFFFF) break;
        }
        if(f == r)
        {
            sign = 0;
            break;
        }
        f++;
    }
    if(sign) printf("%d\n", p[r].step);
    else printf("Impossible\n");
    return 0;
}
