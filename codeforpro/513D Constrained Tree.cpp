#include <bits/stdc++.h>
using namespace std;
const int N = 1000004;
int Lmin[N], Rmin[N], Lmax[N], Rmax[N];
int id = 1;
bool gg = false;
struct point{
    int leftson, rightson;
}p[N];

void init(){
    memset(Lmin, 0x3f, sizeof(Lmin));
    memset(Rmin, 0x3f, sizeof(Rmin));
    memset(Rmax, 0, sizeof(Rmax));
    memset(Lmax, 0, sizeof(Lmax));
    memset(p, 0, sizeof(p));
}

void dfs(int l, int r){
    //l 当前节点 id 下一级
    int i, L, R;
    if(gg)return;
    ++id;
    if(Lmax[l] != 0){
        //左边最小的值一定小于等于lmin[l]
        //即id<=lmin[l]
        //反之  若id>lmin[l] 则gg
        if(id > Lmin[l]){
            gg = true;    return;
        }
        p[l].leftson = id;
        dfs(id, Lmax[l]);

    }
    //若右树有限制
    if(Rmax[l] != 0){
        //同理
        if(id > Rmin[l]){
            gg= true; return;
        }
        p[l].rightson = id;
        dfs(id, max(r, Rmax[l]));
    }//无限制 就随便加了
    else if(id <= r) {
        p[l].rightson = id;
        dfs(id, r);
    }
}

void dfs(int x){
    int i;

    if(p[x].leftson != 0)   {
        dfs(p[x].leftson);
    }
    printf("%d ", x);
    if(p[x].rightson!= 0){
        dfs(p[x].rightson);
    }
}
int main(){
    int n, c, i, x, y;
    char ch[10];
    scanf("%d%d", &n, &c);
    init();
    for(i = 1; i <= c; i++){
        scanf("%d%d%s", &x, &y, ch);
        if(ch[0] == 'L'){
            Lmax[x] = max(y, Lmax[x]);
            Lmin[x] = min(y, Lmin[x]);
        }
        else {
            Rmax[x] = max(y,Rmax[x]);
            Rmin[x] = min(y, Rmin[x]);
        }
    }
    dfs(1, n);
    if(gg)  printf("IMPOSSIBLE\n");
    else dfs(1);
    return 0;
}
