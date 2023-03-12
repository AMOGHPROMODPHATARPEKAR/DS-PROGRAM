#include<stdio.h>
#define max 5
int queue[max];
int front=-1;
int rear=-1;
int isfull()
{
    if((rear+1==front)||(front==0&&rear==max-1))
        return 1;
    return 0;
}
int isempty()
{
    if(front==-1)
        return 1;
        else
    return 0;
}
void enq(int element)
{
    if(isfull())
    {
        printf("overflow");

    }
    else {
    if(front==-1)
    {
        front=rear=0;
    }
    else
    {
        rear=(rear+1)%max;
    }
    queue[rear]=element;
}
}
int deq()
{
    if(isempty())
    {
        printf("underflow");
        return;
    }
    int temp=queue[front];
    if(front == rear)
        front=rear=-1;
    else
        front=(front+1)%max;
    return temp;
}
void display()
{ int i;
    if(isempty())
    {
        printf("queue is empty\n");
        return;
    }
    printf("FRONT=%d\n",front);
    for(i=front;i!=rear;i=(i+1)%max)
    {
        printf("%d  ",queue[i]);
    }
    printf("%d",queue[i]);
    printf("\nREAR= %d",rear);
}
int main(){
 int op=0,ele,p,a;
 while(op!=4)
 {
     printf("enter option:");
     scanf("%d",&op);
     switch(op)
     {
         case 1:printf("enter element:");
         scanf("%d",&ele);
             enq(ele);
         break;
        case 2: p=deq();
          printf("the popped element is %d\n",p);
         break;
         case 3:display();
         break;
         case 4: printf("program terminating...");
         break;
     }
 }
 }

