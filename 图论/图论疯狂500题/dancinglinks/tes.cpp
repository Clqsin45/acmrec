#include<cstdio>
#include<cstring>
#include<cmath>
#define MAXM 20
#define MAXN 10000
#define EPS 1e-8
#define INF 0x7FFFFFFF
int L[MAXN], R[MAXN], U[MAXN], D[MAXN];
int S[MAXN], H[MAXN], C[MAXN], B[MAXN];
double dis[MAXM][MAXM];
bool vis[MAXM];
struct Point {
    double x, y;
};
Point p[MAXM], center[MAXN];
int n, m, size;
inline int dbcmp(double x, double y) {
    if (fabs(x - y) < EPS)
        return 0;
    return x > y ? 1 : -1;
}
inline double DIS(Point a, Point b) {
    double x, y;
    x = b.x - a.x;
    y = b.y - a.y;
    return x * x + y * y;
}
void Init() {
    int i;
    for (i = 0; i <= n; i++) {
        R[i] = i + 1;
        L[i + 1] = i;
        U[i] = D[i] = i;
        S[i] = 0;
    }
    R[n] = 0;
    size = n + 1;
}
void Link(int r, int c) {
    D[size] = D[c];
    U[size] = c;
    U[D[c]] = size;
    D[c] = size;
    if (H[r] < 0)
        H[r] = L[size] = R[size] = size;
    else {
        L[size] = H[r];
        R[size] = R[H[r]];
        L[R[H[r]]] = size;
        R[H[r]] = size;
    }
    S[c]++;
    C[size++] = c;
}
int A() {
    int i, j, k, res;
    memset(vis, false, sizeof(vis));
    for (res = 0, i = R[0]; i; i = R[i]) {
        if (vis[i])
            continue;
        res++;
        for (j = D[i]; j != i; j = D[j]) {
            for (k = R[j]; k != j; k = R[k])
                vis[C[k]] = true;
        }
    }
    return res;
}
void Remove(int c) {
    int i;
    for (i = D[c]; i != c; i = D[i]) {
        L[R[i]] = L[i];
        R[L[i]] = R[i];
    }
}
void Resume(int c) {
    int i;
    for (i = D[c]; i != c; i = D[i])
        L[R[i]] = R[L[i]] = i;
}
bool Dance(int now) {
    if (now + A() > m)
        return false;
    if (R[0] == 0)
        return true;
    int i, j, temp, c;
    for (temp = INF,i = R[0]; i; i = R[i]) {
        if (temp > S[i]) {
            temp = S[i];
            c = i;
        }
    }
    for (i = D[c]; i != c; i = D[i]) {
        Remove(i);
        for (j = R[i]; j != i; j = R[j])
            Remove(j);
        if (Dance(now + 1))
            return true;
        for (j = L[i]; j != i; j = L[j])
            Resume(j);
        Resume(i);
    }
    return false;
}
void Center(int i, int j, double r, int &cnt) {
    double x0, y0, x1, y1, d;
    if (dbcmp(dis[i][j], 0) == 0)
        center[cnt++] = p[i];
    else if (dbcmp(dis[i][j], 2 * r) == 0) {
        center[cnt].x = (p[i].x + p[j].x) / 2;
        center[cnt++].y = (p[i].y + p[j].y) / 2;
    } else if (dbcmp(dis[i][j], 2 * r) < 0) {
        x0 = (p[i].x + p[j].x) / 2;
        y0 = (p[i].y + p[j].y) / 2;
        x1 = (p[i].x - p[j].x) / 2;
        y1 = (p[i].y - p[j].y) / 2;
        d = sqrt(r * r - x1 * x1 - y1 * y1) / dis[i][j];
        center[cnt].x = (p[j].y - p[i].y) * d + x0;
        center[cnt++].y = (p[i].x - p[j].x) * d + y0;
        center[cnt].x = (p[i].y - p[j].y) * d + x0;
        center[cnt++].y = (p[j].x - p[i].x) * d + y0;
    }
}
bool OK(double r) {
    int i, j, k, cnt;
    Init();
    for (cnt = 0, i = 1; i <= n; i++) {
        for (j = i; j <= n; j++)
            Center(i, j, r, cnt);
    }
    for (r *= r, i = 0; i < cnt; i++) {
        H[i] = -1;
        B[i] = 0;
        for (j = 1; j <= n; j++) {
            B[i] <<= 1;
            if (dbcmp(DIS(center[i], p[j]), r) <= 0)
                B[i] |= 1;
        }
    }
    for (i = 0; i < cnt; i++) {
        for (j = i + 1; j < cnt; j++) {
            if ((B[i] | B[j]) == B[j])
                break;
        }
        if (j == cnt) {
            for (k = 0; k < n; k++) {
                if (B[i] & (1 << k))
                    Link(i, k + 1);
            }
        }
    }
    return Dance(0);
}
int main() {
    int T, i, j;
    double low, high, mid;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        for (i = 1; i <= n; i++) {
            dis[i][i] = 0;
            for (j = i + 1; j <= n; j++)
                dis[i][j] = dis[j][i] = sqrt(DIS(p[i], p[j]));
        }
        for (low = 0, high = 15; dbcmp(low, high) < 0;) {
            mid = (low + high) / 2;
            if (OK(mid))
                high = mid;
            else
                low = mid;
        }
        printf("%lf\n", low);
    }
    return 0;
}
