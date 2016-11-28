#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

class cmp
{
    public:
    bool operator()(int A, int B)
    {
        return A > B;
    }

};

priority_queue<int, vector<int>, cmp>Q;
int f[200];
char s[2222];

int main(void)
{
    int T, i, sum, lt, a, b, max;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%s", &max, s);
        memset(f, 0, sizeof(f));    sum = 0;
        lt = strlen(s);

        for(i = 0; i < lt; i++)
        {
            f[s[i]] ++;
        }

        if(lt == f[s[0]])   sum = lt;
        for(i = 0; i < 200; i++)
        {
            if(f[i])   Q.push(f[i]);
        }

        while(Q.size() > 1)
        {
            a = Q.top();    Q.pop();
            b = Q.top();    Q.pop();
            sum += (a + b);
            Q.push(a + b);
        }
        while(!Q.empty())   Q.pop();
        if(sum <= max)  printf("yes\n", sum);
        else printf("no\n");

    }
    return 0;
}
