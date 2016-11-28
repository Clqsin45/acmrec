#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 1004
#define M 1000004
#define LL __int64
#define INF 0x3f7f7f7f

int head[N];
int l[N], r[N], no;
bool vis[N];
struct point{
    int v, next;
    point(){};
    point(int x, int y):v(x), next(y){};
}p[M];
void add(int x, int y){
    p[no] = point(y, head[x]);  head[x] = no++;
    //p[no] = point(x, head[y]);  head[y] = no++;
}

bool connect(int x, int y){
    int i;
    for(i = head[x]; i != -1; i = p[i].next){
        if(y == p[i].v) return true;
    }
    return false;
}

int main(void)
{
    int i, j, x, y, n, s, t, cnt;
    char ch;
    bool loop, first, find;
    while(scanf("%d", &n) != EOF)
    {
        memset(head, -1, sizeof(head));
        memset(vis, 0, sizeof(vis));
        no = 0;
        getchar();
        for(i = 1; i <= n; i++){
            t = 0;
            while(ch = getchar()){
                if(ch == '\n')  {
                    if(t != 0)  {
                        add(i, t);
                    }
                    break;
                }
                else if(ch == ' '){
                    if(t)   {
                        add(i, t);
                    }
                    t=  0;
                }
                else {
                    t = t * 10 + ch - '0';
                }
            }
        }
//        for(i = 1; i <= n; i++){
//            for(j = head[i]; j != -1; j = p[j].next)
//                printf("%d ", p[j].v);
//            printf("\n");
//        }
        s = 1;
        for(i = head[1]; i  != -1; i = p[i].next){
            t = p[i].v;
            break;
        }

        vis[s] = vis[t] =true;
        l[t] = s;   r[s] = t;
        cnt = 2;
        loop = false;   first = true;
      //  printf("%d %d\n", s, t);
        while(true){

            if(!first){

                for(i = 1; i <= n; i++){
                    if(vis[i])  continue;
                    for(j = head[i]; j != -1; j = p[j].next){
                        y = p[i].v;
                        if(vis[y] && y != s && y != t)  {
                            find = true;
                            break;
                        }
                    }
                    if(find)    break;
                }
                s = y;  t = l[y];
            }

            first = false;
            while(cnt <= n){
                for(i = head[s]; i != -1; i = p[i].next){
                    y = p[i].v;
                    if(vis[y])  continue;
                    l[s] = y;   r[y] = s;   s = y;  vis[y] = true;
                    cnt ++;
                    break;
                }
                if( i == -1)    break;
            }
           // printf("%d\n", cnt);
            while(cnt <= n){
               // printf("%d %d\n",t, head[t]);
                for(i = head[t]; i != -1; i = p[i].next){
                    y = p[i].v; //printf("%d\n", y);
                    if(vis[y])  continue;
                    r[t] = y;   l[y] = t;   t = y;  vis[y] =  true;
                    cnt ++;
                    break;
                }
                if(i == -1) break;
            }

            if(connect(s, t)) {
                l[s] = t;   r[t] = s;
            }
            else {
              //  printf("yayayainhere\n");
                for(i = r[s]; i != t; i = r[i])
                {
                    if(connect(i, t) && connect(r[i], s))   break;
                }
                r[s] = r[i];    l[r[i]] = s;
                for(j = l[i]; j != s; j = y){
                    y = l[j];   swap(l[j], r[j]);
                }
                r[t] = i;   r[i] = l[i];    l[i] = t;
                l[s] = r[s];

            }
            if(cnt == n) break;
        }
      //  printf("s:%d t:%d\n", s, t);
        first = true;
        for(i = 1; i != 1 ||first; i = r[i])
        {
            first = false;
            printf("%d ", i);
        }
        printf("%d\n", 1);


    }
    return 0;
}
