#include<stdio.h>
int largest(int a[],int n);
int countDigit(int n);
void radixSort(int a[],int n);
int main()
{
   int a[10],i,n;
   printf("enter number of elements:");
   scanf("%d",&n);
   printf("enter array elements:\n");
   for(i=0;i<n;i++)
    scanf("%d",&a[i]);
   radixSort(a,n);
   printf("sorted array:\n");
   for(i=0;i<n;i++)
    printf("%d ",a[i]);
}
int largest(int a[],int n)
{
    int large=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>large)
            large=a[i];
    }
    return large;
}
int countDigit(int num)
{ int count=0;
    while(num>0)
    {
        count++;
        num/=10;
    }
    return count;

}
 void radixSort(int a[],int n)
 {
     int totalbucket=10;
     int bucket[totalbucket][n],count_per_bucket[10];
     int i,j,k,NOP,rem,large;
     large= largest(a,n);
     NOP=countDigit(large);
     int div=1;
     for(int pass=0;pass<NOP;pass++)
     {
         for(i=0;i<10;i++)
            count_per_bucket[i]=0;

         for(i=0;i<n;i++)
         {
             rem=(a[i]/div)%10;
             bucket[rem][count_per_bucket[rem]]=a[i];
             count_per_bucket[rem]++;
         }
         i=0;
         for(k=0;k<10;k++)
         {
             for(j=0;j<count_per_bucket[k];j++)
             {
                 a[i]=bucket[k][j];
                 i++;
             }
         }
         div=div*10;
     }
 }
