#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

#define MAX 1111

char s[MAX];
int f[200];

class cmp
{
    public:
    bool operator()(int A, int B)
    {
        return A > B;
    }
};
priority_queue<int, vector<int>, cmp>Q;

int main(void)
{
    int lt, i, a, b, sum;

    while(scanf("%s", s))
    {
        if(strcmp(s, "END") == 0)   break;
        memset(f, 0, sizeof(f));    sum = 0;
        lt = strlen(s);
        for(i = 0; s[i] != '\0'; i++)
            f[s[i]] ++;
        if(f[s[0]] == lt)
        {
            printf("%d %d 8.0\n", lt * 8, lt);
            continue;
        }

        for(i = 0; i < 180; i++)
        {
            if(f[i])    Q.push(f[i]);
        }
        while(Q.size() != 1)
        {
            a = Q.top();   Q.pop();
            b = Q.top();   Q.pop();
            sum += (a + b);
            Q.push(a + b);
        }
        while(!Q.empty())   Q.pop();
        printf("%d %d %.1f\n", lt * 8, sum, (double)lt * 8 / sum);

    }
    return 0;
}
