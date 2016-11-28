#include <stdio.h>
#include <string.h>
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MAX 140000
int f[MAX << 2], cl[MAX << 2], hash[MAX + 2];

void judge(int rt)
{
    if(f[rt] == !-1) f[rt] ^= 1;
    else cl[rt] ^= 1;
}

void pushdown(int rt)
{
    if(f[rt] != -1)
    {
        f[rt << 1] = f[rt << 1 | 1] = f[rt];
        cl[rt << 1] = cl[rt << 1 | 1] = 0;
        f[rt] = -1;
    }
    if(cl[rt])
    {
        judge(rt << 1); judge(rt << 1| 1);
        cl[rt] = 0;
    }
}

void modify(char op, int L, int R, int l, int r, int rt)
{
    if(L <= l && R >= r)
    {
        if(op == 'U')
        {
            f[rt] = 1;  cl[rt] = 0;
        }
        else if(op == 'D')
        {
            f[rt] = cl[rt] = 0;
        }
        else if(op == 'S' || op == 'C')
        {
            judge(rt);
        }
        return;
    }
    pushdown(rt);
    int m = (l +  r) >> 1;
    if(L <= m) modify(op, L, R, lson);
    else if(op == 'I' || op == 'C')
    {
        f[rt << 1]  = 0;  cl[rt << 1] = 0;
    }
    if(R > m) modify(op, L, R, rson);
    else if(op == 'I' || op == 'C')
    {
        f[rt << 1| 1] = 0;  cl[rt << 1 | 1] = 0;
    }
}

void require(int l, int r, int rt)
{
    if(f[rt] == 1)
    {
        for( int i = l; i <= r; i++)
            hash[i] = 1;
        return;
    }
    else if(f[rt] == 0) return;
    pushdown(rt);
    int m = (l + r) >> 1;
    require(lson);
    require(rson);
}
int main(void)
{
    cl[1] = f[1] = 0;
    char op, c1, c2, st;
    int i, st1, st2;
   // memset(hash, 1, sizeof(hash));
    while(scanf("%c %c%d,%d%c\n", &op,&c1, &st1, &st2, &c2)!=EOF)
    {
        st1 <<= 1;  st2 <<= 1;
        if(c1 == '(')  st1++;
        if(c2 == ')')  st2--;
        if(st1 > st2)   {cl[1] = f[1] = 0;}
        else
        {
            modify(op, st1, st2, 0, MAX, 1);
        }

    }
    require(0, MAX , 1);
   // for(i = 1; i <= 10; i++)    printf("%d\n", hash[i]);
    int flag = 0, e, s = -1;
    for(i = 0; i <= MAX; i++)
    {
        if(hash[i])
        {
            if(s == -1) s = i;
            e = i;
        }
        else
        {
            if(s != -1)
            {
                if(flag) printf(" ");
                flag = 1;
                printf("%c%d,%d%c", s & 1 ? '(' :'[', s >> 1, (e + 1) >> 1, e & 1? ')' : ']');
                s = -1;
            }
        }
    }
    if(!flag)   printf("empty set");
    puts("");
    return 0;

}
