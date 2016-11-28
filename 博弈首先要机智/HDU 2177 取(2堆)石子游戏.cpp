#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
const int N = 1000005;

struct point{
    int x, y;
    point(){};
    point(int xx, int yy) {x = xx, y = yy;};

    bool operator==(const point &I)const{
        return x == I.x && y == I.y;
    }

    bool operator < (const point &I)const{
        if(x == I.x) return y  < I.y;
        return x < I.x;
    }
}p[N];
map<struct point, bool>f;
vector<struct point>ans;



int findvalx(int x){
    int low, high, mid;
    low = 0; high = 381966;
    while(low <= high){
        mid = (low + high ) /2;
        if(p[mid].x == x)   return mid;
        if(p[mid].x > x){
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return -1;
}

int findvaly(int x){
    int low, high, mid;
    low = 0; high = 381966;
    while(low <= high){
        mid = (low + high ) /2;
        if(p[mid].y == x)   return mid;
        if(p[mid].y > x){
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return -1;
}
void init(){
    int i, temp;
    for(i = 0; i <= 1000000; i++){
        temp = (int)(i*(1.0+sqrt(5.0))/2.0);
        p[i] = point(temp, temp +i);
        //printf("%d %d\n", temp, temp + i);
        if(temp + i > 1000000)  break;
    }
//   printf("!!!%d\n", i);
}
int main(){
    int n, m, k, i, j, ansx, ansy;
    init();
    while(scanf("%d%d", &n, &m) && (n || m)){
        i = n;  j = m;
        k = j - i;
        int temp = p[k].x;
        if(i == temp)   {
            printf("0\n");
        }
        else{
            printf("1\n");
            ans.clear();    f.clear();
            if(i > p[k].x && j > p[k].y &&  (i-p[k].x == j-p[k].y)){
                ansx = p[k].x;  ansy = p[k].y;
                ans.push_back(point(ansx, ansy));
                f[point(ansx, ansy)] = true;

            }
            int temp = findvalx(i);
            if(temp != -1){
                if(p[temp].y < j){
                    ansx = i;   ansy = p[temp].y;
                    if(f[point(ansx, ansy)]);
                    else{
                        ans.push_back(point(ansx, ansy));
                        f[point(ansx, ansy)] = true;
                    }
                }
            }
            temp = findvalx(j);
            if(temp != -1 && i > p[temp].y){
                ansx= p[temp].x; ansy = p[temp].y;
                if(f[point(ansx, ansy)]);
                else{
                    ans.push_back(point(ansx, ansy));
                    f[point(ansx, ansy)] = true;
                }
            }
            temp = findvaly(j);
            if(temp != -1){
                if(p[temp].x <i){
                    ansx = p[temp].x;   ansy = j;
                    if(f[point(ansx, ansy)]);
                    else{
                        ans.push_back(point(ansx, ansy));
                        f[point(ansx, ansy)] = true;
                    }
                }
            }
            temp = findvaly(i);
            if(temp != -1 &&  j > p[temp].x){
                ansx = p[temp].x;   ansy = i;
                if(f[point(ansx, ansy)]);
                else{
                    ans.push_back(point(ansx, ansy));
                    f[point(ansx, ansy)] = true;
                }
            }
            for(i = 0; i < ans.size(); i++){
                printf("%d %d\n", ans[i].x, ans[i].y);
            }
        }
    }
    return 0;
}
