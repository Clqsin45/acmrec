#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define N 10004
#define M 200004
#define LL __int64
#define INF 0x3f3f3f3f

int low[N], dfn[N], st[N], head[N];
char dir[N][22];
int num, id, no, top;
vector<int>v;
map<string, int>f;
struct point{
    int u, v, next;
    point(){};
    point(int x, int y, int z):u(x), v(y), next(z){};
}p[M];

void init(){
    memset(dfn, -1, sizeof(dfn));
    memset(head, -1, sizeof(head));
    no = id = num = top = 0;
    v.clear();
    f.clear();
}

void add(int x, int y){
    p[no] = point(x, y, head[x]);   head[x] = no++;
    p[no] = point(y, x, head[y]);   head[y] = no++;
}

void tarjan(int x, int fa){
    //printf("%d\n", x);
    low[x] = dfn[x] = ++num;
    int i, y;

    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(y == fa) continue;
        if(dfn[y] == -1)    {
            tarjan(y, x);
            low[x] = min(low[x], low[y]);
        }
        else low[x] = min(low[x], dfn[y]);
       // printf("%d %d lowy = %d dfnx%d\n", x, y, low[y], dfn[x]);
        if(low[y] > dfn[x]){
            if(i & 1) v.push_back(i ^ 1);
            else v.push_back(i);
        }
    }
}


int main(void){
    int TC, i, n, m, x, y, ct;
    string a, b;
    char ta[22], tb[22];
    scanf("%d", &TC);
    while(TC--){
        scanf("%d%d", &n, &m);
        init(); ct = 0;
        while(m--){
            scanf("%s%s", ta, tb);
            a = ta; b = tb;
            if(f[a] == 0){
                f[a] = ++id;
                strcpy(dir[id], ta);
            }
            if(f[b] == 0)  {
                 f[b] = ++id;

                 strcpy(dir[id], tb);
            }
            add(f[a], f[b]);
        }
        id = 0;

        for(i = 1, ct = 0; i <= n; i++){

            if(dfn[i] == -1)   {
                tarjan(i, -1);
                ct ++;
            }
        }
        if(ct > 1){
            printf("0\n");
            continue;
        }
        printf("%d\n", v.size());
        n = v.size();
        sort(v.begin(), v.end());
        for(i = 0; i < n; i++){
            x = p[v[i]].u;  y = p[v[i]].v;
           // ta = dir[x];    tb = dir[y];
            printf("%s %s\n", dir[x], dir[y]);
        }
    }
	return 0;
}
