#include <stdio.h>

#define M 60
#define N 1010
#define INF 0x3f3f3f3f
int a[M],dp[M][M];
int n,m;

int min(int i ,int j)
{ return i<j?i:j; }
int main()
{
    int i, j ,l, k,Min, n ,m;
    while(scanf("%d",&n)!=EOF && n)
    {
        scanf("%d",&m);
        a[0]=0; a[m+1]=n;
        for(i=1; i<=m; i++)
            scanf("%d",&a[i]);
        //memset(dp,0x3f,sizeof(dp));
        //并不是所有状态都要清INF，否则会TLE
        for( i=0; i<=m; i++)
            dp[i][i+1]=0;

        for( l=2; l<=m+1; l++)  //把多少块合并
            for( i=0; i<=m-l+1; i++) //标号
            {
                 j=i+l,Min=INF;
                for( k=i+1; k<j; k++)
                    Min=min(Min , dp[i][k]+dp[k][j]);
                dp[i][j]=Min+a[j]-a[i];
                printf("dp[%d][%d] = %d \n", i, j , dp[i][j]);
            }
        printf("The minimum cutting is %d.\n",dp[0][m+1]);
    }
    return 0;
}
