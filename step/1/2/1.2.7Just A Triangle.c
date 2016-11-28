#include <stdio.h>

int judge(int a, int b, int c)
{
    if(a*a + b*b == c * c || a*a + c*c == b*b || c*c + b*b == a*a)  return 1;
    if(a == b || b == c || c == a)  return 2;
    return 0;
}
int main(void)
{
    int n, a, b, c;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d%d%d", &a, &b, &c);
        switch(judge(a, b, c))
        {
            case 0: printf("just a triangle\n");    break;
            case 1: printf("good\n");   break;
            case 2: printf("perfect\n");    break;
        }
    }
    return 0;
}
