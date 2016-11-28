#include <cstdio>
#include <iostream>
using namespace std;
#define MAX 20002
#define orz unsigned int

struct point
{
    orz a, b, c;
}p[MAX];
int n;

int main(void)
{
    int i, ans;
    orz stu, j;
    while(scanf("%d", &n) != EOF)
    {
        stu = 0;    ans = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%u%u%u", &p[i].a, &p[i].b, &p[i].c);
            for(j = p[i].a; j <= p[i].b; j += p[i].c)
                stu ^=(j);
        }
        if(stu == 0)
        {
            printf("DC Qiang is unhappy.\n");
            continue;
        }
        for(i = 1; i <= n; i++)
        {
            if(stu >= p[i].a && p[i].b >= stu && (stu - p[i].a) % p[i].c == 0)    ans++;
        }
        printf("%u %d\n", stu, ans);
    }
    return 0;
}
