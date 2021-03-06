#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

#define N 1500
#define M 400000
#define INF 0x3f3f3f3f

struct point{
    int u, v, flow, next;
    point(){};
    point(int x, int y, int z, int w): u(x), v(y), next(z), flow(w){};
}p[M];
int a[N];
int head[N], cur[M], st[M], d[N];
bool vis[N];
struct Infor{
    int lim, pointer;
    Infor(){};
    Infor(int xx, int yy): lim(xx), pointer(yy){};
}info[M];

int no,  id;

void add(int x, int y, int z){
    p[no] = point(x, y, head[x], z);     head[x] = no++;
    p[no] = point(y, x, head[y], 0);    head[y] = no++;
}
void init(){
    memset(head, -1, sizeof(head));
    no = 0;
}

bool bfs(int s, int e){
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

int dinic(int s, int e, int siz){
    int x = s, top, i, maxflow = 0, nowflow, loc;
    while(bfs(s, e)){
     //   printf("!!!%d\n", maxflow);
        for(i = 0; i <= siz ; i++)    cur[i] = head[i];
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

int main(){
    int n, m, c, x, y, l, r, S, E, t, s, e, sum;
    int i, j;
    while(scanf("%d%d", &n, &m) != EOF){
        init(); id = 0;
        s = 0;  e = n + m +1;
        S = e + 1;  E = S +1;
        sum = 0;
        for(i =1; i <= m; i++){
            scanf("%d", &x);
            add(S, e, x);   add(n +i, E, x);
            add(i + n, e, INF);
            sum += x;
        }
        for(i =1; i <= n; i++){
            scanf("%d%d", &c, &x);
            add(s, i, x);
            while(c--){
                scanf("%d%d%d", &t, &l, &r);
                r -= l; t++;
                add(i, E, l);  add(S, t + n, l);
                sum += l;
                add(i, t + n, r);
                info[++id] = Infor(l, no - 1);
            }
        }
        add(e, s, INF);

        if(dinic(S, E, E + 1) == sum){

            sum = p[no-1].flow ;p[no-2].flow = 0; p[no-1].flow = 0;
            printf("%d\n", sum + dinic(s, e, e + 1));
            for(i = 1; i <= id; i++){
                printf("%d\n", info[i].lim+ p[info[i].pointer].flow);
            }

        }else{
            printf("-1\n");
        }
        printf("\n");
    }

}
