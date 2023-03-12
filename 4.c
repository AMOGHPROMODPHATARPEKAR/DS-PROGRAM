#include<stdio.h>
#define max 5
 int stack[max];
 int top=-1;

 void push()
{ int ele;

  if(top==max-1)
    {
        printf("overflow");
        return;
    }
    printf("enter element:");
    scanf("%d",&ele);
    stack[++top]=ele;
}
int pop()
{
    if(top==-1){
        printf("underflow\n");
        return;
    }
    return stack[top--];
}
int peek()
{
   if(top==-1){
        printf("underflow\n");
        return;
    }
    return stack[top];
}
void display()
{
    if(top==-1){
        printf("stack is empty\n");
        return;
    }
    for(int i=top;i>=0;i--){
        printf("|%d|\n",stack[i]);
    }
    printf("======\n");
}
 int main(){
 int op=0,p,a;
 while(op!=5)
 {
     printf("enter option:");
     scanf("%d",&op);
     switch(op)
     {
         case 1:push();
         break;
        case 2: p=pop();
          printf("the popped element is %d\n",p);
         break;
         case 3:display();
         break;
         case 4:a=peek();
        printf("the top element of stack is %d\n",a);
         break;
         case 5: printf("program terminating...");
         break;
     }
 }
 }
