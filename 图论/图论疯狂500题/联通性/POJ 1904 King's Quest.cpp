#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

#define N 4004
#define M 240004
#define LL __int64
#define INF 0x3f3f3f3f
int head[N], dfn[N], low[N], st[N], belong[N];
int no, num, id, top;
bool vis[N];

struct point{
    int  v, next;
    point(){};
    point(int x, int y): v(x), next(y){};
}p[M];
vector<int>vec[N>>1];

void init(){
    memset(head, -1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
    memset(vis, false, sizeof(vis));
fill(vec, vec + N, vector<int>() );
    no = num = top = id = 0;
}

void add(int x, int  y){
    p[no] = point(y, head[x]);  head[x] = no++;
}

void tarjan(int x){
    dfn[x] = low[x] = ++num;
    vis[x] = true;  st[top++] = x;

    int i, y;

    for( i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(dfn[y] == -1){
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if(vis[y]){
            low[x] = min(low[x], dfn[y]);
        }
    }
    if(low[x] == dfn[x]){
        id++;
        do{
            y = st[--top];
            vis[y] = false;
            belong[y] = id;
        }while(y != x);
    }
}
inline void scan_d(int &ret) {
    char c;
    ret=0;
    while((c=getchar())<'0'||c>'9');
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();

}
int main(void){
    int n, i, j, x, y, k;
    while(scanf("%d", &n) != EOF){
        init();
        for(i = 1; i <= n; i++){
           scanf("%d", &k);
           // scan_d(k);
            while(k--){
                scanf("%d", &x);
                //scan_d(x);
                add(i, x + n);
            }
        }

        for(i = 1; i <= n; i++){
        scanf("%d", &x);
           // scan_d(x);
            add(x + n, i);
        }

        for(i = 1 ; i <= n; i++){
            if(dfn[i] == -1){
                tarjan(i);
            }
        }



        for(i = 1; i <= n; i++){
            for(j = head[i]; j != -1; j = p[j].next){
                y  = p[j].v;
                if(belong[i] == belong[y])  vec[i].push_back(y-n);
            }
        }

        for(i = 1; i <= n; i++){
            y = vec[i].size();
            printf("%d", y);
            sort(vec[i].begin(), vec[i].end());
            for(j = 0; j < y; j++){
                printf(" %d", vec[i][j]);
            }
            printf("\n");
        }
    }

	return 0;
}
