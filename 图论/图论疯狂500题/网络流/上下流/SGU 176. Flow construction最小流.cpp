#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

#define N 105
#define M 20010
#define INF 0x3f3f3f3f

struct point{
    int u, v, flow, next;
    point(){};
    point(int x, int y, int z, int w): u(x), v(y), next(z), flow(w){};
}p[M];
int head[N], cur[N], st[M], d[N];
bool vis[N];
struct Infor{
    int lim, pointer;
    Infor(){};
    Infor(int xx, int yy): lim(xx), pointer(yy){};
}info[5002];

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

void output(int n){
    int i;
    for(i = 1; i <= n; i++){
        printf("%d%c", p[info[i].pointer].flow + info[i].lim, i == n ? '\n' : ' ');
    }
}
int main(){
    int n, m, x, y, z, c, s, e, S, E;
    int first, again, sum, i;
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        sum = 0;
        s = 1;  e = n;  S = 0;  E = n + 1;
        for(i = 1; i <= m; i++){
            scanf("%d%d%d%d", &x, &y, &z, &c);
            if(c){
                add(S, y, z);   add(x, E, z);
                info[i] = Infor(z, no-2);
                sum += z;
            }
            else{
                add(x, y, z);   info[i] = Infor(0, no - 1);
            }
        }
        first = dinic(S, E, E + 1);
        if(first == sum){
            printf("0\n");
            output(m);
        }
        else {
            add(e, s, INF);
            again = dinic(S, E, E + 1);
            if(again + first == sum){
                printf("%d\n", p[no-1].flow);
                output(m);
            }
            else {
                printf("Impossible\n");
            }
        }
    }
    return 0;
}
