#include <bits/stdc++.h>
using namespace std;

const int N = 6;
int Left[N], Right[N];
int n;

double cal_equ(int i, int x){
    int j;
    double ans = 1.0;

    for(j = 1; j <= n; j++){
        if(i == j)  continue;
        if(x >= Left[j])
            ans *= 1.0  * (min(x, Right[j])-Left[j]+1)/(Right[j]-Left[j]+1);
        else return 0;
    }
    return ans;
}

double cal_one( int x){
    int i, j, y = x-1;
    double ans = 0.0, temp;
    for(i = 1; i <= n; i++){
        if(x <= Right[i] && x >= Left[i]){
            temp = 1.0;
            for(j = 1; j <= n; j++){
                if(j == i) continue;
                if(Left[j] <= y){
                    temp *= 1.0  * (min(y-Left[j]+1, Right[j]-Left[j]+1))/(Right[j]-Left[j]+1);
                 //   printf("!!%d %d %d\n", i, j, y);
                }
                else {
                    temp = 0;    break;
                }
            }
          //  printf("%d %f\n",i, temp);
            ans += temp/(Right[i]-Left[i] + 1);
        }
    }
    return ans;
}

int main(){
    //freopen("in.txt", "r", stdin);
    int i, j;
    double ans = 0, temp;
    cin >> n;
    int low = 10004, high = 0;
    double pless, pequ,pone;
    for(i = 1; i <= n; i++){

        cin>>Left[i]>>Right[i];
        low = min(low, Left[i]);
        high = max(high, Right[i]);
    }
    int ff =  8;
    for(i = low; i <= high; i++){
    //for(i = ff; i <= ff; i++){
        for(j = 1; j <= n; j++){
            //first > i
            if(Right[j] > i) {
                pless = cal_equ(j,i-1);
                pequ = cal_equ(j, i);
                temp = pequ - pless;
             //   printf("%d %f %f\n",j, pless, pequ);
                ans += (min(Right[j]-Left[j]+1, Right[j]-i)) * temp / (Right[j]-Left[j]+1) * i;
            }
        }

        //first == i
       // printf("%d %f\n", i, ans);
        pequ = cal_equ(0, i);

        pless = cal_equ(0, i-1);
        temp = pequ - pless;
        //printf("%f %f %f\n", pequ, pless, temp);
        pone = cal_one(i);
       // temp -= pone;printf("%d %f %f\n", i, ans, pone);
       temp -= pone;
        ans += temp * i;
     //   printf("%d %f\n", i, ans);
    }
    printf("%.10f\n", ans);
    return 0;
}
