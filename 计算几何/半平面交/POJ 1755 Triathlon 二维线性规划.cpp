#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define N 111
#define eps 1e-8
#define INF 1e6
int n, no, id;

int doublecmp(double x){
    if(fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

struct Point{
    double x, y;
    Point(){};
    Point(double xx, double yy): x(xx), y(yy){};

    void scan(){
        scanf("%lf%lf", &x, &y);
    }

    Point operator -(const Point &I)const{
        return Point(x - I.x, y - I.y);
    }
    double xmul(const Point &I) const{
        return x * I.y - y * I.x;

    }

    void print(){
        printf("%.10f %.10f\n", x, y  );
    }

}point[N];
struct Line{
    Point a, b;
    double angle;

    void getline(){
        a.scan();   b.scan();
        angle = atan2(b.y - a.y, b.x - a.x);
    }
    //ux + vy +w < 0 left
    void getline(double u, double v, double w){
        if(!doublecmp(u)){//ok
            a = Point(doublecmp(v) > 0, -w / v);   b = Point(doublecmp(v) < 0, -w / v);
        }
        else if(!doublecmp(v)){
            a = Point(-w / u, doublecmp(u) < 0); b = Point(-w / u, doublecmp(u) > 0);
        }
        else if(!doublecmp(w)) {    //OK
            a = Point(0, 0);    b = Point(-v, u);
        }
        else {
            if((doublecmp(u)>0)^(doublecmp(v)>0)^(doublecmp(w)>0)){
                a = Point(0, -w/v); b = Point(-w/u, 0);
            }
            else {
                a = Point(-w/u, 0);b = Point(0, -w/v);
            }
        }
         angle = atan2(b.y - a.y, b.x - a.x);
    }
    void getline(double x1, double y1, double x2, double y2){
        a = Point(x1, y1);  b = Point(x2, y2);
        angle = atan2(y2 - y1, x2 - x1);
    }

    bool parallel(const Line &I)const{
        return doublecmp((b-a).xmul(I.b-I.a)) == 0;
    }

    void print(){
        printf("!!!\n");
        a.print();  b.print();
    }
}line[N];

struct Person{
    int v1, v2, v3;
    Person(){};

    void GetInfor(){
       // double a, b, c;
        scanf("%d%d%d", &v1, &v2, &v3);
        //v1 = 1 / a; v2 = 1 / b;  v3 = 1/c;
    }
}man[N];
struct Line Q[N];


double xmul(Point a, Point b, Point c){
    return (b-a).xmul(c-a);
}


bool cmp(Line A, Line B){
    int d = doublecmp(A.angle-B.angle);
    if(d == 0){
        return doublecmp(xmul(A.a, B.a, B.b)) > 0;
    }
    return d < 0;
}
void unique(){
    int i, j = 0;
    for(i = 1; i <= no; i++){
        if(i == 1 || doublecmp(line[i].angle-line[i-1].angle) != 0) line[++j] = line[i];
    }
    no = j;
}

Point GetIntersection(Line A, Line B){
    double dot1 = xmul(B.a, A.b, A.a);
    double dot2 = xmul(A.b, B.b, A.a);
    Point p = Point((B.a.x*dot2+B.b.x*dot1) / (dot2+dot1), (B.a.y*dot2+B.b.y*dot1)/(dot1+dot2));
    return p;
}
bool OutPlane(Line A, Line x1, Line x2){
    Point p = GetIntersection(x1, x2);
    return doublecmp(xmul(A.a, p, A.b)) > 0;
}
/*
2
1 1 10000
2 2 9999
*/
bool HalfPlaneIntersection(void){
    int i, j;
    sort(line + 1, line + no+ 1, cmp);
    unique();
    int top = 1, bottle = 0;
    Q[0] = line[1]; Q[1] = line[2];
    for(i = 3; i <= no; i++){
            // 顶部交点不在当前平面内
        while(top > bottle && OutPlane(line[i], Q[top], Q[top-1])) top--;
            // 底部交点不在当前平面内
        while(top > bottle && OutPlane(line[i], Q[bottle], Q[bottle + 1]))  bottle ++;
        if(line[i].parallel(Q[top])) return false;
        Q[++top] = line[i];
    }
   //printf("yingying%d %d\n", top, bottle);
  //  Q[3].print();
    //顶部交点不在底部平面内
    while(top > bottle && OutPlane(Q[bottle], Q[top], Q[top-1])) top--;
        //底部交点不在顶部平面内
    while(top > bottle && OutPlane(Q[top], Q[bottle], Q[bottle + 1])) bottle ++;

    Q[++top] = Q[bottle];
    id = 0;
    for(i = bottle; i < top; i++){
        point[++id] = GetIntersection(Q[i], Q[i+1]);
    }
    return id >= 3;
}

bool gao(int pos){
    int i;  no = 0;
    double x, y;
    double dtv1, dtv2, dtv3;
    for(i = 1; i <= n; i++){
        if(i == pos)    continue;
        if(man[pos].v1 <= man[i].v1 &&  man[pos].v2 <= man[i].v2 && man[pos].v3 <= man[i].v3)   return false;
        dtv1 = 10000.0 / man[pos].v1 - 10000.0 / man[i].v1;
        dtv2 = 10000.0 / man[pos].v2 - 10000.0 / man[i].v2;
        dtv3 = 10000.0 / man[pos].v3 - 10000.0 / man[i].v3;
       // dtv1 = -dtv1;dtv2 = -dtv2;dtv3 = -dtv3;
     //  printf("!!!!%f\n", dtv3);
            line[++no].getline(dtv1, dtv2, dtv3);
    }
//    for(i = 1; i <= no; i++){
//        line[i].print();
//    }

    line[++no].getline(0, 0, INF, 0);
    line[++no].getline(INF, 0, INF, INF);

    line[++no].getline(INF, INF , 0, INF);
    line[++no].getline(0, INF , 0,0);

    return (HalfPlaneIntersection()); //    return GetArea();
 //   return false;
}

int main(){
    int i, j;
    while(scanf("%d", &n) != EOF){

        for(i = 1; i <= n; i++){
            man[i].GetInfor();
        }
        if(n == 1){
            printf("Yes\n");
            continue;
        }
        for(i = 1; i <= n; i++){
         //   if(gao(i)) printf("%d\n", i);
           printf("%s\n", gao(i) ?  "Yes": "No");
        }
    }
    return 0;
}
