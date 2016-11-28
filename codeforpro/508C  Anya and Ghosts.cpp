#include <bits/stdc++.h>
using namespace std;

#define N 603
int f[N], now[N];
int main(){
    int m, r, t, i, j, ans = 0,x;
    cin>>m>>t>>r;
    memset(f, 0,sizeof(f));
    memset(now, 0, sizeof(now));


    for(i = 1; i <= m; i++){
        cin>>x;
        f[x] = 1;
    }

    if(t < r) {
        cout<<-1<<endl;
        return 0;
    }


   for(i = 1; i <= 300; i++){
        if(f[i]){
            if(now[i] < r){
                int temp = r - now[i];
                ans += r - now[i];
                for(j = 0; j <= t - temp; j++) now[i+j] += temp;
               for(; j < t; j++) {
                    now[i+j] = now[i+j-1] - 1;
            //        if(now[i+j] < 0) printf("!!!%d %d\n", i, j);
               }
            }
        }
    }

   cout<<ans<<endl;
    //cout<<ans<<endl;
}
/*
88 82 36
16 17 36 40 49 52 57 59 64 66 79 80 81 82 87 91 94 99 103 104 105 112 115 117 119 122 123 128 129 134 135 140 146 148 150 159 162 163 164 165 166 168 171 175 177 179 181 190 192 194 196 197 198 202 203 209 211 215 216 223 224 226 227 228 230 231 232 234 235 242 245 257 260 262 263 266 271 274 277 278 280 281 282 284 287 290 296 297
*/
