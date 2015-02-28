#include <stdio.h>
#define FINISH 1

int main(){

 int num1,num2,ans;
 
 printf("Enter two integers:");
 scanf("%d%d",&num1,&num2);
 printf("Mystery program...\n");
 
 if(0==num2)
 {
   printf("invalid input!\n");
 }
 else
 {
   for(ans=num1/num2;ans>=FINISH;ans=ans/2)
   {
    printf("%d\n",ans);
   }
 } 
 return 0;  
}
