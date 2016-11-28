#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int MAX = 1444;

vector<int>f[MAX];
int map[35][35], match[MAX], num[35][35], no, m, n;
int gox[4] = {0, 1, 0, -1}, goy[4] = {1, 0, -1, 0};
bool v[MAX];
struct point
{
    int x, y;
}p[MAX];
bool inmap(int x, int y)
{
    if(x >= 1 && y >= 1 && x <= m && y <= n)
        return 1;
    else return 0;
}

int dfs(int x)
{
    int i, u;
    for(i = 0; i < f[x].size(); i++)
    {
        u = f[x][i];
        if(!v[u])
        {
            v[u] = true;
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
    int k, i, j, x, y, ans, t;
    cin>>m>>n>>k;
    no = 0;
    t = k;
    memset(map, 0, sizeof(map));

    for(i = 1; i <= 1024; i++)    f[i].clear();
    while(k--)
    {
        scanf("%d%d", &x, &y);
        map[y][x] = 1;
    }
    if((m * n - t) % 2)
    {
        printf("NO\n");
        return 0;
    }
    memset(match, -1, sizeof(match));
    memset(num , 0, sizeof(num));
    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(map[i][j])   continue;
            num[i][j] = ++no;
            p[no].x = i;    p[no].y = j;
        }
    }

    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(map[i][j])   continue;
            for(k = 0; k < 4; k++)
            {
                x = i + gox[k]; y = j + goy[k];
                if(!map[x][y] && inmap(x, y))
                {
                    f[num[i][j]].push_back(num[x][y]);
                }
            }
        }
    }

    ans = 0;
    for(i = 1; i <= no; i++)
    {
        if( (p[i].x + p[i].y ) % 2 == 0)    continue;
        memset(v, 0 ,sizeof(v));
        ans += dfs(i);
    }

    if(ans * 2 == no)   cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
