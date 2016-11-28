#include <stdio.h>
int judge(int a, int b, int c)
{
    if(a*a + b*b == c * c || a*a + c*c == b*b || c*c + b*b == a*a)  return 1;
    else return 0;
}
int main(void)
{
    int t, a, b ,c, n = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &a, &b, &c);
        if(judge(a,b,c))   printf("Scenario #%d:\nyes\n\n",n);
        else  printf("Scenario #%d:\nno\n\n",n);
        n++;
    }
    return 0;
}
