#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 404
#define M 160004
#define LL __int64
#define INF 0x3f7f7f7f

int l[N], r[N], no;
bool vis[N], f[N][N];

int main(void)
{
    int i, j, x, y, n, s, t, cnt, m;
    char ch;
    bool loop, first, find;
    while(scanf("%d%d", &n, &m) &&(n || m))
    {
        memset(vis, 0, sizeof(vis));
        memset(f, 0, sizeof(f));
        no = 0;

        while(m--){
            scanf("%d%d", &x, &y);
            f[x][y] = f[y][x] = true;
        }
         n <<= 1;

        s = 1;
        for(t = 2; t <= n; t++){
            if(f[1][t]) continue;
            break;
        }

        vis[s] = vis[t] =true;
        l[t] = s;   r[s] = t;
        cnt = 2;
        loop = false;   first = true;
        //printf("s:%d t:%d\n", s, t);
      //  printf("%d\n", r[s]);
        while(true){

            if(!first){
                for(i = 1; i <= n; i++){
                    if(vis[i])  continue;

                    for(j = 1; j <= n; j++){
                        if(i != j && vis[j] && !f[i][j] && j != s && j != t){
                            y = j;  find = true;    break;
                        }
                    }
                    if(find)    break;
                }
                s = y;  t = l[y];
            }

            first = false;

            while(cnt < n){

                for(i = 1; i <= n; i++){
                    if(vis[i] || f[i][s])  continue;
                    l[s] = i;   r[i] = s;   s = i;  vis[i] = true;
                    cnt++;  break;
                }
                if( i == n + 1)    break;
            }
           // printf("%d\n", cnt);

            while(cnt <n){
               // printf("%d %d\n",t, head[t]);

               for(i = 1; i <= n; i++){
                    if(vis[i] || f[i][t])  continue;
                    r[t] = i;   l[i] = t;   t = i;  vis[i] = true;
                    cnt ++; break;
               }
                if(i == n + 1) break;
            }

            if(!f[s][t]) { //printf("!!!?? %d %d\n", r[s], s);
                l[s] = t;   r[t] = s;
            }

            else {
              //  printf("yayayainhere\n");
                for(i = r[s]; r[i] != t; i = r[i])
                {
                    if(!f[i][t] && !f[r[i]][s])   break;
                }
                l[s] = r[s];    r[s] = r[i];    l[r[i]] = s;
                for(j = l[i]; j != s; j = y){
                    y = l[j];   swap(l[j], r[j]);
                }
                r[t] = i;   r[i] = l[i];    l[i] = t;


            }
            if(cnt == n) break;
        }//printf("!!!%d %d\n", s, t);    system("pause");
      //  printf("s:%d t:%d\n", s, t);
        first = true;
        for(i = s; i != s || first ; i = r[i])
        {
            first = false;  //printf("%d\n", i);  system("pause");
            printf("%d%c", i, r[i] == s ? '\n' : ' ');
        }
       // printf("==========\n");


    }
    return 0;
}
