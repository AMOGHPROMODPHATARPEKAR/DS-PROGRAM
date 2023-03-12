#include<stdio.h>
#include<stdlib.h>
 typedef struct student{
 char name[20];
 int m1,m2,m3;
 float avg;
 }student;

 int main(){
 student s[20],temp;
 int i,j,n;
 printf("enter no of student\n");
 scanf("%d",&n);
 for(i=0;i<n;i++){
 printf("enter detalis of %d",i+1);
 scanf("%s %d %d %d",s[i].name,&s[i].m1,&s[i].m2,&s[i].m3);
 s[i].avg=(s[i].m1+s[i].m2+s[i].m3)/3.0;
 }//sorted based on avg
 for(i=0;i<n-1;i++)
 {
     for(j=0;j<n-i-1;j++){
        if(s[j].avg<s[j+1].avg){ //to sort name wise conditon
             temp=s[j];          //if(strcmp(s[j].name,s[j+1].name)<0)
            s[j]=s[j+1];
            s[j+1]=temp;
        }
     }
 }
 printf("sorted result\n");
 for(i=0;i<n;i++)
 {
     printf("%s\t%d\t%d\t%d\t%.2f\n",s[i].name,s[i].m1,s[i].m2,s[i].m3,s[i].avg);
 }
 }

