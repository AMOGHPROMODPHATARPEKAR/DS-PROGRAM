#include<stdio.h>
#include<stdlib.h>
 typedef struct node {
     int data;
     struct node *next;
 }node;

 node *start=NULL;

 node *getnode()
 {
     node *p=(node*)malloc(sizeof(node));
     printf("enter data:");
     scanf("%d",&p->data);
     p->next=NULL;
     return p;
 }
 void insert_at_start()
 {

     node *nn=getnode();
     nn->next=start;
     start=nn;
 }
 void traversal()
 {
     if(start==NULL){
        printf("empty list\n");
        return;
     }
     node *temp=start;
     while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
     }
 }
 void insert_end(){
     if(start==NULL){
        start=getnode();
        return;
     }
 node *temp=start;
 while(temp->next!=NULL)
 {
     temp=temp->next;
 }
 temp->next=getnode();
 }
 void insert_after()
 { int key;
     printf("enter existing element:");
     scanf("%d",&key);
     node *temp=start;
     while(temp!=NULL)
     {
         if(key==temp->data){
            node *nn=getnode();
            nn->next=temp->next;
            temp->next=nn;
            return;
         }
         temp=temp->next;
     }
     printf("element not found\n");
 }
 void delete_s()
 {if(start==NULL)
 {
     printf("empty");
     return;
 }
     node *temp=start;
     start=start->next;
     free(temp);
 }
 void delete_end()
 {
     node *prev=NULL,*cur=start;
     if(start==NULL)
 {
     printf("empty");
     return;
 }

 node *temp=start;
 while(cur->next!=NULL){
    prev=cur;
    cur=cur->next;
 }
 free(cur);
 if(prev!=NULL)
    prev->next=NULL;
 else
    start=NULL;
 }
 void delete_node()
 { int key;
     printf("enter node: ");
     scanf("%d",&key);
     node *prev = NULL,*cur=start;
     while(cur!=NULL)
     {
         if(cur->data==key){
            if(prev!=NULL)
                prev->next=cur->next;
            else
                start=start->next;
            free(cur);
            return;
         }
         prev=cur;
         cur=cur->next;
 }
 }

 int main()
 {
     int op=0;
     while(op!=8){
        printf("enter option:");
        scanf("%d",&op);
        switch(op){
        case 1:insert_at_start();
        break;
        case 2:traversal();
        break;
        case 3: insert_end();
        break;
        case 4:insert_after();
        break;
        case 5:delete_s();
        break;
        case 6:delete_end();
        break;
        case 7:delete_node();
        break;
        case 8:printf("program terminating\n");
        break;
        }
     }
 }
