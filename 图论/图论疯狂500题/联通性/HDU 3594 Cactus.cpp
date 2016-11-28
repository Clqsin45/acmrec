#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 20004
#define M 50005
#define LL __int64
#define INF 0x3f7f7f7f

int head[N], dfn[N], low[N], st[N];
int no, top, num, id;
bool vis[N], finish[N], flag;
struct point{
    int v, next;
    point(){};
    point(int x, int y):v(x), next(y){};
}p[M];
void init(){
    memset(vis, false, sizeof(vis));
    memset(head, -1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
    memset(finish, false, sizeof(finish));
    no = top = num = id = 0;
    flag = false;
}

void add(int x, int y){
    p[no] = point(y, head[x]);  head[x] = no++;
}

void tarjan(int x){
    dfn[x] = low[x] = ++num;
    vis[x] = true;  st[top++] = x;
    int i,  y, cnt = 0;
    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
      //  printf("~%d %d\n", x, y);
        if(finish[y]) {
            flag = true;
        }
        if(dfn[y] == -1){
            tarjan(y);
            if(low[y] > dfn[x])     flag = true;
            if(low[y] < dfn[x])     cnt++;
            low[x] = min(low[x], low[y]);
        }
        else if(vis[y]){
            low[x] = min(low[x], dfn[y]);
            cnt ++;
        }
    }
    if(low[x] == dfn[x]){
        id ++;
        do{
            y = st[--top];
            vis[y] = false;
        }while(st[top] != x);
    }
    if(cnt >= 2)    flag = true;
    finish[x] = true;

}


int main(void)
{
    int TC, n, x, y, i;

    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &n);
        init();
        while(scanf("%d%d", &x, &y) &&(x|| y)){
            add(x, y);
        }
        flag = false;
        for(i = 0; i < n; i++)
            if(dfn[i] == -1)    tarjan(i);
        if(id > 1)  flag = false;
        if(flag)    printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
