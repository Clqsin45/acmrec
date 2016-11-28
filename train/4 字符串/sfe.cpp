#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>.h
#include <algorithm>
#define x first
#define y second
#define mk make_pair
#define pb push_back
using namespace std;
typedef pair<int, int>II;
const int SIZE = 510;
const int p1 = 26;
const int q1 = 3577;
const int p2 = 3297;
const int q2 = 4589;
char s[SIZE][SIZE];
int A[SIZE][SIZE];
vector<II>to[4600];
int N, M;
II node1, node2;
void Read()
{
    scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%s", s[i] + 1);
}
void Init(int n)
{
	int v = 1;
	for (int i = 1; i <= n - 1; i++) v *= p1, v %= q1;

	for (int i = 1; i <= N; i++)
	{
		int now = 0;
		for (int j = 1; j <= M; j++)
		{
			if (j > n) now = (now - v * (s[i][j - n] - 'a') % q1 + q1) % q1;
			now = now * p1 % q1 + (s[i][j] - 'a');
			now %= q1;

			if (j >= n) A[i][j - n + 1] = now;
		}
	}
}
bool cp(int x0, int y0, int x1, int y1, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (s[x0 + i][y0 + j] != s[x1 + i][y1 + j]) return false;
	return true;
}
bool check(int n)
{
	Init(n);
	for (int i = 0; i < q2; i++) to[i].clear();

	int v = 1;
	for (int i = 1; i <= n - 1; i++) v *= p2, v %= q2;

	for (int j = 1; j <= M - n + 1; j++)
	{
		int now = 0;
		for (int i = 1; i <= N; i++)
		{
			if (i > n) now = (now - v * A[i - n][j] % q2 + q2) % q2;
			now = now * p2 % q2 + A[i][j];
			now %= q2;

			if (i >= n)
			{
				if (to[now].size())
				{
					for (int k = 0; k < (int)to[now].size(); k++)
						if (cp(to[now][k].x, to[now][k].y, i - n + 1, j, n))
						{
							node1 = to[now][k];
							node2 = mk(i - n + 1, j);
							return true;
						}
				}
				to[now].pb(mk(i - n + 1, j));
			}
		}
	}
	return false;
}
void Solve()
{
	int l = 1, r = min(N, M), ans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}

	printf("%d\n", ans);

	if (ans)
	{
		printf("%d %d\n", node1.x, node1.y);
		printf("%d %d\n", node2.x, node2.y);
	}
}
int main()
{
	Read();
	Solve();
	return 0;
}
