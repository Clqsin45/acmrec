#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <iostream>
using namespace std;


const double eps = 1e-8;
const int N = 144;
int doublecmp(double x){
    if(fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}
struct HalfPlaneIntersection{

    int n, no, id;
    struct Point{
        double x, y;
        Point(){};
        Point(double xx, double yy): x(xx), y(yy){};
        void scan(){
            scanf("%lf%lf", &x, &y);
        }
        void print(){
            printf("%.10f %.10f\n", x, y  );
        }

        void print(char *ss){
            printf("%s\n%.10f %.10f\n",ss, x, y  );
        }
        double mo(){
            return sqrt(x*x+y*y);
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
        //求向量逆时针旋转90度
        Point ContraRotate(){
            return Point(-y, x);
        }
        Point ContraRotate(double rad){
            return Point(x * cos(rad) - sin(rad) * y, x * sin(rad) + y * cos(rad));
        }
        double xmul(const Point &I) const{
            return x * I.y - y * I.x;

        }
    };

    struct Line{
        Point a, b;
        double angle;

        bool operator<(const Line &I)const{
            //根据1。极角增，2.在内优先
            int d = doublecmp(angle-I.angle);
            if(d == 0){
            return doublecmp((I.a-a).xmul(I.b-a)) > 0;
            }
            return d < 0;
        }

        void getline(){
            a.scan();   b.scan();
            angle = atan2(b.y - a.y, b.x - a.x);
        }
        void getline(Point A, Point B){
            a = A;  b = B;
            angle = atan2(b.y - a.y, b.x - a.x);
        }
        void getline(double x1, double y1, double x2, double y2){
            a = Point(x1, y1);  b = Point(x2, y2);
            angle = atan2(y2 - y1, x2 - x1);
        }
        //用不等式ux + vy +w < 0 GET left
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


        bool parallel(const Line &I)const{
            return doublecmp((b-a).xmul(I.b-I.a)) == 0;
        }

        void print(){
            printf("!!!\n");
            a.print();  b.print();
        }
        void print(char *ss){
            printf("%s\n", ss);
            a.print();  b.print();
        }
    };
    Line line[N];   Point point[N];
    Line Q[N];
    double xmul(Point a, Point b, Point c){
        return (b-a).xmul(c-a);
    }
    //所有线向左边平移距离r
    void buildnew(double r){
        int i;
        Point p;
        point[n+1] = point[1];
        for(i = 1; i <= n ;i++){
            p = point[i + 1] - point[i];
            p = p.ContraRotate();
            p = p / (p.mo()) * r;  // printf("~%f %f\n", p.x, p.y);
            line[i].getline(point[i]+p, point[i+1]+p); //line[i].print();
        }
    }
    //去除同样极角的外点
    void unique(){
        int i, j = 0;
        for(i = 1; i <= no; i++){
            if(i == 1 || doublecmp(line[i].angle-line[i-1].angle) != 0) line[++j] = line[i];
        }
        no = j;
    }
    //A B交点
    Point GetIntersection(Line A, Line B){
        double dot1 = xmul(B.a, A.b, A.a);
        double dot2 = xmul(A.b, B.b, A.a);
        Point p = Point((B.a.x*dot2+B.b.x*dot1) / (dot2+dot1), (B.a.y*dot2+B.b.y*dot1)/(dot1+dot2));
        return p;
    }
    bool OutPlane(Line A, Line x1, Line x2){
        Point p = GetIntersection(x1, x2);
       // p.print();
        return doublecmp(xmul(A.a, p, A.b)) > 0;
    }


    void halfplaneintersection(void){
        int i, j;
        Line inser = line[no], temp;
        bool trans = false;
        for(i = 1; i < no; i++){
            if(inser.angle == line[i].angle){
                if(inser < line[i]){
                    line[i] = inser;
                }
                no --;
                break;
            }else if(inser < line[i]){
                swap(inser, line[i]);
                trans = true;
            }
        }
        if(trans){
            line[no] = inser;
        }

        int top = 1, bottle = 0;
        Q[0] = line[1];
        Q[1] = line[2];
        for(i = 3; i <= no; i++){
                // 顶部交点不在当前平面内
            while(top > bottle && OutPlane(line[i], Q[top], Q[top-1])) {
                    top--;
            }
                // 底部交点不在当前平面内
            while(top > bottle && OutPlane(line[i], Q[bottle], Q[bottle + 1]))  bottle ++;
            //如果严格要求没有核 就加下面这条
        //    if(line[i].parallel(Q[top])) return false;
            Q[++top] = line[i];
        }

        //顶部交点不在底部平面内
        while(top > bottle && OutPlane(Q[bottle], Q[top], Q[top-1])) top--;
            //底部交点不在顶部平面内
        while(top > bottle && OutPlane(Q[top], Q[bottle], Q[bottle + 1])) bottle ++;

        Q[++top] = Q[bottle];
        id = 0; no = 0;
        for(i = bottle; i < top; i++){
            point[++id] = GetIntersection(Q[i], Q[i+1]);
            line[++no] = Q[i];
        }

       // return id >= 3;
    }

    double GetArea(){
        int i;
        double ans = 0;
        if(id <3) return 0;
        for(i = 2; i < id; i++){
            ans += xmul(point[1], point[i], point[i+1]);
        }
        ans /= 2.0;
        return ans;
    }
    void AddBound(double bound){
        line[++no].getline(0, 0, bound, 0);
        line[++no].getline(bound, 0, bound, bound);
        line[++no].getline(bound, bound, 0, bound);
        line[++no].getline(0, bound, 0, 0);
    }
    void Main(){
        char op[1000];
        no = 0;
        AddBound(10);
        sort(line + 1, line + 5);

        bool flag = false;


        double x, y;
        Point pre = Point(0, 0), midpoint, now, fax;
        string state;
        string is;


        while(getline(cin, is)){
            //cout<<is<<endl;

            istringstream iss;
            iss.str(is);
            iss>>x>>y>>state;

            if(flag){
                printf("0.00\n");
                continue;
            }
            now = Point(x, y);
          //  printf("%f %f\n", x, y);
            midpoint = (pre+now)/2;
            fax = now - pre;

           // fax.print("fax\n");
            fax = fax.ContraRotate();
           // fax.print();
            if(state[0] == 'C'){
                line[++no].getline(midpoint, midpoint + fax);
            }
            else if(state[0] == 'H') {
                line[++no].getline(midpoint, midpoint - fax);
            }
            else{
                flag = true;
                printf("0.00\n");
                continue;
            }
            halfplaneintersection();
            printf("%.2f\n", GetArea());
            pre = now;
        }
    }
}hpi;

int main(){
    hpi.Main();
    return 0;

}



