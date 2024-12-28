//******** BANK SYSTEM PROJECT *********. 
#include <stdio.h>
#include<stdlib.h>
typedef struct bank
{
    double accountNo[20];
    char name[50];
    int IFC_code;
    int balance;
    char branch[20];
    int Account;
    int amount;
	int A;
	int no,b;
}s;
void newentry(struct bank**,int,int);
void deposit(struct bank**,int,int,int );
void withdraw(struct bank**,int,int);
void search(struct bank**,int,int);
void Balance(struct bank**,int,int);
void Total_Entry(struct bank**,int,int);


int main()
{
   
     struct bank **p;
	 int i;
	 int size;
	 printf("enter the size of bank\n");
	 scanf("%d",&size);
	 
	 p=(struct bank**)malloc(size * sizeof(struct bank*));
     for(i=0;i<size;i++)
	   {
		   p[i]=(struct bank*)malloc(sizeof(struct bank));
	   }
    
    int ch,balance=0,cnt=0;
    
	 int accountNo=0;
    
    do
    { 
	   printf("\n\t********** BANK SYSTEM PROJECT ***********\n");
       printf("\n1.New Entry\n");
       printf("2.Deposit\n");
       printf("3.Withdraw\n");
       printf("4.Search\n");
       printf("5.Check Balance\n");
	   printf("6.Total Account Avaliable in bank\n");
       printf("7.Exit\n");
       printf("\nEnter The Choice\n");
       scanf("%d",&ch);
	   
       switch(ch)
{
          case 1:
                   printf("\n******* WELCOME TO APNA BANK ********\n");
		           int i;
                   accountNo++;
		           i++;
		 
                   newentry(p,i,accountNo);//Function calling.
		  
                   break;
     
         case 2:
        
                  deposit (p,size,i,accountNo);
         
                  break;
         case 3:
            
                  withdraw (p,size,accountNo);
				  
                  break;
         
         case 4:
                  search (p,size,accountNo);
                  
				  break;
         case 5:
                  Balance(p,size,accountNo);
          
                  break;
		 case 6:  
		          Total_Entry(p,size,accountNo);
				  
                   break;				  
				  
         case 7: 
		          printf("Thank You!!! \n");
				  
                  exit(0);
         default:
		          printf("Invalid Choice\n");
				  
				  
}         
       
    }while(ch!=8);
    
    return 0;
	
}
void newentry(struct bank **x,int c,int A)
{
	
	
	
	printf("\nEnter Account Holder Name\n");
	scanf(" %[^\n]",(*x+c)->name);
	printf("Enter IFC Code \n");
	scanf("%d",&(*x+c)->IFC_code);
	printf("Enter A Branch Name\n");
	scanf("%s",(*x+c)->branch);
	printf("Enter Minimum 500 Balance To Create New Entry\n");
	scanf("%d",&(*x+c)->amount);
	if((*x+c)->amount<500)
	{
		printf("Amount Is Less Than 500,Please Enter Minimum 500 Amount\n");
	}
	else
	{
	(*x+c)->balance=(*x+c)->amount;
	printf("Balance=%d\n",(*x+c)->balance);
	printf("Account number =%d\n",A);
	}
	
}
void deposit(struct bank**x ,int a,int c,int A)
{
	int no,i,flag=0;
	printf("Enter The Account Number\n");
	scanf("%d",&no);
	
	for(i=1;i<=A;i++)
	{
		if(no==i)
		{
		    flag=1;
		    break;
		}
	
	}
	if(flag==1)
	{
			printf("Enter The Amount You Want To Deposit\n");
			scanf("%d",&(*x+i)->amount);
			(*x+i)->balance+=(*x+i)->amount;
			printf("Amount Deposited Successfully.\n");
			printf("Total balance=%d\n",(*x+i)->balance);
			
	}
	else
	{
	    printf("Account Number Is Not Avaliable In Bank\n");
	}
	
}
void withdraw(struct bank**x ,int a,int A)
{
	int no,i,flag=0;
	printf("Enter The Account Number\n");
	scanf("%d",&no);

	for(i=1;i<=A;i++)
	{
		if(no==i)
		{
		    flag=1;
			break;
		}
	}
	if(flag==1)
	{
	  printf("Enter The Amount You Want To Withdraw\n");
			scanf("%d",&(*x+i)->amount);
			(*x+i)->balance-=(*x+i)->amount;
			
			
			if((*x+i)->balance<500)
			{
				(*x+i)->balance+=(*x+i)->amount;
			    printf("Total Balance Cannot Be Less Than 500 , Hence Can't Withdraw A Money\n");
			
				
			}
			else
		      {
				printf("Amount was Withdraw successfully from Your Bank.\n");
			    printf("Total balance=%d\n",(*x+i)->balance);
			  }
	}
	else
	{
	  	printf("Account Number Is Not Avaliable In Bank\n");
	}
	
}
void search(struct bank**x,int a,int A)
{
    int no,i;
    int flag=0;
    printf("Enter The Account Number You Want To Search\n");
    scanf("%d",&no);
    for(i=1;i<=A;i++)
    {
        if(no==i)
        {
            flag=1;
            break;
            
        }
    }
    if(flag==1)
    {
		printf("Account Found !!!\n");
		
        printf("*******All Information Of Account Holder*******\n");
		
        printf(" * Account Holder Name=%s\n",(*x+i)->name);
        printf(" * IFC Code=%d\n",(*x+i)->IFC_code);
        printf(" * Branch Name=%s\n",(*x+i)->branch);
        printf(" * Total Balance=%d\n",(*x+i)->balance);
        
    }
    else
    {
        printf("Account Number Is Not Avaliable In Bank\n");
        
    }
}
void Balance(struct  bank **x,int a, int A)
{
    int no,i;
    int flag=0;
    printf("Enter The Account Number To Check Total Balance\n");
    scanf("%d",&no);
    for(i=1;i<=A;i++)
    {
        if(no==i)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("TOTAL BALANCE =%d\n",(*x+i)->balance);
    }
    else
    {
        printf("Account Number Is Not Avaliable In Bank\n");
        
    }
    

}
void Total_Entry(struct bank**x,int a,int A)
{
	int p,i;
	
	printf("Total Account in bank=%d",A);
	
}
			
	
			
	
 