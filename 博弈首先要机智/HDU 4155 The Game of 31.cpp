#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[5][5][5][5][5][5];
int cnt[7];

int  dfs(int ct[], int sum){
    if(dp[ct[1]][ct[2]][ct[3]][ct[4]][ct[5]][ct[6]] != -1)
        return dp[ct[1]][ct[2]][ct[3]][ct[4]][ct[5]][ct[6]];
    int temp[7];int i, j;
    for(i =1 ; i <= 6; i++) temp[i] = ct[i];


    dp[ct[1]][ct[2]][ct[3]][ct[4]][ct[5]][ct[6]] = 0;
    for(i = 1; i <= 6; i++){
        if(sum + i > 31)    break;
        if(ct[i] != 0){
            temp[i]--;
            if(!dfs(temp, sum + i))  {
                dp[ct[1]][ct[2]][ct[3]][ct[4]][ct[5]][ct[6]] = 1;
                break;
            }
            temp[i] ++;
        }
    }return dp[ct[1]][ct[2]][ct[3]][ct[4]][ct[5]][ct[6]];

}

char ch[50];
int main(){
    int n, m, i, j, x;
    char ans1, ans2;
    memset(dp, -1, sizeof(dp));
    while(scanf("%s", ch) != EOF){
        ans1 = 'A', ans2 = 'B';
        int len = strlen(ch);   int sum = 0;
        if(len & 1) swap(ans1, ans2);
        for(i = 1; i <= 6; i++)cnt[i] = 4;
        for(i = 0; i < len; i++){
            cnt[ch[i]-'0'] --;
            sum += ch[i] - '0';
        }
       // for(i = 1; i <= 6; i++) printf("%d\n", cnt[i]);
        printf("%s %c\n", ch,
            dfs(cnt, sum) ?
                ans1 : ans2);
    }
    return 0;
}
