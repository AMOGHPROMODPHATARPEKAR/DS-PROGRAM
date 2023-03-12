#include<stdio.h>
#include<ctype.h>
char stack[20];
int top=-1;
void push(char x)
{
    stack[++top]=x;
}
char pop()
{
    if(top==-1)
    {
        return -1;
    }else
    return stack[top--];
}
int isempty()
{
    return top==-1;
}
int pr(char op)
{    if(op=='('||op==')')
return 0;
    if(op=='+'||op=='-')
        return 1;
    if(op=='*'||op=='/')
        return 2;
}

int main()
{
    char exp[20],x;
    int i=0;
    printf("enter infix expression\n");
    scanf("%s",exp);
    while(exp[i]!='\0')
    {      if(isalnum(exp[i]))
        printf("%c",exp[i]);
        else if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')')
        {
            while((x=pop())!='(')
            {
                printf("%c",x);
            }
        }
        else {
            while(!isempty()&&(pr(stack[top])>=pr(exp[i])))
        {
            printf("%c",pop());
        }
        push(exp[i]);
        }
        i++;
    }
    while(!isempty())
    {
        printf("%c",pop());
    }
}

