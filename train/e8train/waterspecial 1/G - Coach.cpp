#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 50
#define INF 0x7f7f7f7
int f[50], c[MAX] = {0}, v[MAX] = {0};

int find(int x)
{
    if(x == f[x])   return x;
    return f[x] = find(f[x]);
}

void merge(int x, int y)
{
    x = find(x);   y = find(y);
    f[y] = x;
}
int main(void)
{
    int n, m, flag = 0, i, j, st1, st2, t;
    cin>>n>>m;
    for(i = 1; i <= n; i++) f[i] = i;
    while(m--)
    {
        cin>>st1>>st2;
        if(st1 < st2)   merge(st1, st2);
        else merge(st2, st1);
    }

    for(i = 1; i <= n ;i++)     c[find(i)] ++;
    st1 = 0;    st2= 0;
    flag = 1;

    for(i = 1; i <= n; i++)
    {
        if(c[i] > 3)
        {
            flag = 0;   break;
        }
        if(c[i] == 1)   st2++;
        else if(c[i] == 2)  st1++;
    }

    if(st1 > st2 || !flag)
    {
        cout<<-1<<endl;
        return 0;
    }

    for(i =1; i <= n; i++)
    {
        if(c[i] == 3)
        {
            for(j = 1, t = 1; j <= n; j++)
            {
                if(f[j] != i)   continue;
                v[j] = 1;
                printf("%d%c", j, t % 3 == 0 ? '\n': ' ');
                t++;
            }
        }
        else if(c[i] == 2)
        {
            for(j = 1; j <= n; j++)
            {
                if(f[j] != i)   continue;
                v[j] = 1;
                printf("%d ", j);
            }
            for(j = 1; j <= n; j++)
            {
                if(v[j] || c[j] != 1)   continue;
                v[j] = 1;
                printf("%d\n", j);
                break;
            }
        }
    }
    for(i = 1, t = 1; i <= n; i++)
    {
        if(v[i])    continue;
        printf("%d%c", i, t % 3 == 0 ? '\n': ' ');
        t++;
    }
    return 0;
}
