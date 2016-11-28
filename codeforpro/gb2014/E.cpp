#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define LL __int64
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
map<int, int >f;
LL ans[N];
int a[N << 1], dir[N<<1], tot = 0;
struct point{
    int pos, fall;
    point(){};
    point(int x, int y){
        pos = x;    fall = y;
    }

    void scan(){
        scanf("%d%d", &pos, &fall);
        fall = pos + fall;
        a[++tot] = fall;    a[++tot] = pos;
    }
}p[N];
int app[N<<3], ext[N<<3];

void pushup(int x){
	ext[x] = max(ext[x<<1], ext[x<<1|1]);
	app[x] = (app[x<<1]||app[x<<1|1]);
}
void build(int l, int r, int rt){
	if(l == r){
		app[rt] = 0;
		ext[N<<3] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(lson);	build(rson);
	pushup(rt);
}

void modify(int p,  int l, int r, int rt){
	if(l == r){
		ext[rt] = p;
		app[rt] = true;
		return;
	}

	int mid = (l + r) >> 1;
	if(p <= mid) modify(p,lson);
	else modify(p,  rson);
	pushup(rt);
}
int quire(int pos, int l, int r, int rt){
   // printf("!!!first%d\n", pos);
 //   if(!app[rt])    {
   //         printf("!!%d %d\n", l, r);return -1;
   // }
    if(l >= pos){
       // printf("!!!!\n");
        if(app[rt] == 0)   return -1;
        return ext[rt];
    }
	int mid = (l + r) >> 1, ans = -1;
	//printf("%d %d %d %d\n", l,r, mid,pos);
	if(pos >= mid){
        ans = quire(pos, rson);
        //ans = max(ans,  quire(pos, rson));
	}
	else{

        ans =  quire(pos, lson);
        ans = max(ans, quire(pos, rson));
	}
	return ans;
}

int main(){
    int n, m, i, j, temp;
    scanf("%d", &n);
    tot = 0;
    for(i = 1; i <= n; i++) p[i].scan();
    sort(a + 1, a + tot + 1);
    tot = unique(a + 1, a+ tot + 1) - a;
    tot --;
    for(i = 1; i <= tot; i++){
            f[a[i]] = i;
        dir[i] = a[i];
    }
   // printf("%d\n", tot);
    build(1, tot, 1);
    //printf("%d\n", f[p[1].fall]);
    modify(f[p[1].fall], 1, tot, 1);
    printf("%d\n", quire(f[p[2].pos], 1, tot, 1));

    for(i = 1; i <= n; i++){
            temp = 0;
        if(i == 1){
            modify(f[p[i].fall], 1, tot, 1);
        }else{

            int gg = quire(f[p[i].pos],1, tot, 1);
            //if(i == 4)
          //   printf("%d\n", gg);
            if(gg!= -1){
                modify(f[p[i].fall], 1, tot, 1);
            }

            else{
                temp = quire(1, 1, tot, 1);
               // printf("%d\n", temp);
                temp = p[i].pos - dir[temp];
                modify(f[p[i].fall], 1, tot, 1);
            }
        }
        //printf("%d\n", quire(p[i].fall, 1, tot, 1));
        ans[i] = ans[i-1] + temp;
    }


    printf("%d\n", ans[n]);

}
