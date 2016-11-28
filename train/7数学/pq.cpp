#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
map<int, int>M, P;
map<int, int>::iterator it;
vector<int>V;
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("pq.txt", "w", stdout);
	int n, b;
	while(cin >> n >> b) {
		double t = 0;
		M.clear(); P.clear(); V.clear();
		for(int i = 1; i <= n; i++) t += log10(i);
		ll digit = (ll)(t / log10(b)) + 1;
		for(int i = 2; i <= (int)sqrt(b) && b > 1; i++)
			while(b % i == 0) M[i]++, b /= i;
		if(b > 1) M[b]++;
		for(it = M.begin(); it != M.end(); it++) V.push_back(it -> first);
		for(int i = 2; i <= n; i++) {
			int u = i;
			for(int j = 0; j < V.size() && u > 1; j++) {
				while(u % V[j] == 0) P[V[j]]++, u /= V[j];
			}
		}
		int ans = 0x7fffffff;
		for(it = M.begin(); it != M.end(); it++) {
			ans = min(ans, P[it -> first] / it -> second);
		}
		cout << ans << " " << digit << endl;
	}
	return 0;
}
