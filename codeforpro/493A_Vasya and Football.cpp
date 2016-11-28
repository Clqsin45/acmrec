#include <bits/stdc++.h>
using namespace std;
#define N 202
int cnt[N];
char name[2][22];
struct point{
    int time,  num;
    char team[4], typ[4];
    void scan(){
        scanf("%d%s%d%s", &time, team, &num, typ);
    }

    void gao(){

        if(typ[0] == 'r'){
            cnt[num + (team[0]=='a')*100] ++;
            if(cnt[num + (team[0]=='a')*100] == 2){
                printf("%s %d %d\n", name[team[0] == 'a'], num, time);
            }
            cnt[num + (team[0]=='a')*100] ++;
            if(cnt[num + (team[0]=='a')*100] == 2){
                printf("%s %d %d\n", name[team[0] == 'a'], num, time);
            }
        }
        else {
            cnt[num + (team[0]=='a')*100] ++;
            if(cnt[num + (team[0]=='a')*100] == 2){
                printf("%s %d %d\n", name[team[0] == 'a'], num, time);
            }
        }
    }
}p[N];

bool cmp(point a, point b){
    return a.time < b.time;
}
int main(){

    int n, i, j;
    memset(cnt, 0, sizeof(cnt));

    scanf("%s%s%d",name[0], name[1], &n);
    for(i = 1; i <= n; i++) p[i].scan();

    sort(p +1, p +n +1, cmp);

    for(i = 1; i<= n; i++){
        p[i].gao();
    }
    return 0;
}
