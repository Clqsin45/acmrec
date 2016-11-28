#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 55;
const int M  = 104;
char str[M][N];
struct point{
    int num, id;

}p[M];
int n, m;

void GetInverse(int id){
    int i;
    int NumA = 0, NumC = 0, NumT = 0, NumG =0;
    p[id].num = 0;  p[id].id = id;

    for (i = 0; i < m; i++){
        if(str[id][i] == 'A'){
            p[id].num += NumC;
            p[id].num += NumT;
            p[id].num += NumG;
            NumA ++;
        }
        else if(str[id][i] == 'C'){
            p[id].num += NumT;
            p[id].num += NumG;
            NumC ++;
        }
        else if(str[id][i] == 'G'){
            p[id].num += NumT;
            NumG ++;
        }else NumT ++;
    }
}

bool cmp(point a, point b){
    if(a.num == b.num)  return a.id < b.id;
    else return a.num < b.num;
}
int main(){
    int i, j;
    while(scanf("%d%d",&m, &n) != EOF){
        for(i = 1; i <= n; i++){
            scanf("%s", str[i]);
            GetInverse(i);
        }
        sort(p + 1, p + n + 1, cmp);
        for(i = 1; i <= n; i++){
            puts(str[p[i].id]);
        }
    }
    return 0;
}
