#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

#define N 112
#define M 44000
#define LL __int64
#define INF 0x3f7f7f7f
int head[N], d[N], cur[N], st[M], s, e, no;
int in[55], out[55];
int ti[55], ct[55];
vector<int>v;

struct point{
	int u, v, flow, next;
	point(){};
	point(int x, int y, int z, int w):u(x), v(y), next(z), flow(w){};
}p[M];

void init(){
	memset(head, -1, sizeof(head));
	v.clear();
	no = 0;
}
void add(int x, int y, int z){
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
			if(p[i].flow && d[y] < 0){
				d[y] = d[x] + 1;
				if(y == e) return true;
				q.push(y);
			}
		}
	}
	return false;
}

int dinic(){

	int top, i, x = s, maxflow = 0, nowflow, loc;
	while(bfs()){
		for(i = s; i <= e; i ++) cur[i] = head[i];
		top = 0;
		while(true){
			if(x == e){
				nowflow = INF;
				for(i = 0; i < top; i++){
					if(nowflow > p[st[i]].flow){
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
				if(p[i].flow && d[p[i].v] == d[x] + 1) break;
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


int main(void)
{
    int i, j,n, m, temp, x, all, tt, begin;

    while(scanf("%d%d", &n, &m)!= EOF){
        init(); s = 0;  e = 2 * m + 1;
        all = (1 << n) - 1;
        bool flag;
        for(i = 1; i <= m; i++){
            flag = true;
            scanf("%d", &ct[i]);
            add(i, i + m, ct[i]);
            for(j = 1, temp = 0, tt = 0; j <= n; j++){
                scanf("%d", &x);
                if(x == 1) {
                    tt = tt * 2 + x;
                    flag = false;
                }
                else tt <<= 1;
                if(x >= 1)  x = 0;
                else x = 1;
                temp = temp * 2 + x;
            }
            in[i] = temp;   ti[i] = tt;
            if(flag)   {
                add(s, i, INF);
            }
            for(j = 1, temp = 0; j <= n; j++){
                scanf("%d", &x);
                temp = temp * 2 + x;
            }
            out[i] = temp;

            if(temp == all) add(i + m, e, INF);
        }
        begin = no;
        for(i = 1; i <= m; i++){
            for(j = 1; j <= m; j++){
               // printf("%d %d %d %d\n", i, j, in[j], out[i]);
                if(i == j || (in[j] & out[i]) || (ti[j] & out[i]) != ti[j])continue;
                add(i + m, j, INF);
            }
        }

//        for(i = s; i <= e; i++){
//            printf("%d:\n", i);
//
//            for(j = head[i]; j != -1; j = p[j].next){
//                printf("%d %d\n", p[j].v, p[j].flow);
//            }
//        }
        printf("%d ", dinic());
        for(i = begin + 1; i < no; i += 2){
            if(p[i].flow)   v.push_back(i);
        }
        printf("%d\n", v.size());
        for(i = 0; i < v.size(); i++){
            printf("%d %d %d\n", p[v[i]].v - m, p[v[i]].u, p[v[i]].flow);
        }

    }
    return 0;
}
