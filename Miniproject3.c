#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main(){
printf("*******Simple Calculator*******");
printf("Enter the choice\n");
printf("1.Add numbers\n");
printf("2.Subract Numbbers\n");
printf("3.Multiply Numbers\n");
printf("4.Divide Numbers\n");
printf("5.Absolute Sum\n");
printf("6.Absolute Subraction\n");
int choice,first,second,result;
printf("Enter 1st Number: ");
scanf("%d",&first);
printf("Enter 2nd Number: ");
scanf("%d",&second);
printf("Enter the choice: ");
scanf("%d",&choice);
switch (choice) {
  case 1:
      result=add(first,second);
      break;
  case 2:
      result=subract(first,second);
      break;
  case 3:
      result=Multiply(first,second);
      break;
  case 4:
      result=divide(first,second);
      break;
  case 5:
      result=abs_sum(first,second);
      break;
  case 6:
      result=abs_sub(first,second);
      break;
  default:
      printf("Invalid");
      break;
}
printf("The result of equation is %d",result);

}



int add(int a,int b){
  return (float)a+b;
}

int subract(int a,int b){
  return (float)a-b;
}
int Multiply(int a,int b){
  return (float)a*b;
}

int divide(int a,int b){
  return (float)a/b;
}

int abs_sum(int a,int b){
  return (float)abs(a+b);
}
int abs_sub(int a,int b){
  return abs(a-b);
}
