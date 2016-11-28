#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define N 20
#define T 200000
#define INF 0x3f3f3f3f
#define eps 1e-8
int K, cnt, n;
double dis[N][N];
int cover[T];

struct point{
    double x, y;
    void scan(){
        scanf("%lf%lf", &x, &y);
    }

    point(){};
    point(double a, double b):x(a), y(b){};
}p[N], ro[T];

struct DLX{
    int l[T], r[T], u[T], d[T];
    int col[T], cnt[N], head[T];
    int id, n;
    bool vis[N];

    void init(int nt){
        this->n = nt;
        int i;
        for(i = 0; i <= n; i++){
            u[i] = d[i] = i;
            l[i] = i - 1;   r[i] = i +1;
        }
        l[0] = n;   r[n] = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(head, -1, sizeof(head));
        id = n + 1;
    }

    inline void add(int x, int y){
        u[id] = u[y];   d[id] = y;
        d[u[y]] = id;   u[y] = id;
               cnt[y] ++;  col[id] = y;
        if(head[x] == -1){
            head[x ] = l[id] = r[id] = id;
            id++;
        }
        else{
            l[id] = head[x];    r[id] = r[head[x]];
            l[r[id]] = id;  r[l[id]] = id;
            head[x] = id;
            id ++;
        }

    }

    inline void del(int x){
        int i;
        for(i = u[x]; i != x; i = u[i]){
            l[r[i]] = l[i], r[l[i]] = r[i];
        }
    }
    inline void resume(int x){
        int i;
        for(i = d[x]; i != x; i = d[i]){
            l[r[i]] = r[l[i]] = i;
        }
    }

    int H(){
       // memset(vis, false, sizeof(vis));
        int i, j, k, ans = 0;
        for(i = r[0]; i != 0; i = r[i]) vis[i] = true;
        for(i = r[0]; i != 0; i = r[i]){
            if(vis[i]) {
            vis[i] = false;  ans ++;
            for(j = d[i]; j != i; j = d[j]){
                for(k = r[j]; j != k; k = r[k])
                    vis[col[k]] = false;
            }
            }
        }
        return ans;
    }

    bool dfs(int ct){
        if(ct + H() > K){
            return false;
        }
        if(r[0] == 0) return ct <= K;
        int i, j, idx, temp = INF;

        for(i = r[0]; i != 0; i = r[i]){
            if(temp > cnt[i])   {
                temp = cnt[i];
                idx=  i;
            }
        }
        for(i = d[idx]; i != idx; i= d[i]){
            del(i);
            for(j = r[i]; j != i; j = r[j]){
                del(j);
            }
            if(dfs(ct+ 1))  return true;
            for(j = l[i]; j != i; j = l[j]){
                resume(j);
            }
            resume(i);
        }
        return false;
    }

}dlx;


double getdis(point a, point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
void findro(int i, int j, double r){
    double x, y, xx, yy, d;
    double gg;
    if(fabs(dis[i][j]) < eps){
        ro[++cnt] = p[i];
    }
    else if(fabs(dis[i][j] - 2.0 * r) < eps){
        ro[++cnt] = point((p[i].x + p[j].x) / 2.0, (p[i].y + p[j].y) / 2.0);
    }
    else if(dis[i][j]  <= 2.0 *r - eps){
        x = (p[i].x + p[j].x) / 2.0;  y = (p[i].y + p[j].y) / 2.0;
        xx = (p[i].x - p[j].x) / 2.0; yy = (p[i].y - p[j].y) / 2.0;

        gg = sqrt(r * r - xx *xx - yy * yy)/dis[i][j] ;

        ro[++cnt].x = (p[j].y-p[i].y) * gg + x;
        ro[cnt].y = (p[i].x-p[j].x)*gg+y;
        ro[++cnt].x =(p[i].y - p[j].y)*gg + x;
        ro[cnt].y = (p[j].x-p[i].x)*gg+y;
    }
}
bool gao(double mid){
    int i, j, k;
    cnt = 0;
    dlx.init(n);
    for(i = 1; i <= n; i++){
        for(j = i; j <= n; j++){
            findro(i, j, mid );
        }
    }
    mid *= mid;
    for(i = 1; i <= cnt; i++){
        cover[i] = 0;
        for(j = 1; j <= n; j++){
            cover[i] <<= 1;
            if(getdis(ro[i], p[j])  <= mid + eps){
                cover[i] |= 1;
            }
        }
    }
    for(i = 1; i <= cnt; i++){
        for(j = i+1; j <= cnt; j++){
            if((cover[i] | cover[j]) == cover[j])   break;
        }
        if(j <= cnt) continue;
        for(k = 0; k < n; k++){
            if(cover[i] & (1 << k)) dlx.add(i, k +1);
        }
    }
    return dlx.dfs(0);
}
int main(){
    int TC, i, j;
    double ans, low, high, mid;

    scanf("%d", &TC);
    while(TC--){
        scanf("%d%d", &n, &K);
        for(i = 1; i <= n; i++) p[i].scan();

        for(i = 1; i <= n; i++){
            dis[i][i] = 0;
            for(j = i + 1; j <= n; j++)
                dis[i][j] = dis[j][i] = sqrt(getdis(p[i], p[j]));
        }
        low = 0.0;  high = 15.0;
        while(low + eps < high){
            mid = (low + high) / 2;

            if(gao(mid)){
            //    printf("!!\n");
                ans = mid;  high = mid;
            }else {
                low = mid;
            }
        }
        printf("%f\n", ans );
    }

    return 0;
}
