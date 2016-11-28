#include <stdio.h>
#include <map>
using namespace std;
int main(void)
{
    int n, i, st, t = 0, x;
    map<int , int>p;
    while(scanf("%d", &n) != EOF)
    {
        p.clear();
        x = (n + 1) / 2;
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &t);
            p[t] ++;
            if(p[t] >= x)    st = t;
        }
        printf("%d\n", st);
    }
    return 0;
}
