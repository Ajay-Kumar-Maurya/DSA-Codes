#include <stdio.h>

int main()
{
	int c;
	char ch;
	char s[10];
	char str[20];

	printf("Enter an integer :  ");
	scanf("\n%d", &c);
	printf("Enter an character :  ");
	scanf("\n%c", &ch);
	printf("Enter an word :  ");
	scanf("%s", s);
	printf("Enter an sentence :  ");
	scanf("\n%[^\n]", str);

	printf("\n\n\nOutput ::\n%d\n%c\n%s\n%s",c,ch,s,str);

	return 0;
}

/*
In C, If we use scanf() for char and strings, then these type of variables can read
a) white-space from previous input, if it has. (If after taking input, white-space was pressed)
b) newline character, \n, from the previous line. (If after taking input, Enter Key was pressed)

e.g. -
int N; char ch;
scanf("%d", &N); scanf("%c", &ch);
				or
scanf("%d%c", &N, &ch);


Input 1 : 43534<space><space><space><space>43<EnterKey>
Input 2 : 43534<EnterKey>
		  45<EnterKey>





				Resolving These Unexpected Behaviour

Method 1 : Use white-space then format specifiers for each input
e.g. -
int N; char ch;
scanf(" %d", &N); scanf(" %c", &ch);
				or
scanf("%d", &N); scanf("%c ", &ch);
				or
scanf(" %d ", &N); scanf(" %c ", &ch);
				or
scanf("%d %c", &N, &ch);



Method 2 : Use '\n' then format specifier for each input
e.g. -
int N; char ch;
scanf("\n%d", &N); scanf("\n%c", &ch);
				or
scanf("%d\n", &N); scanf("%c\n", &ch);
				or
scanf("\n%d\n", &N); scanf("\n%c\n", &ch);
				or
scanf("%d\n%c", &N, &ch);
*/
