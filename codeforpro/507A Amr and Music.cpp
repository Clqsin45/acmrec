#include <bits/stdc++.h>
using namespace std;

#define N 105
vector<int>ans;
struct point{
    int cost, no;
    point(){};
    point(int x, int y) : cost(x), no(y){};
}p[N];
bool cmp(point a, point b){
    return a.cost < b.cost;
}
int main(){
    int n, k, x, i;
    cin >> n >> k;
    for(i = 1; i <= n; i++){
        cin >>x;
        p[i] = point(x, i);
    }
    int cnt = 0;
    sort(p + 1, p +n +1, cmp);
    i = 1;
    while(k >= p[i].cost && i <= n){
        ans.push_back(p[i].no);
        k -= p[i].cost;
        i++;
    }
    n = ans.size();
    printf("%d\n", n);
    for(i = 0; i < n; i++){
        printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;

}
