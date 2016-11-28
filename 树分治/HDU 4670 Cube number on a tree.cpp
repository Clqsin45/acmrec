#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
using namespace std;

#define N 50005
#define M
#define LL __int64
#define INF 0x3f7f7f7f
int  res[N][33], cnt[N], idx, now, no, head[N],  t;
LL pri[33];
bool vis[N];
LL ans = 0;
int record[33], temp[33];
map<LL, int>f;
map<LL, int>g;
set<LL>S;
struct point{
    int v, next;
    point(){};
    point(int x,int y):v(x), next(y){};
}p[N << 1];
int allpri;

void init(){
    memset(res, 0, sizeof(res));
    memset(vis, false, sizeof(vis));
    memset(head, -1, sizeof(head));
    no = 0; ans = 0LL;
}

void add(int x, int y){
    p[no] = point(y, head[x]);  head[x] = no++;
    p[no] = point(x, head[y]);  head[y] = no++;
}

void findcon(int x, int fa){
    int i, y;
    cnt[x] = 1;
    int high = 0;
  //  printf("!!!%d\n", x);   system("pause");

    for(i = head[x]; i != -1 ; i = p[i].next){
        y = p[i].v;
       // printf("~~~%d ->%d\n", x,  y);
        if(vis[y] || y == fa)   continue;
        findcon(y, x);
        cnt[x] += cnt[y];
        high = max(cnt[y], high);
    }
   // printf("%d %d %d\n", x, cnt[x], t);
    high = max(high, t - cnt[x]);
   // printf("%d %d\n", x, high);
    if(high < now){
        now = high;
        idx = x;
    }
}

void predeal(int x, int fa){
    LL state = 0LL;
    int i, y;
//    printf("%d\n", x);

    for(i = 1; i <= allpri; i++){
        record[i] = (record[i] + res[x][i]) % 3;
   //     printf("%d ",record[i]);
        state = state * 3 + record[i];
    }
    if(g[state] == 0)   g[state] = 1;
    else g[state] = g[state] + 1;
    S.insert(state);
    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(vis[y] || y == fa)   continue;
        predeal(y, x);
    }
    for(i = 1; i <= allpri; i++){
        record[i] = (record[i] - res[x][i] + 3) % 3;
    }

}

void dfs(int x, int fa){
    int i, y, j;
    bool zero = true;
    LL state = 0LL, need = 0LL;
    now = INF;
    findcon(x, fa);

  // printf("!!!%d \n", idx);   system("pause");
    vis[idx] = true;
    f.clear();  f[0] = 1;
    for(j = 1; j <= allpri; j++)
        if(res[idx][j]){
            zero = false;
            break;
        }

    if(zero)    ans ++;
    for(i = head[idx]; i != -1; i = p[i].next){
        y = p[i].v;
        if(vis[y] || y == fa)  continue;
        g.clear();
        S.erase(S.begin(), S.end());
        memset(record, 0, sizeof(record));

        predeal(y, x);
   //     printf("!!! %d %d\n",y, idx);    system("pause");
        set<LL>::const_iterator itor;

        for(itor = S.begin(); itor != S.end(); itor++){
            state = *itor;
         //   printf("%d\n", state);
            need = 0LL;
            for(j = allpri; j >= 1; j--){
                temp[j] = (res[idx][j] + state % 3) % 3;
                state /= 3;
            }

            for(j = 1; j <= allpri; j++){
                need = need * 3 + (3 - temp[j]) % 3;
            }
            ans = ans + f[need] * g[state];
        }

        for(itor = S.begin(); itor != S.end(); itor ++){
            state = *itor;
            f[state] += g[state];
        }
    }
    for(i = head[idx]; i != -1; i = p[i].next){
        y = p[i].v;
        if(vis[y] || y == fa)   continue;
        t = cnt[y];     dfs(y, idx);
    }
}
int main(void)
{
    int i, j, n, x, y;
    LL num;
    while(scanf("%d", &n) != EOF){
        scanf("%d", &allpri);
        init();
        for(i = 1; i <= allpri; i++) scanf("%I64d", &pri[i]);
        for(i = 1; i <= n; i++){
            scanf("%I64d",  &num);
           // if(num == 0LL)  zero ++;
            j = 1;
            while(num != 1 && j <= allpri){
                while((num % pri[j]) == 0){
                    res[i][j] ++;
                    num /= pri[j];
                }
                    res[i][j] %= 3;
                j ++;
            }
//            for(j = 1; j <= allpri; j++){
//                printf("%d ", res[i][j]);
//            }
//            printf("\n");
        }
        for(i = 1; i < n; i++){
            scanf("%d%d", &x, &y);
            add(x, y);
        }
//        for(i = 1; i <= n; i++){
//            printf("%d:\n", i);
//            for(j = head[i]; j != -1; j = p[j].next){
//                printf("%d ", p[j].v);  system("pause");
//            }
//            printf("\n");
//        }
        t = n;dfs(1, -1);
        ans =
        printf("%I64d\n", ans);
    }
    return 0;
}
