#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


const int N = 55;
const int M = 50004;

int sg[N][M];


int dfs(int x, int y){
    if(sg[x][y] != -1)return sg[x][y];
    //����ֻ��һ���ˣ�Ҳ����һ���ֶ���һ��
    if(y==1)return sg[x][y] = dfs(x+1, 0);
    sg[x][y] = 0;

    if(x && !dfs(x-1, y)) sg[x][y] = 1;  //ȡ��1�ѵ�
    else if(y && !dfs(x, y-1))  sg[x][y] = 1;  //ȡ��һ��>1�ѵ�
    else if(x&&y&&!dfs(x-1, y+1))   sg[x][y] = 1;
    //1�ϲ���>1��
    else if(x >= 2 && !y && !dfs(x-2,y+2))    sg[x][y] = 1;
    else if(x >= 2 && y && !dfs(x-2, y + 3))    sg[x][y] = 1;
    return sg[x][y];
}
int main(){
    int n, m ,tc, x, TC, i, j, one, all;
    memset(sg, -1, sizeof(sg));

    scanf("%d", &TC);
    for(tc = 1; tc<= TC; tc++){
        scanf("%d", &n);
        one = all = 0;
        while(n--){
            scanf("%d", &x);
            if(x==1){
                one ++;
            }
            else{
                all += (x+1);
            }
        }
        if(all) all --;

        printf("Case #%d: %s\n", tc, dfs(one, all) ? "Alice" : "Bob");
    }
    return 0;
}
