#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define maxn 10005
struct point {
	double x, y;
	point() {};
	point(double _x, double _y) : x(_x) , y(_y) {};
	point operator -(point const &I) const {
		return point(x - I.x, y - I.y);
	}
}dots[maxn], ret1[maxn], ret2[maxn];
double mul(point a, point b, point c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
double dis(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool cmp(const point a, const point b) {
	if(fabs(mul(dots[0], a, b)) < eps) return dis(dots[0], a) < dis(dots[0], b) - eps;
	return mul(dots[0], a, b) >= -eps;
}
double cross(point a, point b, point c, point d) {
	return (a.x - b.x) * (c.y - d.y) - (a.y - b.y) * (c.x - d.x);
}
double cdis(point a, point b, point c) {
	point s(a - b), t(c - b);
	if(s.x * t.x + s.y * t.y < eps) return dis(b, c);
	s = (b - a), t = (c - a);
	if(s.x * t.x + s.y * t.y < eps) return dis(a, c);
	return fabs(mul(a, b, c) / dis(a, b));
}
double ccdis(point a, point b, point c, point d) {
	return min(min(cdis(a, b, c), cdis(a, b, d)), min(cdis(c, d, a), cdis(c, d, b)));
}
int graham(point *ret, int n) {
	int i, j, nt;
	point tmp;
	for(i = j = 0; i < n; i++) if(dots[i].x < dots[j].x - eps || (fabs(dots[i].x - dots[j].x) < eps && dots[i].y < dots[j].y)) j = i;
	tmp = dots[j]; dots[j] = dots[0]; dots[0] = tmp;
	sort(dots + 1, dots + n, cmp);
	for(nt = 0; nt < 3; nt++) ret[nt] = dots[nt];
	for(i = 3; i < n; i++) {
		while(nt > 1 && mul(ret[nt - 2], ret[nt - 1], dots[i]) <= eps) nt--;
		ret[nt++] = dots[i];
	}
	return nt;
}
int main() {
//	freopen("in", "r", stdin);
	int n, m;
	double x, y;
	point p, q, r, s;
	while(~scanf("%d%d", &n, &m) && (n || m)) {
		for(int i = 0; i < n; i++) {
			scanf("%lf%lf", &x, &y);
			dots[i] = point(x, y);
		}
		int nn = graham(ret1, n);
		for(int i = 0; i < m; i++) {
			scanf("%lf%lf", &x, &y);
			dots[i] = point(x, y);
		}
		int mm = graham(ret2, m);
		double ans = 1e10;
		int j = 1;
		for(int i = 0; i < nn; i++) {
			while(!(cross(ret1[i], ret1[(i + 1) % nn], ret2[j], ret2[(j - 1 + mm) % mm]) < -eps &&
					cross(ret1[i], ret1[(i + 1) % nn], ret2[(j + 1) % mm], ret2[j]) >= - eps)) j = (j + 1) % mm;
			ans = min(ans, ccdis(ret1[i], ret1[(i + 1) % nn], ret2[(j - 1 + mm) % mm], ret2[j]));
		}
		printf("%f\n", ans);
	}
	return 0;
}
