#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, s;
    int temp;
    cin >> a>> b >>s;
    temp = abs(a) + abs(b);
    printf("%s\n", temp > s || (s-temp)&1 ? "No" : "Yes");
    return 0;

}
