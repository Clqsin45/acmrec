#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctime>
#define MAXN 111111
#define MAXM 1122222
#define INF 1000000007
#define eps 1e-8
using namespace std;
int n;
typedef pair<int, int> PII;
vector<PII> g[66 * 66];
int num[66 * 66];
int in[66 * 66], out[66 * 66];
int fa[66 * 66], v[66 * 66];
int en[66 * 66][66 * 66];
int vis[222222], nv[222222];
int st[222222];
char s[211111][6];
int find(int x) {
    if(x == fa[x]) return x;
    int t = find(fa[x]);
    fa[x] = t;
    return t;
}
void join(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if(fx != fy) fa[fx] = fy;
}
int getc(char c) {
    if(c >= 'a' && c <= 'z') return c - 'a';
    if(c >= 'A' && c <= 'Z') return c - 'A' + 26;
    return c - '0' + 52;
}
int ind;
void dfs(int u, int eid) {
    for(int i = 0; i < g[u].size(); i++) {
        int tid = g[u][i].second;
        if(vis[tid]) {
            vis[tid] --;
            dfs(g[u][i].first, tid);
        }
    }
    if(eid) st[ind++] = eid;
}
int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < 66 * 66; i++) fa[i] = i;
    for(int i = 1; i <= n; i++) {
        scanf("%s", s[i]);
        int a = getc(s[i][0]);
        int b = getc(s[i][1]);
        int c = getc(s[i][2]);
        int id1 = a * 62 + b;
        int id2 = b * 62 + c;
        v[id1] = 1; v[id2] = 1;
        join(id1, id2);
        if(en[id1][id2] == 0) en[id1][id2] = i, g[id1].push_back(PII(id2, i));
        in[id2]++;
        out[id1]++;
        vis[en[id1][id2]]++;

    }
    int tmp = -1, flag = 0;
    for(int i = 0; i < 66 * 66; i++) {
        if(!v[i]) continue;
        if(tmp == -1) tmp = find(i);
        else {
            if(tmp != find(i)) {
                flag = 1;
                break;
            }
        }
    }
    int cnt = 0, src = -1;
    for(int i = 0; i < 66 * 66; i++) {
        if(!v[i]) continue;
        if(abs(in[i] - out[i]) >= 2) {
            flag = 1;
            break;
        } else if(abs(in[i] - out[i]) == 1) {
            cnt ++;
            if(out[i] - in[i] == 1) src = i;
        }
    }
    if(src == -1) src = tmp;
    if(flag) {
        printf("NO\n");
    } else if(cnt == 0 || cnt == 2) {
        dfs(src, 0);
        printf("YES\n");
        for(int i = ind - 1; i >= 0; i--) {
            int tid = st[i];
            if(i == ind - 1) printf("%s", s[tid]);
            else printf("%c", s[tid][2]);
        }
        printf("\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
