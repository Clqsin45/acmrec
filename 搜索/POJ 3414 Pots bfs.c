#include <stdio.h>

int q[1000004][4], ff[10110] = {0},rd[10110][3] = {{0}}, out[1002];
int add(int x, int y)
{
    int t =q[x][1] * 100 + q[x][2] , p = q[y][1] * 100 + q[y][2];
    ff[t] = ff[p] + 1;      rd[t][2] = p;
    return t;
}
int main(void)
{
    int a, b, n, f, r, sign = 0, x, i;
    scanf("%d%d%d", &a, &b ,&n);
    q[1][1] = q[1][2] = 0;  f = r = 1;
    ff[0] = 0;  rd[0][2] = 0;

    while(f <= r)
    {
        if(q[f][1] == n || q[f][2] == n)
        {   sign = 1;  break; }

        if(q[f][1] < a && !rd[a * 100 + q[f][2]][1])
        {
            q[++r][1] = a;  q[r][2] = q[f][2];
            x = add(r, f);  rd[x][1] = 1;
        }
        if(q[f][2] < b && !rd[q[f][1] * 100 + b][1])
        {
            q[++r][2] = b;  q[r][1] = q[f][1];
            x = add(r, f);  rd[x][1] = 2;
        }
        if(q[f][1] > 0 && q[f][2] && !rd[q[f][2]][1])
        {
            q[++r][1] = 0;  q[r][2] = q[f][2];
            x = add(r, f);  rd[x][1] = 3;
        }
        if(q[f][2] > 0 && q[f][1] && !rd[q[f][1] * 100][1])
        {
            q[++r][2] = 0;  q[r][1] = q[f][1];
            x = add(r, f);  rd[x][1] = 4;
        }
        if(q[f][1] && q[f][2] != b)
        {
            x = q[f][2] + q[f][1];
            if(x <= b && !rd[x][1])
            {
                q[++r][2] = x;       q[r][1] = 0;
                x = add(r, f);  rd[x][1] = 5;
            }
            else if (x > b && !rd[b + (x - b) * 100][1])
            {
                q[++r][2] = b;  q[r][1] = x - b;
                x = add(r, f);  rd[x][1] = 5;
            }

        }
        if(q[f][2] && q[f][1] != a)
        {
            x = q[f][2] + q[f][1];
            if( x <= a && !rd[x * 100][1])
            {
                q[++r][1] = x;        q[r][2] = 0;
                x = add(r, f);  rd[x][1] = 6;
            }
            else if (x > a && !rd[a * 100 + x - a][1])
            {
                q[++r][1] = a;  q[r][2] = x - a;
                x = add(r, f);  rd[x][1] = 6;

            }
        }
        f++;

    }
    if(sign)
    {
        printf("%d\n",ff[x = q[f][1] * 100 + q[f][2]]);
        f = 0;
        while(x)
        {
            out[++f] = rd[x][1];    x = rd[x][2];
        }
        for(i = f; i >= 1; i--)
        {
            switch (out[i])
            {
                case 1:     printf("FILL(1)\n");    break;
                case 2:     printf("FILL(2)\n");    break;
                case 3:     printf("DROP(1)\n");    break;
                case 4:     printf("DROP(2)\n");    break;
                case 5:     printf("POUR(1,2)\n");  break;
                case 6:     printf("POUR(2,1)\n");  break;
            }
        }
    }
    else printf("impossible\n");
    system("pause");
    return 0;
}
