#include <bits/stdc++.h>
using namespace std;
map<char, int >f;
char ch[10];
void init(){
    f.clear();
    f['Q'] = 9; f['q'] = -9;
    f['R'] = 5; f['r'] = -5;
    f['B'] = 3; f['b'] = -3;
    f['N'] = 3; f['n'] = -3;
    f['P'] = 1; f['p'] = -1;
}

int main(){
    int i, j, ans = 0;
    init();
    for(i = 1; i <= 8; i++){
        scanf("%s", ch);
        for(j = 0; j < 8;j ++)ans += f[ch[j]];
    }

    if(ans == 0)    printf("Draw\n");
    else printf("%s\n", ans > 0 ? "White" : "Black");
    return 0;
}
