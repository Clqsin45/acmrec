#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MAX 1000000
#define SIDE 5005
int f[MAX] = {0}, rd[SIDE];
int a[200];

void init(void)
{
    int i, ct = 2, j;
    for(i = 'a'; i <= 'z';)
    {
        if(ct == 7 || ct == 9)
        {
            for(j = 1; j <= 4; j++, i++)
                a[i] = ct;
            ct++;
        }
        else
        {
            for(j = 1; j <= 3; j++, i++)
                a[i] = ct;
            ct++;
        }
    }
    return;
}

int main(void)
{
    int T, m, n, temp, lt, bas, tp;
    char ch[10];
    init();
    cin>>T;
    while(T-- )
    {
        cin>>n>>m;
        memset(f, 0, sizeof(f));
        tp = 0;
        while(n--)
        {
            scanf("%d", &temp);
            rd[++tp] = temp;
        }
        while(m--)
        {
            scanf("%s", ch);
            lt = strlen(ch);
            temp = 0;
            for(n = lt - 1, bas = 1; n >= 0; n--, bas *= 10)   temp += a[ch[n]] * bas;
            f[temp] ++;
        }
        for(n = 1; n <= tp; n++)
            printf("%d\n", f[rd[n]]);
    }

    return 0;
}
