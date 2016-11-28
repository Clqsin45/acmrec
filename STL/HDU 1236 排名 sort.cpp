#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct STU
{
    char name[22];  int sr;
}s[1002];
int t[12];
bool cp(STU a, STU b)
{
    if(a.sr > b. sr)    return 1;
    else if(a.sr == b.sr && strcmp(a.name, b.name) < 0) return 1;
    return 0;
}
int main(void)
{
    int n, m, g, i, j, st, ct, ot;
    while(scanf("%d", &n) && n)
    {
        scanf("%d%d", &m, &g);
        ct = 0;
        for(i = 1; i <= m; i++) scanf("%d", &t[i]);
        for(i = 0; i < n; i++)
        {
            scanf("%s%d", s[i].name, &ot);
            s[i].sr = 0;
            for(j = 1; j <= ot; j++)
            {
                scanf("%d", &st);
                s[i].sr += t[st];
            }
            if(s[i].sr >= g)    ct++;
        }
        sort(s, s+n,cp);
        if(ct == 0)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n",ct);
        for(i = 0; i < ct; i++)   printf("%s %d\n",s[i].name, s[i].sr);
    }
    return 0;
}
