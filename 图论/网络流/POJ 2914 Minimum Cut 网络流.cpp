#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include <queue>
#include <stdlib.h>
using namespace std;

#define N 555
#define INF 0x3f3f3f3f


int f[N][N], w[N], T, S, n;
bool v[N], comb[N];

int find()
{
    int mincut, i, j, temp, maxt;
    memset(v, false, sizeof(v));
    memset(w, 0, sizeof(w));

    T = S = -1;
    for(i = 0; i < n; i++)
    {
        maxt = -INF;
        for(j = 0; j < n; j++)
        {
            if(!v[j] && !comb[j] && w[j] > maxt)
            {
                maxt = w[j];    temp = j;
            }
        }
        if(temp == T)   return mincut;
        S = T;  T = temp;
        mincut = maxt;
        v[temp] = true;

        for(j = 0; j < n; j++)
        {
            if(!v[j] && !comb[j])
            {
                w[j] += f[temp][j];
            }
        }
    }
    return mincut;
}

int store_wagner()
{
    int i, j, ans = INF, nowcut;
    memset(comb, false, sizeof(comb));
    for(i = 1; i < n; i++)
    {
        nowcut = find();
        //printf("!!\n");
        if(nowcut == 0) return 0;
        ans = min(nowcut, ans);

        comb[T] = true;
        for(j = 0; j < n; j++)
        {
            if(comb[j]) continue;
            f[S][j] += f[T][j];
            f[j][S] += f[j][T];
        }
    }
    return ans;
}

int main()
{
    int  m, i, j, st1, st2, stt, ans;
    bool flag;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(f, 0, sizeof(f));
        while(m--)
        {
            scanf("%d%d%d", &st1, &st2, &stt);
            f[st1][st2] += stt; f[st2][st1] += stt;
        }
        //printf("!!\n");
        printf("%d\n", store_wagner());
    }
	return 0;
}
