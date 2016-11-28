/*******************
若解不唯一，一定要把dfs改回bool型搜到一组就罢手。。。
*******************/

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <ctype.h>
using namespace std;

#define N 1004
#define T 400000
#define INF 0x3f3f3f3f

int  st[N], ans, pos[N], val[N];

bool vis[N];
char map[100];
int num[100];

struct DLX {
    int l[T], r[T], u[T], d[T];
    int cnt[N], row[T], col[T], head[N];
    int id, n;

    void init(int nt){
        memset(head, -1, sizeof(head));
        memset(cnt, 0, sizeof(cnt));

        this->n = nt;
        int i;
        for(i  = 0; i <= n; i++) {
            u[i] = d[i] = i;
            l[i] = i - 1;   r[i] = i +1;
        }
        l[0] = n;   r[n] = 0;
        id = n + 1;
    }

    void add(int x, int y){

        if(head[x] == -1 ){
            head[x] = l[id] = r[id] = id;
        }
        else{
            l[id] = head[x];    r[id] = r[head[x]];
            l[r[id]] = r[l[id]] = id;
            head[x] = id;
        }
        u[id] = u[y];   d[id]  = y;
        d[u[id]] = id;  u[y] = id;
        col[id] = y;    row[id] = x;
        cnt[y] ++;  id ++;
    }

    void del(int x){
        int i, j;
        r[l[x]] = r[x]; l[r[x]] = l[x];
        for(i = d[x]; i != x; i = d[i]){
            for(j = r[i]; j != i; j = r[j]){
                u[d[j]] = u[j]; d[u[j]] = d[j];
                cnt[col[j]] --;
            }
        }
    }

    void resume(int x){
        int i, j;
        for(i = u[x]; i != x; i = u[i]){
            for(j = l[i]; j != i; j = l[j]){
                u[d[j]] = d[u[j]] =j;
                cnt[col[j]] ++;
            }
        }
        l[r[x]] = r[l[x]] = i;
    }

    bool dfs(){
        int i, j, now;
        if(r[0] == 0){
            for(i = 1; i <= ans; i++){
                num[pos[st[i]]] = val[st[i]];
            }
            for(i = 0, now = 0; i < 9; i++){
                for(j = 0; j < 9; j++){
                    printf("%d", num[now]);
                    now ++;
                }
                printf("\n");
                //system("pause");
            }
            return true;
        }
        int idx, temp = INF;
        for(i = r[0]; i != 0; i = r[i]){
           if(temp > cnt[i]){
                temp = cnt[i];
                idx = i;
           }
        }
        if(temp == 0)return false;
        del(idx);

        for(i = d[idx]; i != idx; i = d[i]){
            st[++ans] = row[i];
                //      printf("%d %d\n", temp, idx);
            for(j = r[i]; j != i; j = r[j]){
                del(col[j]);
            }

           if( dfs()) return true;
            for(j = l[i]; j != i; j = l[j]) resume(col[j]);
            ans --;
        }
        resume(idx);
        return false;
    }
}dlx;
int main(){
 //freopen("in.txt", "r", stdin);
    char s[4];
    int  i, j, k, now, id, a, b, c, d, loc, tc;
    scanf("%d", &tc);
    while(tc--){
        for(i = 0; i < 81; i++) {
            scanf("%1d", &num[i]);
        }


        //init
        dlx.init(324);
        id = now =  ans = 0;
        memset(vis, false, sizeof(vis));

        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                if(num[now]){
                    loc = i / 3  * 3 +j / 3;
                    a = i * 9 + j + 1;  b = i * 9 + 81 + num[now];
                    c = 162 + j * 9 +num[now] ;
                    d = loc * 9 + 243 + num[now] ;
                    vis[a] = vis[b] = vis[c] = vis[d] = true;
                  //  if(i == 0) printf("have%d %d %d\n", i, j, d);
                    dlx.add(++id, a) ;
                    dlx.add(id, b) ;
                    dlx.add(id, c) ;
                    dlx.add(id, d);
                    pos[id] = a - 1;    val[id] = num[now];
                }
                now ++;
            }
        }
        now = 0;
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
              //  printf("%d\n", i);
                if(!num[now]){
                    for(k = 1; k <= 9; k++){

                        loc = i / 3 * 3 +j / 3;
                        a = i * 9 + j + 1;  b = i * 9 + 81 + k;
                        c = 162 + j * 9 + k;
                        d = loc * 9 + 243 + k;
                     //   printf("%d %d %d %d %d\n",a, k,vis[c], vis[b], vis[d]);
                       // if(i == 0) printf("have%d %d %d\n", i, j, d);
                        if( vis[b] || vis[c]||vis[d]) continue;

                        dlx.add(++id, a);
                        dlx.add(id, b) ;
                        dlx.add(id, c) ;
                        dlx.add(id, d);
                        pos[id] = a - 1;    val[id] = k;
                    }
                }
                now ++;
            }
        }
     //  printf("!!!\n");
       if(! dlx.dfs()) printf("Could not complete this grid.\n");
       if(tc) printf("\n");
    }
    return 0;
}
