#include <iostream>
#include <cstdio>
using namespace std;
const int MAX  = 30;
int f[MAX][MAX], match[MAX], chan[200], chat[200] , n;
bool v[MAX];
char x[MAX][4], y[MAX][4];

 void set(void)
 {
     int i;
     chan['A'] = 14;    chan['T'] = 10;  chan['J'] = 11;
     chan['Q'] = 12;   chan['K'] = 13;
     for(i = '2'; i <= '9'; i++)    chan[i] = i - '1' + 1;
     chat['H'] = 4; chat['S'] = 3;  chat['D'] = 2; chat['C'] = 1;
 }

 int dfs(int x)
 {
     int i;
     for(i = 1; i <= n; i++)
     {
         if(!v[i] && f[x][i])
         {
             v[i] = 1;
             if(match[i] == -1 || dfs(match[i]) )
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
    int t, i,j, ans;
    cin>>t;
    set();
    while(t--)
    {
        cin>>n;
        memset(f, 0, sizeof(f));
        memset(match, -1, sizeof(match));
        for(i = 1; i <= n; i++) scanf("%s", x[i]);
        for(i = 1; i <= n; i++) scanf("%s", y[i]);
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(chan[ y[i][0] ] > chan[ x[j][0] ])   f[i][j] = 1;
                else if(y[i][0] == x[j][0] && chat[ y[i][1] ] > chat[ x[j][1] ])
                    f[i][j] = 1;
            }
        }
        ans = 0;
        for(i = 1; i <= n; i++)
        {
            memset(v, false, sizeof(v));
            ans += dfs(i);
        }
        printf("%d\n", ans);
    }

}
