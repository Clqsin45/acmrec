/********************
 һ��ʼ��Ϊ��Ҫ��1��ʼ���δ���Щ�����������ϵ����
��������A��һ�¿��Ե�x�㣬B��һ�µ�y�㣬�о���Щ�鷳��
���������Լ�����ˡ�

���˸��������lca(x, y)Ϊ���ڡ������ڴ���������
��Ĵ�С���ᳬ��������max(x,y)
������ȡģ�Ϳ�����

����һ�±�aÿ��1/x���Ӵ� һ�¿��Կ���ÿ��y���Ӵ�һ�£�ͬ���ı任b
����С����Ĵ��˳������
ע�ⱬlonglong re�� = =
D. Vanya and Computer Game
**********************/
#include<bits/stdc++.h>
using namespace std;
#define LL __int64
#define N 10000007
int typ[N];
string st[3] = {"Vanya","Vova", "Both"};
int main(void){
    int i, n,  z, j, tot =0;
    LL x, y;
    cin>>n>>x>>y;

    LL m = __gcd(x,y);
    m = x / m * y;
    i = j = 1;
    //0->xy
    typ[0] = 2;
   // cout<<m<<endl;
    while(i * y <= m && j * x <= m){
        if(i * y < j * x){
            typ[++tot] = 0;
            i++;
        }
        else if(j * x < i * y){
            typ[++tot] = 1;
            j++;
        }
        else{
            typ[++tot] = 2;
            break;
        }
        //printf("%d %d %d\n", tot, i, j);
    }
//cout<<tot<<endl;
    tot++;
    while(n--){
        cin>>x;
        cout<<st[typ[x%tot]]<<endl;

    }
}

