#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 10004
#define M
#define LL __int64
#define INF 0x3f7f7f7f

int head[N], deep[N], belong[N], cnt[N], num[N], n, t, no, k, ans, idx, sum;
bool vis[N], fin[N];
struct point{
    int  v, next, dis;
    point(){};
    point(int x, int y, int z):v(x), next(y), dis(z){};
}p[N << 1];

void add(int x, int y, int z){
    p[no] = point(y, head[x], z);   head[x] = no++;
    p[no] = point(x, head[y], z);   head[y] = no++;
}
void init(){
    memset(head, -1, sizeof(head));
    memset(vis, false, sizeof(vis));
    sum = 0, no = 0;
}

void findcon(int x, int fa){
    int i, y, temp = 0, pmax = 0;   cnt[x] = 0;
    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(vis[y] || y == fa) continue;
        findcon(y, x);
        temp += cnt[y];
        pmax =  max(pmax, cnt[y]);
    }
    cnt[x] = temp + 1;
    pmax = max(t - cnt[x], pmax);
    //pmax用与若以此点为根，其子树们的节点数的最大值
    //往下搜完儿子们的节点总数，父亲那块的点总数就是整棵树的点-儿子们的点
    if(ans > pmax){
        ans = pmax;
        idx = x;    //idx是本树重心，更新
    }
}

void predeal(int x, int fa){
    int i, y;
    num[++no] = deep[x];        //搜集距离。
    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(y == fa || vis[y]) continue;
        deep[y] = deep[x] + p[i].dis;
        predeal(y, x);
    }
}

int caldis(int x){
    int i, j, temp = 0;
    sort(num + 1, num + x + 1);

    i = 1;  j = x;
    while(i < j)    //枚举小的值，再枚举+它<=k的最大值，这样他们之间的+小值也会<=k
    {
        while(num[i] + num[j] > k && j > i) j--;
        temp += (j - i);
        i++;
    }
    return temp;
}
void dfs(int x, int fa){
    int i, y;  ans = INF;

    findcon(x, -1);     //寻找重心

    deep[idx] = 0;  no = 0;
    predeal(idx, -1);   vis[idx] = true;    //处理距离 标记
    sum += caldis(no);  //先计算所有的值

    for(i = head[idx]; i != -1; i = p[i].next){
        y = p[i].v;
        if(y == fa || vis[y]) continue;

        no = 0;
        predeal(y, idx); sum -= caldis(no); //统计所有只在某儿子上的，从答案中减去
        t = cnt[y];
        dfs(y, idx);    //递归处理分开的树
    }
}

int main(void)
{
    int i, x, y, z;
    while(scanf("%d%d", &n, &k) && (n || k)){
        init();
        for(i = 1; i < n; i++){
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z);
        }
        t = n;
        dfs(1, -1);
        printf("%d\n", sum);
    }

    return 0;
}
