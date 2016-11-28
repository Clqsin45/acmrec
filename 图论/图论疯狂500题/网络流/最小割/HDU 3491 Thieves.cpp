
void init(){
	memset(head, -1, sizeof(head));
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

int main(){
int S, T, TC, i, j, x, y, z, n, m;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d%d%d%d", &n, &m, &S, &T);
		init();
		s = 0;	e = 2 * n + 1;
		for(i = 1; i <= n; i++){
			scanf("%d", &x);
			if(i == S || i == T){
				add(i, i + n, INF);
			}
			else add(i, i + n, x);
		}
		while(m--){
			scanf("%d%d", &x, &y);
			add(x + n, y, INF);
			add(y + n, x, INF);
		}
		add(s, S, INF);
		add(T, e, INF);
		printf("%d\n", dinic());
	}
}
