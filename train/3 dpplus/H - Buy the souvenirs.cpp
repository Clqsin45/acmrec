#include <stdio.h>
#include <string.h>
#define MAX 505
int w[MAX];
struct point
{
    int way, num;
}p[MAX];
int main(void)
{
    int TC, n, m, i, j, temp, ans;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d%d", &n, &m);
        memset(p, 0, sizeof(p));
        p[0].way = 1;
        for(i = 1; i <= n; i++)
            scanf("%d", &w[i]);
        for(i = 1; i <= n; i++)
        {
            for(j = m; j >= w[i]; j--)
            {
                if(p[j - w[i]].num >= p[j].num)
                {
                    p[j].num = p[j - w[i]].num + 1;
                    p[j].way = p[j - w[i]].way;
                }
                else if(p[j - w[i]].num + 1 == p[j].num)
                {
                    p[j].way += p[j - w[i]].way;
                }
            }
        }
        ans = p[m].way;
        i = m;
        while(p[i].num == p[i - 1].num)
        {
            ans += p[--i].way;
        }
        if(p[m].num)
            printf("You have %d selection(s) to buy with %d kind(s) of souvenirs.\n",ans,p[m].num);
        else printf("Sorry, you can't buy anything.\n");

    }

    return 0;
}

