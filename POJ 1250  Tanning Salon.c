#include <stdio.h>
#include <string.h>
char a[100];
int v[200];
int main(void)
{
    int ans, ct, n, i;
    while(scanf("%d", &n) &&  n)
    {
       // scanf("%s", a);
        ans = 0;    ct = 0;
        memset(v, 0, sizeof(v));
        for(i = 0 ; a[i] != '\0'; i++)
        {
            printf("%d  %d\n",ct, n);
            if(ct < n && !v[a[i]])
            {
                ct++;   v[a[i]] = 1;
            }
            else if(v[a[i]] == 1)
                ct--;
            else
            {
                v[a[i]] = 2;
                ans++;
            }
        }
        if(ans) printf("%d customer(s) walked away.\n", ans);
        else printf("All customers tanned successfully.\n");
    }

    return 0;
}
