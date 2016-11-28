#include <stdio.h>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define MAX 55555
int mnum[MAX << 2], rnum[MAX << 2], lnum[MAX << 2], cl[MAX << 2];

int max(int x, int y)
{
    return x > y ? x : y;
}

void pushdown(int rt, int m)
{
    if(cl[rt] != -1)
    {
        cl[rt << 1] = cl[rt << 1 | 1] = cl[rt];
        mnum[rt<<1] = lnum[rt<<1] = rnum[rt<<1] = cl[rt] ? 0 : m - (m >> 1);
		mnum[rt<<1|1] = lnum[rt<<1|1] = rnum[rt<<1|1] = cl[rt] ? 0 : (m >> 1);
        cl[rt] = -1;
    }
}

void pushup(int rt, int m)
{
    lnum[rt] = lnum[rt<<1];
	rnum[rt] = rnum[rt<<1|1];
    if (lnum[rt] == m - (m >> 1)) lnum[rt] += lnum[rt<<1|1];
	if (rnum[rt] == (m >> 1))     rnum[rt] += rnum[rt<<1];
    mnum[rt] = max(lnum[rt<<1|1] + rnum[rt<<1], max(mnum[rt<<1] , mnum[rt<<1|1]));
   // printf("%d  %d\n", rt, mnum[rt]);
}

void build(int l, int r, int rt)
{
    mnum[rt] = lnum[rt] = rnum[rt] = r - l + 1;
    cl[rt] = -1;
    if(l == r)  return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    return;
}

void modify(int L, int R, int c, int l, int r, int rt)
{
    if(L <= l && r <= R)
    {
        mnum[rt] = lnum[rt] = rnum[rt] = (c ? 0 : r - l + 1);
        cl[rt] = c;
        return;
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
	if (L <= m) modify(L , R , c , lson);
	if (m < R) modify(L , R , c , rson);
    pushup(rt, r - l + 1);
}
int require(int w, int l, int r, int rt)
{
    if(l == r)  return l;
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if(mnum[rt << 1] >= w)  return require(w, lson);
    else if(rnum[rt<<1] + lnum[rt<<1|1] >= w) return m - rnum[rt<<1] + 1;
    return require(w, rson);
}
int main(void)
{
    int n, m, i, op, st1, st2, p;
    scanf("%d%d", &n, &m);
    build(1, n, 1);
    for(i = 1; i <= m; i++)
    {
        scanf("%d", &op);
        if(op == 1)
        {
            scanf("%d", &st1);
            if(mnum[1] < st1)   printf("0\n");
            else
            {
                p = require(st1, 1, n, 1);
                printf("%d\n", p);
                modify(p, p + st1 - 1, 1, 1, n, 1);
            }
        }
        else
        {
            scanf("%d%d", &st1, &st2);
            modify(st1, st2 + st1 - 1, 0, 1, n, 1);
        }
    }
    return 0;
}
