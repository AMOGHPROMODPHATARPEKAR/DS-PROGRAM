#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;

node *mt(int x){
node *p=(node*)malloc(sizeof(node));
p->data=x;
p->left=NULL;
p->right=NULL;
return p;
}
node *insert(node *tree,int data)
{
    if(tree==NULL)
    {
        return mt(data);
    }
    if(data<tree->data)
        tree->left=insert(tree->left,data);
    else
        tree->right=insert(tree->right,data);
    return tree;
}
void inorder(node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->left);
        printf("%d ",tree->data);
        inorder(tree->right);
    }
}
void preorder(node *tree)
{
    if(tree!=NULL)
    {
        printf("%d ",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}
void postorder(node *tree)
{
    if(tree!=NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ",tree->data);
    }
}
int main()
{
    node *rootp=NULL;
    int a[100],i,n;
    printf("enter no of elements:");
    scanf("%d",&n);
    printf("enter elemnts\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        rootp=insert(rootp,a[i]);
    }
    printf("INORDER TRAVERSAL OF TREE\n");
    inorder(rootp);
     printf("\nPREORDER TRAVERSAL OF TREE\n");
    preorder(rootp);
     printf("\nPOSTORDER TRAVERSAL OF TREE\n");
    postorder(rootp);

}
