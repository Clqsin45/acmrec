
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[20][50][252];
int dig[20], f[2521];
ll dfs(int c, int p, int r, bool lim) {
	if(c < 0) return (r % p == 0);
	if(!lim && ~dp[c][f[p]][r]) return dp[c][f[p]][r];
	int up = lim ? dig[c] : 9;
	ll ans = 0;
	for(int i = 0; i <= up; i++) {
		ans += dfs(c - 1, i ? p * i / __gcd(p, i) : p, c ? (r * 10 + i) % 252 : (r * 10 + i), lim && (i == up));
	}
	return lim ? ans : dp[c][f[p]][r] = ans;
}
ll solve(ll x) {
	int cnt = 0;
	for(; x; dig[cnt++] = x % 10, x /= 10);
	return dfs(cnt - 1, 1, 0, 1);
}
int main() {
	int T;
	ll x, y;
	memset(dp, -1, sizeof(dp));
	for(int i = 1, s = -1; i <= 2520; i++) {
		s += !(2520 % i);
		f[i] = s;
	}
	cin >> T;
	while(T--) {
		cin >> x >> y;
		cout << solve(y) - solve(x - 1) << endl;
	}
	return 0;
}
