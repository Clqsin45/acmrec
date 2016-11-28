#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 60
#define MAX3 216000
#define INF 0x7f7f7f7f
int n, m, fl, stx, sty, stz, edx, edy, edz, no = 0;
int mark[MAX][MAX][MAX] , heap[MAX3];

struct point
{
    int px, py, pz, gx, hx, ft, pos;
}p[MAX3];

int ov[MAX3] = {0}, cv[MAX3] = {0}, gox[6] = {0, 1, 0, -1, 0, 0}, goy[6] = {1, 0, -1, 0, 0, 0}, goz[6] = {0, 0, 0, 0, 1, -1};

inline int judge(int x, int y, int z)
{
    if(!mark[x][y][z])    return 0;
    else return 1;
}

void heapify(int i)
{
    int min = i, left = i * 2, right = i * 2 + 1, temp;
    if(left <= no && p[heap[left]].gx + p[heap[left]].hx < p[heap[min]].gx + p[heap[min]].hx)
        min = left;
    if(right <= no && p[heap[right]].gx + p[heap[right]].hx < p[heap[min]].gx + p[heap[min]].hx)
        min = right;

    if(min != i)
    {
        temp = heap[i];     heap[i] = heap[min];   heap[min] = temp;
        p[heap[i]].pos = i; p[heap[min]].pos = min;
        if(min * 2 <= no)   heapify(min);
    }
}

void insert(int x)
{
    int i, temp;
    heap[++no] = x; p[x].pos = no;
    i = no;

    while(i > 1 && (p[heap[i]].gx + p[heap[i]].hx) < (p[heap[i / 2]].gx + p[heap[i / 2]].hx))
    {
        temp = heap[i];     heap[i] = heap[i /2];   heap[i / 2] = temp;
        p[heap[i]].pos = i; p[heap[i / 2]].pos = i / 2;
        i /= 2;
    }
    return;
}

int outtop(void)
{
    int top = heap[1];
    heap[1] = heap[no--];
    heapify(1);
    return top;
}

void del(int i)
{
    heap[i] = heap[no--];
    heapify(i);
}
int abfs(void)
{
    int x = stx, y = sty, z = stz, xx, yy, zz, i, now, rel;
    int st[6], j = 0;
    no = 0;
    now = mark[x][y][z];   ov[now] = 1;   insert(now);
    p[now].gx = 0;  p[now].hx = abs(x - edx) + abs(y - edy) + abs(z - edz);
    while(no)
    {
        now = outtop(); j = 0;
        x = p[now].px;  y = p[now].py;  z = p[now].pz;
        for(i = 0; i < 6; i++)
        {
            xx = x + gox[i];    yy = y + goy[i];    zz = z + goz[i];

            if(!judge(xx, yy, zz))
            {
                //printf("%d\n", now);
                continue;
            }
            rel = mark[xx][yy][zz];
            if(ov[rel])
            {
                if(p[now].gx + 1 < p[rel].gx)
                {
                    del(p[rel].pos);
                    p[rel].gx = p[now].gx + 1;
                    insert(rel);
                    //p[rel].hx = abs(xx - edx) + abs(yy - edy) + abs(zz - edz);
                    p[rel].ft = now;
                }
            }
            if(cv[rel])
            {
                if(p[now].gx + 1 < p[rel].gx)
                {
                    del(p[rel].pos);
                    p[rel].gx = p[now].gx + 1;
                    //p[rel].hx = abs(xx - edx) + abs(yy - edy) + abs(zz - edz);
                    p[rel].ft = now;
                    ov[rel] = 1;
                    insert(rel);
                    cv[rel] = 0;
                    //st[j++] = rel;
                }
            }
            if(!cv[rel] && !ov[rel])
            {
                p[rel].gx = p[now].gx + 1;
                p[rel].ft = now;
                p[rel].hx = abs(xx - edx) + abs(yy - edy) + abs(zz - edz);
                insert(rel);
                ov[rel] = 1;
            }
        }
        cv[now] = 1;
        if(cv[mark[edx][edy][edz]])  return p[mark[edx][edy][edz]].gx;

    }
    return -1;
}

int main(void)
{

    //freopen("in.txt", "r", stdin);
    char ch, op[MAX];
    int ans, i, j, k;
    while(scanf("%d%d%d",&fl, &n, &m) != EOF && (fl || m || n))
    {
        getchar();
        memset(mark, 0, sizeof(mark));
        memset(ov, 0, sizeof(ov));
        memset(cv, 0, sizeof(cv));
        no = 0;
        for(k = 1; k <= fl; k++)
        {
            for(i = 1; i <= n; i++)
            {
                scanf("%s", op + 1);
                for(j = 1; j <= m; j++)
                {
                    ch = op[j];
                    if(ch == '#')       continue;
                    mark[i][j][k] = ++no;
                    p[no].px = i;   p[no].py = j;   p[no].pz = k;
                    p[no].gx = INF; p[no].hx = INF;
                    p[no].ft = 0;
                    if(ch == 'S')
                    {
                        stx = i;    sty = j;    stz = k;
                    }
                    else if(ch == 'E')
                    {
                        edx = i;    edy = j;    edz = k;
                    }
                }
            }
        }

        if( (ans = abfs()) == -1)    printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", ans);

    }
    return 0;
}
