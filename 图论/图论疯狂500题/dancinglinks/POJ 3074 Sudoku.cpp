#include<cstdio>
#include<cstring>
#include <algorithm>
#include<ctype.h>
using namespace std;

#define N 1000
#define T 400000
#define INF 0x3f3f3f3f
char map[100];
char dit[1001];
int inmap[1000], ans, pos[1000];
struct DLX{
	int r[T], u[T], l[T], d[T];
	int cnt[344], col[T], head[N], row[T];
	int n, id;

	void init(int nt){
		this->n = nt;
		int i;
		for(i = 0; i <= n; i++){
			d[i] = u[i] = i;
			l[i] = i - 1;	r[i] = i + 1;
		}
		id = n + 1;
		r[n] = 0;	l[0] = n;

		memset(cnt, 0, sizeof(cnt));
		memset(head, -1, sizeof(head));
	}

	void add(int rr, int cc){
		d[id] = cc;	u[id] = u[cc];
		d[u[cc]] = id;	u[cc] = id;

		if(head[rr] < 0){
			head[rr] = l[id] = r[id] = id;
		}
		else {
			l[id] = head[rr];	r[id] = r[head[rr]];
			l[r[head[rr]]] = id;	r[head[rr]] = id;
			head[rr] = id;
		}
		cnt[cc] ++;	col[id] = cc;
		row[id] = rr;
		id ++;
	}

	void remove(int x){
		int i, j;
		l[r[x]] = l[x];	r[l[x]] = r[x];

		for(i = d[x]; i != x; i = d[i]){
			for(j = r[i]; j != i; j = r[j]){
				cnt[col[j]] --;
				u[d[j]] = u[j];	d[u[j]] = d[j];
			}
		}
		return ;
	}

	void resume(int x){
		int i, j;
		for(i = u[x]; i != x; i = u[i]){
			for(j = l[i]; j != i; j = l[j]){
				cnt[col[j]] ++;
				d[u[j]] = j;	u[d[j]] = j;
			}
		}
		l[r[x]] = x;	r[l[x]] = x;
	}

	bool  dfs(){
		if(r[0] == 0) {
            int i;
//printf("!!\n");
            for(i = 1; i <= ans; i++){
                map[pos[inmap[i]]] = dit[inmap[i]]+'0';
            }
            printf("%s\n", map);
            return true;
		}
		int idx, temp = INF, i, j;

		for(i = r[0]; i != 0; i = r[i]){
			if(cnt[i] < temp){
				temp = cnt[i];
				idx = i;
			}
		}
//printf("!!%d %d\n",  temp, idx);
	//	printf("%d\n", idx);
		if(temp == 0) return false;
		remove(idx);
		for(i = d[idx]; i != idx; i = d[i]){
            inmap[++ans] = row[i];
			for(j = r[i]; j != i; j = r[j]){
				remove(col[j]);
			}
            dfs();
			for(j = l[i]; j != i; j = l[j]){
				resume(col[j]);
			}
            --ans;
		}
		resume(idx);return false;
	}

}dlx;

bool vis[344];

int main(){
    //freopen("in.txt", "r", stdin);
    int i , j, k, now, id, loc, a, b, c, d;
    while(scanf("%s", map) && map[0] != 'e'){

        memset(vis, false, sizeof(vis));
        dlx.init(324);
        now = 0;    id = 0; ans = 0;
        for(i = 0, now = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                if(isdigit(map[now])){
                    loc = i / 3 * 3 + j / 3 ;
                    a = (i * 9 + j + 1);  b = 81 + i * 9 + map[now] - '0';
                    c = 162 + j * 9 + map[now] - '0';  d= 243 + loc * 9 + map[now] -'0';
                    vis[a] = vis[b] = vis[c] = vis[d] = true;
                    dlx.add(++id, a);
                    dlx.add(id, b);
                    dlx.add(id, c);
                   // printf("!!!!! %d\n", b);
                    dlx.add(id, d);
                    pos[id] = a-1;    dit[id] = map[now] - '0';
                }
                now ++;
            }
        }
        for(i = 0, now = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                if(!isdigit(map[now])){
                    for(k = 1; k <= 9; k++){
                        loc = i / 3 * 3 + j / 3 ;
                        a = (i * 9 + j + 1);  b = 81 + i * 9 + k;
                        c = 162 + j * 9 + k;  d= 243 + loc * 9 + k;
                        if( vis[b] || vis[c] || vis[d]) continue;
                        dlx.add(++id, a);
                        dlx.add(id, b);
                        dlx.add(id, c);
                        dlx.add(id, d);
  //                      if(i == 0) printf("%d %d %d %d\n" , i, j, k, a);
                        pos[id] = a-1;    dit[id] = k;
                    }
                }
                now ++;
            }
        }
       // printf("%d\n", now);
       // printf("%d\n", id);

        dlx.dfs();
    }
    return 0;
}
