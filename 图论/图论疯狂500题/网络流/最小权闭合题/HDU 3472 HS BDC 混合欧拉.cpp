#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define T 33
#define M 3100005
#define LL __int64
#define INF 0x3f7f7f7f

struct point{
    int u, v, flow, next;
    point(){};
    point(int x, int y, int w, int z):u(x), v(y), flow(w), next(z){};
}p[M];
int head[T], cur[T], d[T], no, s, e, st[M], n, m, cnt;
int in[T], out[T], f[T], vis[T];
char ch[T];
void add(int x, int y, int z){
    p[no] = point(x, y, z, head[x]);    head[x] = no++;
    p[no] = point(y, x, 0, head[y]);    head[y] = no++;
}

void init(){
    int i;
    memset(head, -1, sizeof(head));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(vis, 0, sizeof(vis));
    for(i = 1; i <= 26; i++)    f[i] = i;
    no = 0;
}

bool bfs()
{
    int i, x, y;
    memset(d, -1, sizeof(d));
    queue<int>q;
    d[s] = 0;   q.push(s);
    while(!q.empty()){
        x = q.front();  q.pop();
        for(i = head[x]; i != -1; i = p[i].next){
            if(p[i].flow && d[y = p[i].v] < 0){
                d[y] = d[x] + 1;
                if(y == e)  return true;
                q.push(y);
            }
        }
    }
    return false;
}

int dinic()
{
    int i, top, x = s,  maxflow = 0, nowflow, loc;
    while(bfs()){
        for(i = s; i <= e; i++) cur[i] = head[i];
        top = 0;
        while(true){
            if(x == e){
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
                if(p[i].flow && d[p[i].v] == d[x] + 1)  break;
            }
            cur[x] = i;
            if(i != -1){
                st[top++] = i;
                x = p[i].v;
            }
            else{
                if(!top)    break;
                d[x] = -1;
                x = p[st[--top]].u;
            }
        }
    }
    return maxflow;
}

bool check(){
    int i, j;
    for(i = 1; i <= 26; i++){
        for(j = i + 1; j <= 26; j++){
            if(vis[i] && vis[j]){
                if(f[i] != f[j])    return false;
            }
        }
    }
    return true;
}

int find(int x){
    if(x == f[x])   return x;
    return f[x] = find(f[x]);
}

void merge(int x, int y){
    x = find(x); y = find(y);
    f[x] = y;
    return;
}

int main(void)
{
    int TC, tc, i, j, l, t, sol, x, y, sum, odd;
    bool flag;
    scanf("%d", &TC);
    s = 0;  e = 27;
    for(tc = 1; tc <= TC; tc++){
        scanf("%d", &n);
        flag = true;
        init();
        sum = odd = 0;
        for(i = 1; i <= n; i++){
            scanf("%s%d", ch + 1,  &t);
            l = strlen(ch + 1);
            x = ch[1] - 'a' + 1;
            y = ch[l] - 'a' + 1;
            if(t == 1){
                add(x, y, 1);
            }
            out[x] ++;  in[y] ++;
            merge(x, y);
            vis[x] = vis[y] = 1;
        }
        printf("Case %d: ", tc);
        for(i = 1; i <= 26; i++)
            f[i] = find(i);
        if(!check()) {
            printf("Poor boy!\n");
            continue;
        }
        x = y = 0;
        for(i = 1; i <= 26; i++){
            sol = out[i] - in[i];
            if(sol & 1){
                odd ++;
                if(sol < 0) x = i;
                else if(sol > 0)    y = i;
            }
            if(sol > 0) {
                add(s, i, sol / 2);
                sum += (sol / 2);
            }
            else if(sol < 0){
                add(i, e, -sol / 2);
            }
        }
        if(odd == 0 || (odd == 2 && x && y)){
            if(odd == 2)    add(x, y, 1);
        }
        else {
            printf("Poor boy!\n");
            continue;
        }
        if(sum == dinic()){
            printf("Well done!\n");
        }
        else printf("Poor boy!\n");
    }
    return 0;
}
