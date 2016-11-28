#include<cstdio>
#include<cstring>
#include<algorithm>
#include <ctype.h>
using namespace std;

#define N 1204
#define M 5000
#define T 4200004
#define INF 0x3f3f3f3f

int  st[M], ans, pos[M], val[M];

bool vis[N];
char map[400];

struct DLX {
    int l[T], r[T], u[T], d[T];
    int cnt[N], row[T], col[T], head[M];
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

    bool  dfs(){
        int i, j, now;
        if(r[0] == 0){
            for(i = 1; i <= ans; i++){
                map[pos[st[i]]] = val[st[i]]+'A'-1;
            }
            for(i = 0, now = 0; i < 16; i++){
                for(j = 0; j < 16; j++){
                    printf("%c", map[now]);
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

            if(dfs()) return true;
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
    while(scanf("%s", map)!=EOF){
        for(i = 16; i < 256; i+=16) {
            scanf("%s", map + i);
        }
        //init
        dlx.init(1024);
        id = now =  ans = 0;
        memset(vis, false, sizeof(vis));

        for(i = 0; i < 16; i++){
            for(j = 0; j < 16; j++){
                if(isupper(map[now])){
                    loc = i / 4  * 4 +j / 4;
                    a = i * 16 + j + 1;  b = i * 16 + 256 + map[now] - 'A' + 1;
                    c = 512 + j * 16 + map[now] - 'A' + 1;
                    d = loc * 16 + 768 +  map[now] - 'A' + 1;
                    vis[a] = vis[b] = vis[c] = vis[d] = true;
                  //  if(i == 0) printf("have%d %d %d\n", i, j, d);
                    dlx.add(++id, a) ;
                    dlx.add(id, b) ;
                    dlx.add(id, c) ;
                    dlx.add(id, d);
                    pos[id] = a - 1;    val[id] =  map[now] - 'A' + 1;
                }
                now ++;
            }
        }
        now = 0;
        for(i = 0; i < 16; i++){
            for(j = 0; j < 16; j++){
              //  printf("%d\n", i);
                if(!isupper(map[now])){
                    for(k = 1; k <= 16; k++){

                        loc = i / 4 * 4 +j / 4;
                        a = i * 16 + j + 1;  b = i * 16 + 256 + k;
                        c = 512 + j * 16 + k;
                        d = loc * 16 + 768 + k;
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
        dlx.dfs();     printf("\n");
    }
    return 0;
}
