#include<stdio.h>
void heapify(int a[],int n,int root);
void heap_sort(int a[],int n);
void printf_array(int a[],int n);
int main()
{
    int n,i,a[20];
    printf("enter number of elements:");
    scanf("%d",&n);
    printf("enter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf_array(a,n);

    heap_sort(a,n);
      printf("\nSorted array:");
      printf_array(a,n);

}
void heapify(int a[],int n,int root)
{
    int largest=root;
    int left=2*root+1;
    int right= 2*root+2;

    if(left<n&&a[left]>a[largest])
        largest= left;
    if(right<n&&a[right]>a[largest])
        largest=right;

    if(root!=largest)
    {
        int temp=a[root];
        a[root]=a[largest];
        a[largest]=temp;

        heapify(a,n,largest);
    }
}

void heap_sort(int a[],int n)
{ int i,j;
    for(i=n/2-1;i>=0;i--)
        heapify(a,n,i);

    for(j=n-1;j>=0;j--)
    {
        int temp=a[0];
        a[0]=a[j];
        a[j]=temp;
        heapify(a,j,0);
    }
}

void printf_array(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

}

