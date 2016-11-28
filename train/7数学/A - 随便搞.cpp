#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

#define MAX
#define INF 0x3f7f7f7f


int main(void)
{
    int TC;
    double n;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%lf", &n);
        n = n * log10(n);
        printf("%d\n", (int)pow(10.0, n - floor(n)));
    }
    return 0;
}
