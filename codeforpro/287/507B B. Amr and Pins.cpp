#include <bits/stdc++.h>
using namespace std;

int main(){
    double x, xx, y, yy, r;
    double dis;
    cin >> r>> x>> y >> xx >> yy;

    dis = sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
   // cout<<dis<<endl;
    if(dis < r &&fabs(dis) > 1e-10){
        cout<<1<<endl;
        return 0;
    }
    cout<<ceil(dis/(2.0 * r))<<endl;
    return 0;
}
//8066 7339 19155 -90534 -60666

