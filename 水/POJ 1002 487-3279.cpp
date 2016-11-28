#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;
const int N = 30;
int f[N];
int a[100004];
void init()
{
    int i, j = 0, tim;
    for(i =  2; i <= 6; i++) {
        for(tim = 0; tim < 3; tim++) {
            f[j] = i;
            j++;

        }
    }
    f[j++] = 7;
    f[j++] = 0;
    f[j++] = 7;
    f[j++] = 7;

    for(i = 8; i <= 9; i++) {
        for(tim = 0; tim < 3; tim++) {
            f[j] = i;
            j++;
        }
    }
}
char str[40];
int main()
{
    init();
    int n, i, j, id = 0, temp;
    scanf("%d", &n);
    getchar();
    for(i = 1; i <= n; i++) {
        gets(str);
      //  puts(str);
        temp = 0;
        for(j = 0; str[j] !='\0'; j++) {
            if(str[j] == '-')   continue;
            if(isdigit(str[j])) {
                temp = temp * 10 + str[j] - '0';
            } else {
                temp = temp * 10 + f[str[j]-'A'];
            }
        }
        a[++id] = temp;
        //  printf("%d\n", temp);
    }
    sort(a + 1, a + id + 1);
    temp = 0;
    bool ok = false;
    for(i = 2; i <= id; i++) {
        if(a[i] == a[i-1]) {
            temp ++;
            ok = true;
        } else {
            if(temp) {
                printf("%03d-%04d %d\n", a[i-1] / 10000, a[i-1] % 10000, temp+1);
            }
            temp = 0;
        }
    }
    if(temp) {
        printf("%03d-%04d %d\n", a[i-1] / 10000, a[i-1] % 10000, temp+1);
    }
    if(!ok) {
        puts("No duplicates.");
    }
    return 0;
}
