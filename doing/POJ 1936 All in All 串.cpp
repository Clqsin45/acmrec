#include <stdio.h>
#include <string.h>
#define MAX 100050

char a[MAX], b[MAX];
int main(void)
{
    int la, lb, i, j;
    while(scanf("%s%s", a, b) != EOF)
    {
        la = strlen(a);
        lb = strlen(b);
        for(i = j = 0; i < la && j < lb;)
        {
            if(a[i] == b[j])
            {
                i++;    j++;
            }
            else    j++;
        }
        if(i == la) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
