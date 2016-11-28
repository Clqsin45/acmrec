#include <stdio.h>
#include <math.h>
struct point
{
    double x;  double y;
}p[1002];
int f[1002], rank[1002], n, v[1002];
double d;
int judge(int a, int b)
{
    if(sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y)) <= d) return 1;
    else return 0;

}
int find(int x)
{
    if(x == f[x]) return x;
    else return f[x] = find(f[x]);
}

int main(void)
{
    int i, x, y, t;
    char op;
    scanf("%d%lf", &n, &d);
    for(i = 1; i <= n; i++)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);
        f[i] = i;  rank[i] = 0;   v[i] = 0;
    }

    scanf("\n");
    while(scanf("%c",&op) != EOF)
    {
        if(op == 'O')
        {
            scanf("%d", &x);
            v[x] = 1;
            for(i = 1; i <= n; i++)
            {
                if(v[i] && judge(x, i))
                {
                    f[find(x)] = find(i);
                }
            }
        }
        else if(op == 'S')
        {
            scanf("%d%d", &x, &y);
            if(find(x) != find(y))  printf("FAIL\n");
            else printf("SUCCESS\n");
        }
    }

    return 0;
}
