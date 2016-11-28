#define N 204
#define M 4004
#define INF 0x3f3f3f3f

struct point
{
    int u, v, flow, next;
}p[M];
int in[N], out[N], head[N], d[N], cur[N], st[M], s, e, no;
void init()
{
    memset(in, 0, sizeof(in));  memset(out, 0, sizeof(out));
    memset(head, -1, sizeof(head)); no = 0;
}

void add(int x, int y, int z)
{
    p[no].u = x; p[no].v = y;   p[no].flow = z;
    p[no].next = head[x];   head[x] = no++;
    p[no].u = y;    p[no].v= x; p[no].flow = 0;
    p[no].next= head[y];    head[y] = no++;
}

bool bfs()
{
    int i, x, y;
    queue<int>q;
    memset(d, -1, sizeof(d));
    d[s] = 0;   q.push(s);
    while(!q.empty())
    {
        x=  q.front();  q.pop();
        for(i = head[x]; i != -1; i = p[i].next)
        {
            if(p[i].flow && d[y = p[i].v] < 0)
            {
                d[y] = d[x] + 1;
                if(y == e)  return true;
                q.push(y);
            }
        }
    }
    return false;
}

int dinic()
{
    int i, x= s, nowflow, maxflow = 0, top, loc;
    while(bfs())
    {
        top = 0;
        for(i = s; i <= e; i++) cur[i] = head[i];
        while(true)
        {
            if(x == e)
            {
                nowflow = INF;
                for(i = 0; i < top; i++)
                {
                    if(p[st[i]].flow < nowflow)
                    {
                        nowflow = p[st[i]].flow;
                        loc = i;
                    }
                }
                maxflow += nowflow;
                for(i = 0 ; i < top; i++)
                {
                    p[st[i]].flow -= nowflow;
                    p[st[i] ^ 1].flow += nowflow;
                }
                top = loc;  x = p[st[top]].u;
            }
            for(i = cur[x]; i != -1; i = p[i].next)
            {
                if(p[i].flow && d[p[i].v] == d[x] + 1)  break;
            }
            cur[x] = i;
            if(i != -1)
            {
                st[top++] = i;  x = p[i].v;
            }
            else
            {
                if(!top )   break;
                d[x] = -1;   x = p[st[--top]].u;
            }
        }
    }
    return maxflow;
}
int main()
{
    int TC, n, m, x, y, i, type, sum = 0;
    bool flag;
    scanf("%d", &TC);
    while(TC--)
    {
        init(); flag = false;
        sum = 0;
        scanf("%d%d", &n, &m);
        s = 0;  e = n + 1;
        while(m--)
        {
            scanf("%d%d%d", &x, &y, &type);
            out[x]++ ;  in[y] ++;
            if(type)    continue;
            add(x, y, 1);
        }
        for(i = 1; i <= n; i++)
        {
            if((in[i] - out[i]) & 1)
            {
                flag = true;    break;
            }
            else
            {
                x = in[i] - out[i];
                if(x < 0)
                {
                    sum+= (-(x/2));
                    add(s, i, -x / 2);
                }
                else if(x == 0) continue;
                else add(i, e, x / 2);
            }
        }
        if(flag)
        {
            printf("impossible\n"); continue;
        }
        if(sum == dinic())  printf("possible\n");
        else printf("impossible\n");
    }
	return 0;
}
