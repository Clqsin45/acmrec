#include <stdio.h>
char stack[200002];
int main(void)
{
	int top, t, i;
	char ch;
	scanf("%d\n",&t);
	while(t--){
		top = 0;
		while((ch = getchar()) != '\n'){
			stack[++top] = ch;
			if (stack[top] == stack[ top -1]) top -= 2;
		}
		
		for(i = 1; i <= top; i++)
		    printf("%c",stack[i]);
		printf("\n");
	}
	return 0;
}
