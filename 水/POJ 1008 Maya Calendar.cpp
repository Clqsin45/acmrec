#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include<iostream>
using namespace std;
map<string, int>f;
const int N = 22;
char str[N][10] = {"imix", "ik", "akbal", "kan", "chicchan",
    "cimi", "manik", "lamat", "muluk", "ok",
    "chuen", "eb", "ben", "ix", "mem",
    "cib", "caban", "eznab", "canac", "ahau"};
void init(){
    f["pop"] = 1;f["no"] = 2;f["zip"] = 3;f["zotz"] = 4;f["tzec"] = 5;
    f["xul"] = 6;f["yoxkin"] = 7;f["mol"] = 8;f["chen"] = 9;  f["yax"] = 10;
    f["zac"] = 11;f["ceh"] = 12;f["mac"] = 13;f["kankin"] = 14;f["muan"] = 15;
    f["pax"] = 16;f["koyab"] = 17;f["cumhu"] = 18;f["uayet"] = 19;
}

int main(){
    init();
    int TC, i, n, day, year, sumday, month;
    string st;
    char temp;
    scanf("%d", &TC);
    while(TC--){
        cin >> day >> temp >> st >> year;
        //haab to sum
        sumday = year * 365;
        month = f[st];

        sumday += (month-1)*20 + day;//printf("%d\n", sumday);
        //sum to Tzolkin
        year = sumday / 260;
       // sumday %= 260;
        day = sumday % 20 ;
        month = sumday %13 + 1;
        printf("%d %s %d\n", month, str[day], year);
    }
    return 0;
}
