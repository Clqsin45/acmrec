#include<cstdio>
#include <cstring>
#include <vector>
#include<algorithm>
using namespace std;

#define N 66
#define T 40000
#define INF 0x3f3f3f3f
int op[N], f[N];
int ANS;
/*
struct DLX{
    int l[T], r[T], u[T], d[T];
    int cnt[N], col[T], row[T], head[N];
    int id, n;
    bool vis[N], v[N];
    void init(int nt){
        memset(vis, false, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));
        memset(head, -1, sizeof(head));
        int i;
        for(i = 0 ; i<= n; i++){
            u[i] = d[i] = i;
            l[i] = i - 1;   r[i] = i +1;
        }
        l[0] = n;   r[n] = 0;
        id = n + 1;
    }

    void add(int x, int y){
        u[id] = u[y];   d[id] = y;
        d[u[id]] = id;  u[y] = id;
        if(head[x] == -1){

            head[x] = l[id] = r[id] = id;
        }
        else{
            l[id] = head[x];    r[id] = r[head[x]];
            r[l[id]] = l[r[id]] = id;
            head[x] = id;
        }
        col[id] = y ;   cnt[y] ++;  row[id] = x;
        id ++;
    }

    void resume(int x){
        int i;
        for(i = d[x]; i != x; i  = d[i]){
            l[r[i]] = i; ;
            r[l[i]] = i;
        }
    }

    void del(int x){
        int i;
        for(i = u[x]; i != - 1; i = u[i]){

            l[r[i]] = l[i], r[l[i]] = r[i];
        }
    }

    int H(){
        memset(v, false, sizeof(v));
        int i, j, k, ans = 0;
        for(i = r[0]; i != 0; i = r[i]){
            if(v[i]) continue;

            v[i] = true;   ans ++;
            for(j = d[i]; j != i; j =d[j]){
                for(k = r[j]; k != j; k = r[k]){
                    v[col[k]] = true;
                }
            }
        }
    }
    void dfs(int ct){
        if(ct + H() >= ANS)return ;
        if(r[0] == 0) {
            ANS = min(ANS, ct);
            return ;
        }
        int i, temp = INF, idx, j;
        for(i = r[0] ;i != 0; i = r[i]){
            if(cnt[i] < temp){
                temp = cnt[i];
                idx = i;
            }
        }
        if(temp == 0) return ;
        for(i = d[idx]; i != idx; i = d[i]){
            if(vis[op[row[i]]]) continue;
            vis[row[i]] = true;
            del(i);
            for(j = r[i]; j != i; j = r[j]){
                del(j);
            }
            dfs(ct +1);
            for(j = l[i]; j != i; j = l[j]) resume(j);
            resume(i);
        }

    }
}dlx;
*/
struct DLX{
    int l[T], r[T], u[T], d[T];

    int cnt[N], col[T], row[T], head[N];
    bool vis[N], v[N];
    int n, id;
    void init(int nt){
        int i;
        this->n = nt;

        for(i = 0; i <= n; i++){
            u[i] = d[i] = i;
            l[i] = i -1;    r[i] = i + 1;
        }
        l[0] = n;    r[n] = 0;
        id = n + 1;
        memset(cnt, 0, sizeof(cnt));
        memset(head, -1, sizeof(head));
        memset(v, false, sizeof(v));
    }

    void add(int x, int y){
        u[id] = u[y];    d[id] = y;
        d[u[y]] = id;    u[y] = id;


        if(head[x] == -1){
            head[x] = l[id] = r[id] = id;
        }else{
            l[id] = head[x];    r[id] = r[head[x]];
            l[r[head[x]]] = id;    r[head[x]] = id;
        }
        col[id] = y;    row[id] = x;
        cnt[y] ++;    id++;
    }


    void del(int x){
        int i;
        for(i = u[x]; i != x; i = u[i]){
            l[r[i]] = l[i];    r[l[i]] = r[i];
        }

    }

    void resume(int x){
        int i;
        for(i = d[x]; i != x; i = d[i]){
            l[r[i]] = r[l[i]] = i;
        }
    }

    int H(){
        memset(vis, false, sizeof(vis));

        int i, j,k, ans = 0;

        for(i = r[0]; i != 0; i = r[i]){
            if(vis[i]) continue;
            ans ++;    vis[i] = true;
            for(j = d[i]; j != i; j = d[j]){
                for(k = r[j]; k != j; k = r[k]){
                    vis[col[k]] = true;
                }
            }
        }

        return ans;
    }

    void dfs(int ct){
        if(ct + H() >= ANS) return ;

        if(r[0] == 0) {
            ANS = min(ANS, ct);
            return;
        }
        int i, j, idx, temp = INF;

        for(i = r[0]; i != 0; i = r[i]){
            if(cnt[i] < temp){
                temp = cnt[i];    idx = i;
            }
        }
        for(i = d[idx]; i != idx; i = d[i]){
            if(v[op[row[i]]] ) continue;
            v[row[i]] = true;
            del(i);
            for(j = r[i]; j != i; j =r[j]){
                del(j);
            }
            dfs(ct +1);
            for(j = l[i]; j != i; j = l[j]){
                resume(j);
            }
            resume(i);
            v[row[i]] = false;
        }
    }


}dlx;
vector<int>vec[N];
int st[T], top;
int main(void){
    int  TC, tc, i, j, k, K,  n, m, id, x, y;
    scanf("%d", &TC);
    for(tc= 1; tc<= TC; tc++){
        scanf("%d",&n);
        id = 0; top = 0;

        fill(vec, vec + N, vector<int>() );
        //dlx.init(n<<1);
        for(i = 0; i < n;i++){
            scanf("%d", &m);
            if(m == 1){
                st[++top] = i *2;
                op[top] = N - 1;
            }
            else{
                //op[i*2] = i*2+1; op[i*2 +1] = i*2;
                st[++top] = i *2; st[++top] = i *2 +1;
                op[top-1] = top;    op[top] = top - 1;
            }
            for(j = 0; j < m; j++){
                scanf("%d", &K);
                for(k = 1; k <= K; k++){
                    scanf("%d%d", &x, &y);
                    vec[i*2+j].push_back(x*2+y);
                   // printf("%d\n", i *2 + j);
                    //dlx.add(i*2+j, x*2+y+1);
                }
                vec[i*2+j].push_back(i*2+j);
                if(m == 2){
                    vec[i*2+j].push_back(i*2+(j^1));
                }
                sort(vec[i*2+j].begin(), vec[i*2+j].end() );
            }
        }
        sort(st +1, st +top +1);
        //top = unique(st + 1, st + top + 1) - st - 1;

        for(i = 1; i <= top; i++)   {
            //printf("%d", st[i]);
            f[st[i]] = i;
        }
        dlx.init(top);//  printf("%d\n", top);
        for(i = 1; i <= top; i++){
              //  printf("%d %d %d\n", i, st[i], vec[st[i]].size());
            for(j = 0; j < vec[st[i]].size(); j++){
                dlx.add(i, f[vec[st[i]][j]]);
             //  printf("%d %d, %d %d\n", i, st[i], f[vec[st[i]][j]], vec[st[i]][j]);
            }
        }


        ANS = INF;
        dlx.dfs(0);
        printf("Case %d: %d\n", tc, ANS);
    }
    return 0;
}
