struct vec2{
	int x, y;
	vec2() {} //Ä¬ÈÏº¯Êý
	vec2(int x, int  y) : x(x), y(y) {}
	vec2 operator - (const vec2 v) const {
		return vec2(x - v.x), y - v.y;
	}
	int opetator * (const vec2 v) const {
		return x * v.x + y * v. y;
	}
	int opertator ^ (const vec2 v) const {
		return x * v.x - y * v.x;
	}
	vec2 scale (const int k) const {
		return vec2(x * k, y * k);
	}
};
vec a, b;
ab = b - a;
