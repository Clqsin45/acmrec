#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) &&(n||m)){

        int cnt = 0;
        while(true){
            if(n < m)   swap(n, m);
            if(m == 0)    break;

            cnt ++;
            if(n - m > m)   break;
            int temp = n / m;
            n -= temp * m;
        }
        printf("%s\n",cnt&1 ?  "Stan wins":"Ollie wins");
    }
    return 0;
}
