#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
#define N  20015
#define eps 1e-10



int n, id, no;
struct Point{
    double x, y;
    Point(){};
    Point(double xx, double yy): x(xx), y(yy){};

    void scan(){
        scanf("%lf%lf", &x, &y);
    }

    Point operator +(const Point &I)const{
        return Point(x+I.x, y + I.y);
    }
    Point operator -(const Point &I)const{
        return Point(x - I.x, y - I.y);
    }
    Point operator /(const double k)const{
        return Point(x / k, y / k);
    }
    Point operator *(const double k)const{
        return Point(x * k, y * k);
    }

    Point ContraRotate(){
        return Point(-y, x);
    }

    double mo(){
        return sqrt(x*x+y*y);
    }

    double xmul(const Point &I) const{
        return x * I.y - y * I.x;
    }

    void print(){
        printf("%f %f\n", x, y  );
    }

}point[N], pt[N];
struct Line{
    Point a, b;
    double angle;
    Line(){};
    Line(Point aa, Point bb): a(aa), b(bb){angle = atan2(bb.y-aa.y, bb.x-aa.x);};

    void getline(){
        a.scan();   b.scan();
        angle = atan2(b.y - a.y, b.x - a.x);
    }

    void getline(double x1, double y1, double x2, double y2){
        a = Point(x1, y1);  b = Point(x2, y2);
        angle = atan2(y2 - y1, x2 - x1);
    }

    void print(){
        printf("!!!\n");
        a.print();  b.print();
    }
}line[N];

struct Line Q[N];


int doublecmp(double x){
    if(fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

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
    for(i = 1; i <= n; i++){
        if(i == 1 || doublecmp(line[i].angle-line[i-1].angle)) line[++j] = line[i];
    }
    n = j;
}

Point GetIntersection(Line A, Line B){
    double dot1 = xmul(B.a, A.b, A.a);
    double dot2 = xmul(A.b, B.b, A.a);
    Point p = Point((B.a.x*dot2+B.b.x*dot1) / (dot2+dot1), (B.a.y*dot2+B.b.y*dot1)/(dot1+dot2));
    return p;
}
bool OutPlane(Line A, Line x1, Line x2){
    Point p = GetIntersection(x1, x2);
    return doublecmp(xmul(p, A.a, A.b)) < 0;
}
void HalfPlaneIntersection(void){
    int i, j;
    sort(line + 1, line + n + 1, cmp);
    unique();
    int top = 1, bottle = 0;
    Q[0] = line[1]; Q[1] = line[2];
    for(i = 3; i <= n; i++){
            // 顶部交点不在当前平面内
        while(top > bottle && OutPlane(line[i], Q[top], Q[top-1])) top--;
            // 底部交点不在当前平面内
        while(top > bottle && OutPlane(line[i], Q[bottle], Q[bottle + 1]))  bottle ++;
        Q[++top] = line[i];
    }

    //顶部交点不在底部平面内
    while(top > bottle && OutPlane(Q[bottle], Q[top], Q[top-1])) top--;
        //底部交点不在顶部平面内
    while(top > bottle && OutPlane(Q[top], Q[bottle], Q[bottle + 1])) bottle ++;

    Q[++top] = Q[bottle];
    id = 0;
//    for(i = bottle; i <= top; i++) {
//        Q[i].print();
//    }
    for(i = bottle; i < top; i++){

        point[++id] = GetIntersection(Q[i], Q[i+1]);
    }
}

double GetArea(){
    int i;
    double ans = 0;
    if(id <3) return 0;
//    printf("%d\n", id);
//    for(i = 1; i <= id; i++){
//        point[i].print();
//    }
    return 1;
    for(i = 2; i < id; i++){
        ans += xmul(point[1], point[i], point[i+1]);
    //    printf("%f\n", ans);
    }

    ans /= 2.0;
    return ans;
}
void buildnew(double r){
    int i;
    Point p;
    pt[n+1] = pt[1];
    for(i = 1; i <= n ;i++){
        p = pt[i + 1] - pt[i];
        p = p.ContraRotate();
        p = p / (p.mo()) * r;  // printf("~%f %f\n", p.x, p.y);
        line[i]= Line(pt[i]+p, pt[i+1]+p); //line[i].print();
    }
}
int main(void){
    int i, j;
    double low, ans, high, mid;

    while(scanf("%d", &n) != EOF){
        for(i = 1; i <= n; i++) pt[i].scan();

        low = 0;    high = 10000;
        double debugcnt = 0;
/*
        buildnew(700);
        no = n;
            line[++no].getline(0, 0, 10000, 0);
            line[++no].getline(10000, 0, 10000, 10000);
            line[++no].getline(10000, 10000, 0, 10000);
            line[++no].getline(0, 10000 , 0, 0);
            HalfPlaneIntersection();

            if(GetArea()) {
                    printf("!!!\n");
                ans = 700;
            }

*/
        while(doublecmp(high - low) > 0){
            mid = (low + high) / 2;
            buildnew(mid);
            no = n;
            line[++no].getline(0, 0, 10000, 0);
            line[++no].getline(10000, 0, 10000, 10000);
            line[++no].getline(10000, 10000, 0, 10000);
            line[++no].getline(0, 10000 , 0, 0);
            HalfPlaneIntersection();

            if(GetArea()) {
               //     printf("!!\n");
                ans = mid;  low = mid;
            }
            else high = mid;
            printf("%f %f %f %f\n", low, high, ans, mid);
        }

        printf("%.10f\n", ans);
    }
    return 0;
}
