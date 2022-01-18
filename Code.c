#include<stdio.h>
#include<stdlib.h>
#define Max_num 100


struct bankaccount{
  char name[101];
  int age;
  int account_number;
  int Pan_number;
  int ammount;
  int loan_pending;
}accounts[Max_num];

int account_number=1,index=0;
void main(){
    printf("******Welcome to the banking Portal******");
    int loop=1;
    while(loop){
      printf("enter your choice\n1.Create account\n2.Transfer ammount\n3.Check_balance\n4.GetLoan\n5.Delete account\n6.Exit\n");
      int choice;
      scanf("%d",&choice);
      if(choice==1){
        create_account();
      }
      else if(choice==2){
        int from,to,ammount;
        printf("Enter your bank account: ");
        scanf("%d",&from);
        printf("Enter Account number of reciver: ");
        scanf("%d",&to);
        printf("Enter your ammount to transfer: ");
        scanf("%d",&ammount);
        transfer_ammount(from,to,ammount);
      }
      else if(choice==3){
        int from,from_index;
        printf("Enter Your bank Account Number: ");
        scanf("%d",&from);
        from_index=find_from_account(from);
        if(from_index!=-1)
          printf("The balance ammount is %d\n",accounts[from_index].ammount);
        else
          printf("Account not found");
      }
      else if(choice==4){
        give_loan();
        }
      else if(choice==5){
        int from,from_index;
        printf("Enter the account number you need to delete: ");
        scanf("%d",&from);
        from_index=find_from_account(from);
        if(from_index!=-1){
          printf("Account Deleted!!\n");
          for (int i=from_index;i<Max_num;i++){
            accounts[i]=accounts[i+1];
          }
        }
        else
          printf("Invalid account Number\n");
        }
      else if (choice==6){
        loop=0;
      }

      }

    }

void create_account(){
  struct bankaccount temp=accounts[index];
  printf("Enter Your name: ");
  scanf("%s",&accounts[index].name);
  printf("Enter Your age: ");
  scanf("%d",&accounts[index].age);
  printf("Enter Your Pan_number: ");
  scanf("%d",&accounts[index].Pan_number);
  printf("Enter Your ammount: ");
  scanf("%d",&accounts[index].ammount);
  accounts[index].account_number=account_number;
  account_number++;
  printf("Account created\n");
  printf("name:%s\nAge:%d\nPan_number:%d\nAmmount:%d\nAccount_number:%d\n",accounts[index].name,accounts[index].age,accounts[index].Pan_number,accounts[index].ammount,accounts[index].account_number);
  index++;
}


void transfer_ammount(int from,int to,int ammount){
/*finding account with from and to account numbers*/
int from_index,to_index;
from_index=find_from_account(from);
to_index=find_to_account(to);
if(from_index==-1||to_index==-1)
  printf("Given Information is wrong\n");
else{
    accounts[from_index].ammount-=ammount;
    accounts[to_index].ammount+=ammount;
    printf("Ammount Transfered\n");
    printf("Your current balance is %d",accounts[from_index].ammount);
}

}

void give_loan(){
  int ammount,from,from_index,ch;
  printf("Enter your bank account_number: ");
  scanf("%d",&from);
  from_index=find_from_account(from);
  if(from_index!=-1){
    int loan_count=accounts[from_index].loan_pending;
    if(loan_count>2)
      printf("You can't get loans already maximum ammount reached");
    else{
      long int ammount;
      float interest,result;
      printf("Enter the ammount you want: ");
      scanf("%ld",&ammount);
      printf("\nTenor in 10 years\n");
      printf("Enter your choice:\n1.Home loan\n2.Car loan\n3.Education Loan\n");
      scanf("%d",&ch);

      if (ch==1){
        interest=0.1;
      }
      else if(ch==2){
        interest=0.08;
      }
      else if (ch==3){
        interest=0.06;
      }
      result=interest*ammount*10;
      printf("interest ammount is %.2f\n",result+ammount);
      accounts[from_index].ammount+=ammount;
      accounts[from_index].loan_pending++;
    }
}
  else{
    printf("Account is invalid");
  }
}



int find_from_account(int from){
  int from_index,flag1=0;
  for(int i=0;i<Max_num;i++){
    if(accounts[i].account_number==from){
      from_index=i;
      flag1=1;
      break;
    }
  }
  if(flag1==0){
    return -1;
  }
  else{
    return from_index;
  }
  return  -1;
}

int find_to_account(int to){
  int to_index,flag1=0;
  for(int i=0;i<Max_num;i++){
    struct bankaccount t=accounts[i];
    if(t.account_number==to){
      to_index=i;
      flag1=1;
    }
  }
  if(flag1==0){
    return -1;
  }
  else{
    return to_index;
  }

}
