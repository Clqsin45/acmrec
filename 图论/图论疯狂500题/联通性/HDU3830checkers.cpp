#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <iostream>
using namespace std;

#define N 10002
#define M 1000002
#define LL long long
#define INF 0x3f3f3f3f


struct point{
	int x, y, z;
	LL deep;
	point(){};
	point(int a, int b, int c, LL d):x(a), y(b), z(c), deep(d){};

	bool operator !=(const point &I)const{
		return x != I.x || y != I.y || z != I.z;
	}
	bool operator ==(const point &I)const{
		return x == I.x && y == I.y && z == I.z;
	}
}start, end;
void order(point &temp){
		if(temp.x > temp.y)	swap(temp.x, temp.y);
		if(temp.x > temp.z)	swap(temp.x, temp.z);
		if(temp.y > temp.z)	swap(temp.y, temp.z);
}


point findroot(point &st){
	point temp = st;
	LL  p = temp.z - temp.y, q = temp.y - temp.x, ct;
	while(p != q){
		//cout<<p<< "  "<< q<<endl;
		if(p > q){
			ct  = (p - 1) / q;
			temp.y += ct * q;
			temp.x += ct * q;
		}
		else{
			ct = (q - 1) / p;
			temp.y -= ct * p;
			temp.z -= ct * p;
		}
		st.deep += ct;
		order(temp);
		p = temp.z - temp.y;
		q = temp.y - temp.x;
	}
	return temp;
}

point gao(point st, LL step){
	point t = st;
	LL  p,q, r;
	while(step > 0LL){

		p = t.z - t.y;	q = t.y - t.x;

		if(p > q){
			r = min(step, (p - 1) / q);
			t.x += r * q;
			t.y += r * q;
		}
		else{
			r = min(step, (q - 1) / p);
			t.y -= r * p;
			t.z -= r * p;
		}
		step -= r;
		order(t);
		p = t.z - t.y;	q = t.y - t.x;
	}
	return t;
}

int main(){
	int x, y, z, xx, yy, zz;
	LL ds, de, dis, high, low, mid, ans;
	point t1, t2;
	while(cin>>x>>y>>z>>xx>>yy>>zz){
		start = point(x, y, z, 0LL);
		end = point(xx,yy, zz, 0LL);
		order (start);	order(end);



		t1 = findroot(start);

	t2 = findroot(end);
		if(t1 != t2){
			cout<<"NO"<<endl;
			continue;
		}

		ds = start.deep;	de = end.deep;
		dis = ds - de;
		if(dis > 0){
			start = gao(start, dis);
		}
		else end = gao(end,- dis);
		//	cout<<start.deep<<"  " << end.deep<<endl;

		low = 0LL, high = min(ds, de);
		ans = 0LL;
		while(low <= high){
			mid = (low + high) >> 1;
			if(gao(start, mid)== gao(end, mid)){
				high = mid - 1;
				ans = mid;

			}
			else low = mid + 1;
		}
		dis = abs(dis);
		ans = ans * 2 + dis;
		cout<<"YES"<<endl<<ans<<endl;
	}
	return 0;
}

