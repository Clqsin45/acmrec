#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define N 104
#define M 14000
#define LL __int64
#define INF 0x3f7f7f7f
#define eps 1e-8
vector<int>v;
int head[N], d[N], cur[N], st[M], s, e, no, n, m;
int f[N];
bool vis[N];
struct point{
	int u, v, next;
	double flow;
	point(){};
	point(int x, int y, int z, double w):u(x), v(y), next(z), flow(w){};
}p[M];
struct record{
    int x, y;
}rec[1004];
void init(){
	memset(head, -1, sizeof(head));
	no = 0;
}
void add(int x, int y, double z){
	p[no] = point(x, y, head[x], z);	head[x] = no++;
	p[no] = point(y, x, head[y], 0);	head[y] = no++;
}
bool bfs(){

	memset(d, -1, sizeof(d));
	queue<int>q;
	d[s] = 0;
	int i , x, y;
	q.push(s);
	while(!q.empty()){
		x = q.front();
		q.pop();

		for(i = head[x]; i != -1; i = p[i].next){
			y = p[i].v;
			if(p[i].flow > eps && d[y] < 0){
				d[y] = d[x] + 1;
				if(y == e) return true;
				q.push(y);
			}
		}
	}
	return false;
}

double dinic(){

	int top, i, x = s, loc;
	double maxflow = 0.0, nowflow;
	while(bfs()){
		for(i = s; i <= e; i ++) cur[i] = head[i];
		top = 0;
		while(true){
			if(x == e){
				nowflow = 1e9;
				for(i = 0; i < top; i++){
					if(nowflow > p[st[i]].flow + eps){
						loc = i;
						nowflow = p[st[i]].flow;
					}
		}
				for(i = 0; i < top; i++){
					p[st[i]].flow -= nowflow;
					p[st[i]^1].flow += nowflow;
				}
				maxflow += nowflow;
				top = loc; x = p[st[top]].u;
			}
			for(i = cur[x]; i != -1; i = p[i].next)
				if(p[i].flow > eps&& d[p[i].v] == d[x] + 1) break;
			cur[x] = i;
			if(i != -1){
				st[top++] = i;
				x = p[i].v;
			}
			else {
				if(!top) break;
				d[x] = -1;
				x = p[st[--top]].u;
			}
		}
	}
	return maxflow;
}

void build(double g){
    init();
    int i;
    for(i = 1; i <= n; i++) {
        add(s, i, m * 1.0);
        add(i, e, m * 1.0 + 2.0 * g -1.0* f[i]);
    }

    for(i = 1; i <= m; i++){
        add(rec[i].x, rec[i].y, 1.0);
        add(rec[i].y, rec[i].x, 1.0);
    }

}

void dfs(int x){
    int i, y;

    for(i = head[x]; i != -1; i = p[i].next){
        if(p[i].flow > eps && !vis[p[i].v]){
            vis[p[i].v] = true; dfs(p[i].v);
           // printf("~~%d\n", p[i].v);
            v.push_back(p[i].v);
        }
    }
}
int main(void)
{
   freopen("in.txt", "r", stdin);
    int  x, y, i;
    double ans, low, high, mid;

    while(scanf("%d%d", &n, &m) != EOF){
        memset(f, 0, sizeof(f));

        for(i = 1; i <= m; i++){
            scanf("%d%d", &rec[i].x, &rec[i].y);
            f[rec[i].x] ++;    f[rec[i].y] ++;
        }
        s = 0;  e = n + 1;
        init();
        low = 0.0;  high = 2.0 * m;
        ans =10000.0;
        double lim = 1.0 / n / n / 2;
        while(low + lim < high){
            mid = (low + high) / 2.0;
            build(mid);
            double temp = dinic();
         //  printf("%f %f\n", mid, temp);
            if((n * m * 1.0  - temp)/2.0 < eps){
                high = mid;
            }
            else low = mid;
        }
        //printf("%f\n", low);
        build(low);     dinic();

        memset(vis, 0, sizeof(vis));
        vis[s] = true;
        v.clear();
       dfs(s);

        if(v.size() == 0)   {
            printf("%d\n%d\n", 1, 1);
            continue;
        }
        printf("%d\n", v.size());
        sort(v.begin(), v.end());
        for(i = 0; i < v.size(); i++){
            printf("%d\n",  v[i]);
        }

    }

    return 0;
}
