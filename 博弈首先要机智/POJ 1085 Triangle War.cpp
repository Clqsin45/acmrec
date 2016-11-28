#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int inf;
int line[22][2] = {
    {1, 2},{1, 3},{2, 3},{2, 4},{2, 5},{3, 5},
    {3, 6},{4, 5},{5, 6},{4, 7},{4, 8},{5, 8},
    {5, 9},{6, 9},{6, 10},{7, 8},{8, 9},{9, 10}
};

int tri[10] = { 0x07, 0x34, 0x98, 0x160, 0x8600, 0xc80,0x11800,
    0x3100, 0x26000
};

int dir[20];

int dp[1 <<20], n, m;
int lookup(int x, int y){
    int i;
    for(i = 0; i < 18; i++){
        if(line[i][0] == x && line[i][1] == y)return i;
    }
}

int find(int state, int k){
    int i,  ans = 0;
    for(i = 0; i < 9; i++){
        //如果已经形成了
        if((state & tri[i]) == tri[i]) continue;
            //加入k之后才形成
        if((tri[i]&(k|state)) == tri[i])  ans ++;
    }
    //不直接break -- 可能形成多个
    return ans;
}

int gao(int state){
    if(dp[state] != inf)return dp[state];
    //放完了
    if(state == dir[18] - 1) return dp[state] = 0;

    int ans = inf, i, j, temp;
    for(i = 0; i < 18; i++){
        if(state & dir[i])  continue;
        temp = find(state, dir[i]);
        //若获得 则继续走一步1，否则为下一个人-1
        temp += gao(state | dir[i]) * (temp?1:-1);
        ans = max(ans, temp);
    }
    return dp[state] = ans;
}

void init(){
    int i;
    dir[0] = 1;
    for(i = 1; i <= 18; i++)dir[i] = dir[i-1]<<1;
}

int main(){
    int TC, state, num,  temp, k, i, j, n, tc, one;
    int x, y ;
    scanf("%d" , &TC);
    init();
    for(tc = 1; tc <= TC; tc++){
        scanf("%d", &n);
        state = num = 0;
        one = 1;

       // memset(dp, 0xbf, sizeof(dp));
        fill(dp, dp + (1<<18), -20);
        //printf("%d\n", dp[0]);
        inf = dp[0];
        while(n--){
            scanf("%d%d", &x, &y);

            k = lookup(x, y);
            temp = find(state, dir[k]);
           // printf("~~~%d\n", temp);
            state |= dir[k];
            num += one * temp;
            //获得后可以多走一步
            one = temp> 0 ? one : -one;
        }
      //  printf("%d %d\n", state, num);
        printf("Game %d: %c wins.\n",tc ,(num+one*gao(state))>0?'A':'B');
    }
}



