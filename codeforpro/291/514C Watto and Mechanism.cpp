#include <bits/stdc++.h>
using namespace std;
const int N = 600005;

struct point{
    int now;
    bool let;
    int next[3];

    void init(){
        memset(next, -1, sizeof(next));
        let = false;
    }

    void add(int x){
        init();
        now = x;
    }

    void print(){
        printf("%d %d\n", now, let);
    }
}p[N];
int no;
char ch[N];
int len ;
bool dfs(int pre, int pos, bool flag){
    if(pos == len){
        return flag && p[pre].let;
    }
    int i, x;
    bool ok = false;
    x = ch[pos] - 'a';
    if(flag){
        if(p[pre].next[x] == -1){
            return false;
        }
        return dfs(p[pre].next[x], pos + 1, flag);
    }
    else{
        for(i = 0; i < 3; i++){
            if(p[pre].next[i] == -1)   continue;
            if(dfs(p[pre].next[i], pos + 1, i != x)){
                ok = true;
                break;
            }
        }
    }
    return ok;
}

void push(){
    int n = strlen(ch);
    int i, x;
    int now = 0;

    for(i = 0; i < n; i++){
        x = ch[i]-'a';
        if(p[now].next[x]== -1){

            p[no].add(x);
            if(i == n-1)p[no].let = 1;
            p[now].next[x] = no ++;

        }
        now = p[now].next[x];
    }
}



int main(){
    int n, m, i, j;
    p[0].init();    no = 1;
    cin >> n >> m;
    while(n--){
        scanf("%s", ch);
        push();
        //printf("%d\n", p[0].next[0]);
    }
//    for(i = 0; i <  no; i++){
//        printf("%d : ", i );  p[i].print();
//    }
    while(m--){
        scanf("%s", ch);
        len = strlen(ch);
        printf("%s\n", dfs(0, 0, 0) ? "YES" : "NO");
    }
    return 0;
}
