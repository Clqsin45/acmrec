#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 111;

vector<int>f[MAX];
int match[MAX], n, rx[MAX * 10], ry[MAX * 10];
bool v[MAX];

void swap(int x,int y)
{
    int temp = match[x];    match[x] = match[y];    match[y] = temp;
}

int dfs(int x)
{
    int i, u;
    for(i = 0 ; i < f[x].size(); i++)
    {
        u = f[x][i];
        if(!v[u])
        {
            v[u] = 1;
            if(match[u] == -1 || dfs(match[u]))
            {
                match[u] = x;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int i, j, temp, ans, ct;
    while(cin>>n)
    {
        memset(match, -1, sizeof(match));
        for(i= 1; i <= n; i ++)
        {
            f[i].clear();
            for(j = 1; j <= n; j++)
            {
                scanf("%d", &temp);
                if(temp)    f[i].push_back(j);
            }
        }
        ans = 0;
        for(i = 1; i <= n; i++)
        {
            memset(v, 0, sizeof(v));
            ans += dfs(i);
        }
        if(ans != n)    cout<<"-1"<<endl;
        else
        {
            ct = 0;
            for(i = 1; i <= n; i++)
            {
                temp = i;
                for(j =i; j <= n; j++)
                {
                    if(match[j] < match[temp])
                        temp = j;
                }
                if(temp != i)
                {
                    rx[++ct] = i;
                    ry[ct] = temp;
                    swap(temp, i);
                }
            }
            cout<<ct<<endl;
            for(i = 1; i <= ct; i++)
                printf("C %d %d\n", rx[i], ry[i]);
        }
    }
    return 0;
}
