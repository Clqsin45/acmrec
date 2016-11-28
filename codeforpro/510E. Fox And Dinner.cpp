#include <bits/stdc++.h>
using namespace std;

#define N 222
#define M 25000
#define INF 0x3f3f3f3f
struct point{
    int u, v, flow, next;
    point(){};
    point(int x, int y, int z, int w): u(x), v(y), next(z), flow(w){};
}p[M];
int a[N];
int head[N], cur[M], st[M], d[N], rec[23333];
bool vis[N], nicprime[23333];
vector<int> ans[N];

int no, s,  e, id;

void add(int x, int y, int z){
    p[no] = point(x, y, head[x], z);     head[x] = no++;
    p[no] = point(y, x, head[y], 0);    head[y] = no++;
}
void init(){
    int i, j, cnt = 0;

    for(i = 2; i <= 20000; i++){
        if(!nicprime[i])    rec[cnt++] = i;
        for(j = 0; j < cnt && i * rec[j] <= 20000; j++)
        {
            nicprime[i * rec[j]] = true;
            if(i % rec[j] == 0)   break;
        }
    }

    memset(head, -1, sizeof(head));
    no = 0;
}

bool bfs(){
    memset(d, -1, sizeof(d));
    memset(vis, false, sizeof(vis));
    queue<int>q;
    int x, y, i;
    q.push(s);  d[s] = 0;  vis[s] = true;
    while(!q.empty()){
        x = q.front();  q.pop();
        for(i = head[x]; i != -1; i = p[i].next){
            y = p[i].v;
            if(p[i].flow && d[y] < 0){
                d[y] = d[x] + 1;
                if(y == e) return true;
                q.push(y);
            }
        }
    }
    return false;
}

int dinic(){
    int x = s, top, i, maxflow = 0, nowflow, loc;
    while(bfs()){
     //   printf("!!!%d\n", maxflow);
        for(i = s; i <= e ; i++)    cur[i] = head[i];
        top = 0;
        while(true){
            if (x == e){
                nowflow = INF;
                for(i = 0; i < top; i++){
                    if(p[st[i]].flow < nowflow){
                        nowflow = p[st[i]].flow;
                        loc = i;
                    }
                }
                for(i = 0; i < top; i++){
                    p[st[i]].flow -= nowflow;
                    p[st[i]^1].flow += nowflow;
                }
                maxflow += nowflow;
                top = loc;  x = p[st[top]].u;
            }
            for(i = cur[x]; i != -1; i = p[i].next){
                if(p[i].flow && d[p[i].v] == d[x] + 1 ) break;
            }
            cur[x] = i;
            if(i != -1){
                st[top++] = i;
                x = p[i].v;
            }
            else {
                if(!top)break;
                d[x] = -1;
                x = p[st[--top]].u;
            }

        }
    }
    return maxflow;
}

void dfs(int x){
    ans[id].push_back(x);   vis[x] = true;
    int i, y;
    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(!vis[y]){
            dfs(y);
        }
    }
}
int main(void){
    int n, m, i, j, x, y, z;
    cin >> n;
    s = 0;   e= n + 1;
    init();
    for(i = 1; i <= n; i++){
        cin >> a[i] ;
        if(a[i] & 1){
           add(s, i, 2);
        }
        else add(i, e, 2);
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if((a[i] & 1) && !(a[j] & 1))
            if(!nicprime[a[i] + a[j]]){
             //   printf("%d %d\n", i, j);
                add(i, j, 1);
            }
        }
    }

    int flow = dinic();

    if(flow != n){
        printf("Impossible\n");
    }
    else {
      //  printf("HHAA\n");
        memset(head, -1, sizeof(head));
        id = no;    no = 0;
        for(i = 0; i < id; i+= 2){
            if(p[i].u != 0 && p[i].v != e && p[i].flow == 0){
               add(p[i].u, p[i].v, 1);
              // printf("%d %d\n", p[i].u, p[i].v);

            }
        }
        memset(vis, false, sizeof(vis));
        id = 0;
        for(i = 1; i <= n; i++){
            if(!vis[i]){
                ++id;
                dfs(i);
            }
        }
        printf("%d\n", id);
        for(i = 1; i <= id; i++){
            m = ans[i].size();
            printf("%d", m);
            for(j = 0; j < m; j++){
                printf(" %d", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
