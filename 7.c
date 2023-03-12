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
node *max_node(node *tree)
{
    if(tree->right==NULL)
    return tree;
    else
        return max_node(tree->right);
}
node *delete_node(node *root,int key)
{
    if(root==NULL){
        printf("not found");
        return root;
    }
    else if(key<root->data)
        root->left=delete_node(root->left,key);
    else if(key>root->data)
        root->right=delete_node(root->right,key);
    else {
        if(root->left!=NULL&&root->right!=NULL)//has 2 child
        {
            node *temp=max_node(root->left);
            root->data=temp->data;
            root->left=delete_node(root->left,temp->data);
        }
        else if(root->left==NULL&&root->right==NULL) //0 child
        {
            free(root);
            root=NULL;
        }
        else if(root->left==NULL)//only right child
            { node *temp=root;
        root=root->right;
        free(temp);
        }
        else {  //left child
            node *temp=root;
            root=root->left;
            free(temp);
        }
    }
    return root;
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
int main()
{
    node *rootp=NULL;
    int a[100],i,n,op,num,key;
    while(op!=5)
    {  printf("enter option:");
    scanf("%d",&op);
    switch(op)
    {
        case 1:printf("enter no of elements:");
    scanf("%d",&n);
    printf("enter elemnts\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        rootp=insert(rootp,a[i]);
    }
    break;

    case 2:printf("insert a number:");
    scanf("%d",&num);
    rootp=insert(rootp,num);
    break;

    case 3:printf("enter a number to be deleted:");
    scanf("%d",&key);
    rootp=delete_node(rootp,key);
    break;
    case 4:printf("INORDER TRAVERSAL OF TREE\n");
    inorder(rootp);
    break;
    case 5:printf("terminate");
    break;

    }


    }
}
