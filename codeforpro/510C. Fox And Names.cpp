#include <bits/stdc++.h>
using namespace std;

#define N 150

int head[N], in[N];
bool vis[N];
struct point{
    int u, v, next;
    point(){};
    point(int x, int y, int z): u(x), v(y), next(z){};
}p[N];
char ch[N][N];
vector <int> ans;
queue<int>q;
int no = 0;


void init(){
    memset(head, -1, sizeof(head));
    memset(in, 0, sizeof(in));
    memset(vis, false, sizeof(vis));
    no = 0;
}

void add(int x, int y){
    p[no] = point(x, y, head[x]);   head[x] = no++;
    in[y] ++ ;
}

bool bfs(){
    int i, j, x, y;
    for(i = 0; i < 26; i++){
        if(in[i] == 0){
            ans.push_back(i);
            vis[i] = true;
            q.push(i);
         //   printf("%c\n", i + 'a');
        }
    }
    while(!q.empty()){
        x = q.front();  q.pop();
        for(i = head[x]; i != -1; i = p[i].next){
            y = p[i].v;
            in[y] --;
            if(in[y] == 0){
                vis[y] = true;
                q.push(y);
                ans.push_back(y);
            }
        }
    }
    for(i = 0; i < 26; i++)if(!vis[i])  return false;
    return true;
}

int main(){
    int n, i, j, m;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%s", ch[i] + 1);
    }

    init();
    for(i = 2; i <= n; i++){
        m = strlen(ch[i-1] + 1);
        for(j = 1; j <= m; j++){
            if(ch[i-1][j] == 0){
              //  printf("!!\n");
                break;

            }
            else if(ch[i][j] == 0){
                printf("Impossible\n");
                return 0;
            }
            else if(ch[i-1][j] != ch[i][j]){
               // printf("!!\n");
                add(ch[i-1][j] - 'a', ch[i][j] - 'a');
                break;
            }
        }
    }
    if(!bfs()){
        printf("Impossible\n");
        return 0;
    }
    for(i = 0; i < 26; i++){
        printf("%c", ans[i] + 'a');
    }
    printf("\n");


}
