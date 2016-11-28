#include <stdio.h>
#include <string.h>

int a[50], b[50], ans[5000], l1, l2, l, i, j;
char s1[50], s2[50];
int main(void)
{
    scanf("%s%s", s1, s2);
    l1 = strlen(s1);    l2 = strlen(s2);
    strrev(s1); strrev(s2);
    for(i = 0; i < l1; i++)
        a[i] = s1[i] - '0';
    memset(ans, 0, sizeof(ans));
    for(i = 0; i < l2; i++) b[i] = s2[i] - '0';
    for(i = 0; i < l1; i++)
    {
        for(j = 0 ; j < l2; j++)
        {
            ans[i + j] += a[i] * b[j];
        }
    }
    l = l1 + l2;
    for(i = 0 ; i < l ; i++)
    {
        ans[i + 1] += ans[i]/10;
        ans[i] %= 10;
    }
    while(ans[l]== 0 && l > 0)
    {
        l--;
    }
    i = ans[l];
    while(i)
    {
        ans[l] = i % 10;
        i /= 10;
        l++;
    }
    for(i = l - 1; i >= 0; i--)
    {
        printf("%d",ans[i]);

    }
    printf("\n");
    return 0;
}
