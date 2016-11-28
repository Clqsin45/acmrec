#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;
vector<int>f[111];
int p, n, match[333];
bool v[333];

int dfs(int x)
{
    int i, u;
    for(i = 0; i < f[x].size(); i++)
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
    int t, temp, m, ans;
    cin>>t;
    while(t--)
    {
        memset(f, 0, sizeof(f));
        memset(match, -1, sizeof(match));
        cin>>p>>n;
        for(int i = 1; i <= p; i++)
        {
            cin>>m;
            while(m--)
            {
                scanf("%d", &temp);
                f[i].push_back(temp);
            }
        }
        ans = 0;
        for(int i = 1; i <= p; i++)
        {
            memset(v, false, sizeof(v));
            ans += dfs(i);
        }
        if(ans == p)    cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
