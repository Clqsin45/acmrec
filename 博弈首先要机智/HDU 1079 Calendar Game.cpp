#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*******************
11.4 = �档������һ��Ϊ�����ġ�
��һ�����ż�������� ������ż����
�ر�ġ�9.30��11.30 ��һ��10.1��12��1Ҳ������
*******************/
int main(){
    int TC, i, j, n, m, y;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d%d%d", &y, &n, &m);
        if((n+m)%2==0 ||( (n==11 || n == 9)&&m==30)){
            printf("YES\n");
        }
        else printf("NO\n");
    }
}
