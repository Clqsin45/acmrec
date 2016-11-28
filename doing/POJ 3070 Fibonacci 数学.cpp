#include <stdio.h>
#define mod 10000
struct matrix
{
    int v[4][4];
}m;

matrix mtmul(matrix a, matrix b)
{
    matrix c;
    c.v[0][0] = (a.v[0][0]*b.v[0][0] + a.v[0][1]*b.v[1][0]) % mod;
    c.v[0][1] = (a.v[0][0]*b.v[0][1] + a.v[0][1]*b.v[1][1]) % mod;
    c.v[1][0] = (a.v[1][0]*b.v[0][0] + a.v[1][1]*b.v[1][0]) % mod;
    c.v[1][1] = (a.v[1][0]*b.v[0][1] + a.v[1][1]*b.v[1][1]) % mod;
    return c;
}

matrix mtpow(matrix a, int k)
{
    if(k == 1)  return a;
    a = mtpow(a, k / 2);
    if(!(k & 1))
        return mtmul(a, a);
    else return mtmul(mtmul(a, a), m);
}
int main(void)
{
    int n;
    m.v[0][0] = 0;    m.v[1][0] = 1;
    m.v[0][1] = 1;    m.v[1][1] = 1;
    while(scanf("%d", &n) && n != -1)
    {
        if(n == 0)
        {
            printf("0\n");
            continue;
        }
        matrix a = mtpow(m , n);
        printf("%d\n", a.v[0][1]);
    }
    return 0;
}
