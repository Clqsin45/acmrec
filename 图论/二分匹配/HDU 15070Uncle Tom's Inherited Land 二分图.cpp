#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 55;
int f[MAX][MAX],map[MAX*2][MAX*2], match[MAX], num[MAX*2][MAX*2],
        gox[5] = {0,1, 0, -1}, goy[5] = {1, 0, -1,0}, no, m, n;
bool v[MAX];
struct point
{
    int x, y;
}p[MAX];

int inmap(int x, int y)
{
    return (x >= 1 && y >= 1 && x <= m && y <= n);
}

int dfs(int x)
{
    int i;
    for(i = 1; i <= no; i++)
    {
        if((p[i].x + p[i].y) % 2 == 1) continue;
        if(!v[i] && f[x][i])
        {
            v[i] = 1;
            if(match[i] == -1 || dfs(match[i]))
            {
                match[i] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main(void)
{
    int i, j, st1, st2, x, y, k, ans;
    while(cin>>m>>n && (m || n))
    {
        cin>>k;     no = 0;
        memset(f, 0, sizeof(f));
        memset(match, -1, sizeof(match));
        memset(map, 0, sizeof(map));
        for(i = 1; i <= k; i++)
        {
            cin>>st1>>st2;
            map[st1][st2] = 1;
        }
        for(i = 1; i <= m; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(map[i][j] )   continue;
                num[i][j] = ++no;
                p[no].x = i;    p[no].y = j;
            }
        }
        for(i = 1; i <= m; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(map[i][j])   continue;
                for(k = 0 ; k < 4; k++)
                {
                    x = i + gox[k]; y = j + goy[k];
                    if(!map[x][y] && inmap(x,y))
                    {
                        f[ num[i][j] ][ num[x][y] ] = 1;
                        f[ num[x][y] ][ num[i][j] ] = 1;
                    }
                }
            }
        }
        ans = 0;
        for(i = 1; i <= no; i++)
        {
            if( (p[i].x + p[i].y) % 2 == 0) continue;
            memset(v, 0, sizeof(v));
            ans += dfs(i);
        }
        cout<<ans<<endl;
        for(i = 1; i <= no; i++)
        {
            if(match[i] == -1)   continue;
            printf("(%d,%d)--(%d,%d)\n",p[i].x,p[i].y,p[match[i]].x, p[match[i]].y);
        }
        cout<<endl;
    }

    return 0;
}
