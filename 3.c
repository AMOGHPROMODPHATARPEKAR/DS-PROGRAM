#include<stdio.h>
#include<stdlib.h>
 typedef struct node {
     int data;
     struct node *left;
     struct node *right;
 }node;

 node *start=NULL;

 node *getnode()
 {
     node *p=(node*)malloc(sizeof(node));
     printf("enter data:");
     scanf("%d",&p->data);
     p->left=NULL;
     p->right=NULL;
     return p;
 }
 void insert_at_start()
 { if(start==NULL)
 {
     start=getnode();
     return;
 }

     node *nn=getnode();
     nn->right=start;
     start->left=nn;
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
        temp=temp->right;
     }
 }
 void insert_end(){
     if(start==NULL){
        start=getnode();
        return;
     }
 node *temp=start;
 while(temp->right!=NULL)
 {
     temp=temp->right;
 }
 node *nn =getnode();
 temp->right=nn;
 nn->left=temp;
 }

 void delete_s()
 {if(start==NULL)
 {
     printf("empty");
     return;
 }
     node *temp=start;
     start=start->right;
     free(temp);
 }
 void delete_end()
 { if(start==NULL)
 {
     printf("empty");
     return;
 }
  if(start->right==NULL)
  {
      start=NULL;
      free(start);
      return;
  }
     node *temp=start;
     while(temp->right!=NULL){
        temp=temp->right;
     }
     temp->left->right=NULL;
     free(temp);
 }
 int main()
 {
     int op=0;
     while(op!=6){
        printf("enter option:");
        scanf("%d",&op);
        switch(op){
        case 1:insert_at_start();
        break;
        case 2:traversal();
        break;
        case 3:insert_end();
        break;
        case 4:delete_s();
        break;
        case 5:delete_end();
        break;
        case 6:printf("program terminating\n");
        break;
        }
     }
 }

