#include <bits/stdc++.h>
using namespace std;

#define N 100004
#define M 200004
#define ll __int64
#define INF 0x3f3f3f3f
int shortestdis;
struct point{
    int u, v, next, cost;
    point(){};
    point(int x, int y, int z, int c){u = x, v = y; next = z, cost = c;}

    void print(){
        printf("%d %d %d\n", u,v, cost);
    }
}p[M];
int head[N], ds[N], de[N], vis[N], pre[N];
ll d[N];
int no;

vector <struct point>ans;

void add(int x, int y, int z){
    p[no] = point(x, y, head[x], z);    head[x] = no++;
}

void add(int x, int y, int z, int tt){
    p[tt] = point(x, y, head[x], z);    head[x] = tt;
}

void init(){
    memset(head, -1, sizeof(head)); no = 0;
}

void shortest_path(int s, int e, int *dis){
    int x, y, i;
    memset(dis, -1, sizeof(int)*N);
    queue<int> Q;
    dis[s] = 0;
    Q.push(s);
    while(!Q.empty()){
        x = Q.front();  Q.pop();
        for(i = head[x]; i != -1; i = p[i].next){
            y = p[i].v;
            if(dis[y] < 0){
                dis[y] = dis[x] + 1;
                Q.push(y);
            }
        }
    }
    shortestdis = dis[e];
}

void spfa(){
    memset(d, 0x3f, sizeof(d));
    memset(pre, -1, sizeof(pre));
    memset(vis, false, sizeof(vis));

    int i, x, y;
    queue<int>Q;
    Q.push(1);  d[1] = 0;   vis[1] = true;
    while(!Q.empty()){
        x = Q.front();  Q.pop();
        for(i = head[x]; i != -1; i = p[i].next)   {
            if(d[y = p[i].v] > d[x] + p[i].cost){
                d[y] = d[x] + p[i].cost;
                pre[y] = i;
                if(vis[y])  continue;
                vis[y] = true;
                Q.push(y);
            }

        }
        vis[x] = false;
    }
}
int main(){
    int n, m, i, j, d, usefull;
    int x, y, op;
    scanf("%d%d", &n, &m);
    usefull = 0;
    init();

    for(i = 1; i <= m; i++){
        scanf("%d%d%d", &x, &y, &op);
        usefull += op;
        add(x, y, op);  add(y, x, op);
    }
    m = max(m, n);  m ++;
    shortest_path(1, n, ds);

    shortest_path(n,1, de);
    int  id = no;
    init();
    for(i = 0; i < id; i++){
        if(ds[p[i].u] + de[p[i].v] + 1 == shortestdis){
            no ++;
            add(p[i].u, p[i].v, p[i].cost ? m - 1 : m + 1, i);
        }
    }

    spfa();
    memset(vis, false, sizeof(vis));
    for(i = pre[n]; i != -1; i = pre[p[i].u]){
        vis[i/2] = true;
        if(p[i].cost> m){
            p[i].cost = 1;
            ans.push_back(p[i]);//printf("%d %d %d\n", p[i].u, p[i].v, 1);
        }
    }
    for(i = 0; i < id; i+= 2){
        if(vis[i/2])  continue;
        if(p[i].cost == 0)  continue;
        if(p[i].cost == 1 || p[i].cost < m) {
            p[i].cost = 0;
            ans.push_back(p[i]);
        }
        //else printf("%d %d %d\n", p[i].u, p[i].v, 1);
    }
    m = ans.size();
    printf("%d\n",m);
    for(i = 0; i < m; i++){
        ans[i].print();
    }
    return 0;
}
