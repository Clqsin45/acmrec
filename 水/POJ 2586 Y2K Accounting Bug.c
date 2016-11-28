#include <stdio.h>

int main(void)
{
    int s, d, ans;
    while(scanf("%d%d", &s, &d)!= EOF)
    {
        if(d > 4 * s)   ans = s * 10 - d * 2;
        else if(2 * d > 3 * s)  ans =  8 * s - d * 4;
        else if(3 * d > 2 * s)  ans =  s * 6 - d * 6;
        else if(4 * d > s)  ans = s * 3 - d * 9;
        else ans = -1;
        if(ans < 0) printf("Deficit\n");
        else printf("%d\n", ans);
    }
    return 0;
}
