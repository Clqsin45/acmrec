#include<bits/stdc++.h>
using namespace std;
char ch[103];
int main(){
    string inp;
    gets(ch);
    inp = (string)ch;
    //���ļ� ���벢�����ļ�
    FILE *fp = NULL;
    inp= inp + ".cpp";
    int len = inp.length();
    inp.copy(ch, len, 0);
    fp = fopen( ch, "w");
    //cout<<inp<<endl;

    //Ԥ�ô���
   // if(isdigit(ch[0])){
        fprintf(fp, "#include <bits/stdc++.h>\n");
    //}else{
        //fprintf(fp,"#include <cstring>\n");
        //fprintf(fp,"#include <cstdio>\n");
      //  fprintf(fp,"#include <algorithm>\n");

    //}
    fprintf(fp,"using namespace std;\n");
    //close
    fclose(fp); fp = NULL;


    return 0;
}
