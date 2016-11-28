#include <bits/stdc++.h>
using namespace std;
struct point{
    int x, y;
    point(){};
    point(int xx, int yy){x = xx, y = yy;};
    bool operator==(const point &I)const{
        return I.x == x&& I.y == y;
    }
    bool operator<(const point &I)const{
        if( I.x == x)return  y < I.y;
        return x <I.x;
    }
};

map<struct point, bool> f;

int main(){
    int ans, i, x, y, temp, a, b, n;
    ans = 0;
    f.clear();
    cin >> n >> a >> b;
    while(n--){
        cin >> x >> y;
        x -= a; y-= b;
        temp = __gcd(x, y);
        //cout<<temp<<endl;
        x /= temp;  y /= temp;
        if(f[point(x, y)] )  continue;
        f[point(x, y)] = true;
        ans ++;
    }
    cout<<ans<<endl;
    return 0;
}
