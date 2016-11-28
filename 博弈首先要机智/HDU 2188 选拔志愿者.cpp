#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int n, m, TC;
    cin >> TC;
    while(TC--){
        cin >> n >> m;
        printf("%s\n", n <= m || n % (m+1) ? "Grass":"Rabbit");
    }
    return 0;
}
