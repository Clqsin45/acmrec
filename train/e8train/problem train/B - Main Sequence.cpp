#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

#define MAX 1000006
#define INF 0x3f7f7f7f
int f[MAX], q[MAX] = {0};
stack<int>s;

int main(void)
{
    int n, i, j, t, flag = 1,x, y, k;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &f[i]);
    if(n & 1)   flag = 0;
    scanf("%d", &t);
    for(i = 1; i <= t; i++)
    {
        scanf("%d", &j);
        f[j] = -f[j];
        q[j] = f[j];
        if(flag == 0)   continue;
        s.push(j);
        for(k = j - 1; k >= 1; k -= 1)
        {
            if(f[k] == 0)   continue;
            x = s.top();
            if(f[k] > 0 && f[x] + f[k] == 0)
            {
                s.pop();
                q[k] = f[k];    q[x] = f[x];
                f[k] = f[x] = 0;
                break;
            }
            else if(f[k] > 0 && f[x] == f[k])
            {
                q[k] = f[k];    f[x] = -f[x];
                s.pop();
            }
            else
                s.push(k);
        }
        if(!s.empty())  flag = 0;
    }
    if(flag == 0)
    {
        printf("NO\n"); return 0;
    }
    for(i = 1; i <= n; i++)
    {
        if(f[i] == 0)   continue;
        if(s.empty())
        {
            s.push(i);
            continue;
        }
        else
        {
            j = s.top();

            if(f[i] == f[j])
            {
                q[i] = -f[j];
                q[j] = f[i];
                s.pop();
            }
            else
            {
                s.push(i);
            }
        }
    }
    if(s.empty())
    {
        printf("YES\n");
        for(i = 1; i <= n; i++)
            printf("%d%c", q[i], i == n ? '\n':' ');
    }
    else printf("NO\n");
    return 0;
}
