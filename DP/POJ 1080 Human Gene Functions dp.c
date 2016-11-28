#include <stdio.h>
#include <string.h>
int map[160];
int d[6][6] = {{5, -1, -2, -1, -3},
               {-1, 5, -3, -2, -4},
               {-2, -3, 5, -2, -2},
               {-1, -2, -2, 5, -1},
               {-3,-4,-2, -1,0}};
int f[102][102];

int max(int x, int y)
{
    return x > y ? x : y;
}
int main(void)
{
    map['A'] = 0;   map['C'] = 1;   map['G'] = 2;   map['T'] = 3;   map['-'] = 4;
    int t, l1, l2, i, j;
    char s1[102], s2[102];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%s%d%s", &l1, s1, &l2, s2);
        f[0][0]=0;
        for(i = 1; i <= l1; i++)    f[0][i] = f[0][i-1] + d[map[s1[i-1]]][4];
        for(i = 1; i <= l2; i++)    f[i][0] = f[i-1][0] + d[4][map[s2[i-2]]];
        for(i = 1; i <= l2; i++)
        {
            for(j = 1; j <= l1; j++)
            {
                f[i][j] = max(f[i-1][j-1] + d[map[s2[i-1]]][map[s1[j-1]]]
                              , max(f[i - 1][j] + d[map[s2[i-1]]][4], f[i][j-1]+d[map[s1[j-1]]][4]));
            }
        }
        printf("%d\n",f[l2][l1]);
    }
    return 0;
}
