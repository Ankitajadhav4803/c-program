/*infix to postfix expression*/#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
struct stack
{
	char a[MAX];
	int top;
}s;
void init()
{
	s.top=-1;
}
int isfull()
{
	if(s.top==MAX-1)
	return 1;
	else
	return 0;
}
int isempty()
{
	if(s.top==-1)
	return 1;
	else
	return 0;
}

void push(char x)
{
	if(isfull())
	printf("stack is full.don't push.");
	else
	{
	s.top++;
	s.a[s.top]=x;
	}
}
char pop()
{
	char ch;
	if(isempty())
	return -1;
	else
	{
	ch=s.a[s.top];
	s.top--;
	return ch;
	}
}
int priority(char x)
{
	if(x=='(')
	return 0;
	if(x=='+'||x=='-')
	return 1;
	if(x=='*'||x=='/')
	return 2;
	if(x=='$'||x=='^')
	return 3;
	return 0;
}
int main()
{
	char infix[100],postfix[100],ch;
	int i,j=0;
	printf("enter infix string=");
	gets(infix);
	init();
	for(i=0;infix[i]!='\0';i++)
	{
	if(isalpha(infix[i]))
	postfix[j++]=infix[i];
	else if(infix[i]=='(')
	push(infix[i]);
	else if(infix[i]==')')
	{
	while(ch=pop()!='(')
	postfix[j++]=ch;
	}
	else
	{
	while(priority(s.a[s.top])>=priority(infix[i]))
	{
	postfix[j++]=pop();
	}
	push(infix[i]);
	}
	}
	while(!isempty())
	{
	postfix[j++]=pop();
	}
	postfix[j]='\0';
	printf("\n postfix string=%s",postfix);	
}



