#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int bTrue=1;
int balance = 1000;
int deposit;
int fastcash;
int myChoice;
int receipt;
int temp = 0;
int withdraw;
int *choice = &temp;
char pin;
int getCard(char);
int getFastCash(char);
int makeWithdraw(char);
int makeDeposit(char);
int getBalance(char);
void chooseTransaction();
int charLength(char *c);



int main(int bTrue)
{
	char pin[5];
	int i=0;
	int x=0;
    memset(pin,0,sizeof(pin));

	while(i<2)
	{
		if(i == 0)
		{
		    printf("          Welome to GarBank ATM          \n\n");
	        printf("\nPlease enter your 4 digit pin: ");
            scanf("%s",&pin);
		}
		++i;

		if( charLength(pin) == 4)
		{ 
			system("cls");
	        printf("\nWould you like a receipt?\n");
			printf("\n    1=YES     2=NO : \n");
			scanf("%d",&receipt);
			break;
        }
	    else
		{
			system("cls");
	        printf("\nInvalid pin, TRY AGAIN \n");
		    printf("\nPlease enter your 4 digit pin: ");
			memset(pin,0,sizeof(pin));
	        scanf("%s",&pin);

			if( charLength(pin) == 4)
			{
				system("cls");
				printf("\nWould you like a receipt?\n");
				printf("\n   1=YES    2=NO \n");
				scanf("%d",&receipt);
				break;
			}

			if(i==2)
			{
				system("cls");
                printf("\n\nSorry, invalid PIN \n");
	            printf("Please contact the bank for assistance\n");
                printf("GOODBYE\n\n");
				bTrue = 0;
				system("\npause");
			    return 0;
		     }
		}
	}
	
    if(receipt ==1 ||receipt == 2)
	{ 
	system("cls");
       chooseTransaction();
	}
        while(bTrue)
			{
	         switch(*choice)
		       {
			      case 1: getCard(pin);
					      bTrue=0;
				          break;

                   case 2: getFastCash(pin);
			               break;

		           case 3: makeWithdraw(pin);
			               break;

		           case 4: makeDeposit(pin);
			               break;

		           case 5: getBalance(pin);
			               break;

		           default: system("cls");
					        printf("Invalid choice.\n");
					        chooseTransaction();
              }        
		}
	printf("\n");

	if(bTrue==0)
	{
        system("pause");
	}
}
int charLength(char *c)
{
	char ct;
	int i = 0;
	while(ct = *(c+i))
	{
		if(ct =='\0'){
			break;
		}
		else{
			i++;
		}
	}
	return i;
}
int getCard(char *pin)
{
	 time_t mytime;
     mytime = time(NULL);
	 system("cls");
	 if(receipt == 1)
	 {
		 printf("\nThank you for using GarBank\n");
		 printf("\n          GOODBYE          \n");
		 printf("\n\n");
	     printf("************Receipt**********\n");
		 printf(" \n ");
		 printf(ctime(&mytime));
		 printf("\nCard Number   xxxx xxx  %c%c%c%c\n",pin[0],pin[1],pin[2],pin[3]);
		 printf("\n         ATM  GB0644\n");
		 printf("\n    Your balance is $%d\n",balance);
		 printf("\n\n");
		 printf("\n\n");
		 printf("************Receipt***********\n");
		 printf("\n\n");
         system("pause");
	     exit(0);
	 }
	 else
	 {
		 printf("\nThank you for using GarBank\n");
	     printf("\nGOODBYE\n");
		 system("pause");
	     exit(0);
	 }
}
int getFastCash(char *pin)
{
	int myChoice;

	system("cls");
	printf("\n    Choose amount\n");
	printf("1 = $10          2 = $20\n");
	printf("3 = $50          4 = $100\n");
	printf("Enter selection: ");
	scanf("%d",&fastcash);

	if(fastcash ==1)
	{
		system("cls");
		fastcash = 10;
        printf("\nThank you.Please take your $%d\n",fastcash);
		balance-=fastcash;
		printf("\nYour balance is $%d\n",balance);
    }
	else if(fastcash == 2)
	{
		system("cls");
		fastcash = 20;
		printf("\nThank you, Please take your $%d\n",fastcash);
	    balance-=fastcash;
		printf("\nYour balance is $%d\n",balance);
	}
	else if(fastcash == 3)
	{
		system("cls");
		fastcash = 50;
		printf("\nThank you, Please take your $%d\n",fastcash);
	    balance-=fastcash;
		printf("\nYour balance is $%d\n",balance);
    }
	else if(fastcash == 4)
	{
		system("cls");
		fastcash = 100;
		printf("\nThank you, Please take your $%d\n",fastcash);
	    balance-=fastcash;
		printf("\nYour balance is $%d\n",balance);
    }
	else
	{ system("cls");
		printf("\nYou have made an invalid selection\n");
	}
	printf("\nWould you like another transaction?\n");
	printf("\n    1=YES    2=NO\n");
	scanf("%d",&myChoice);
	
	if(myChoice==1)
	{
		system("cls");
		chooseTransaction();
	}
	if(myChoice==2)
	{
        getCard(pin);
		
	}
	if(myChoice != 1 && myChoice != 2)
	{
		system("cls");
		printf("Invalid entry\n");
		chooseTransaction();
	}
	return 0;
}
int makeWithdraw(char *pin)
{
	system("cls");
	printf("\nAmount of withdraw(in multiples of $10)\n");
	scanf("%d",&withdraw);
	if(withdraw > balance)
	{
		system("cls");
		printf("\nYour request is greater than your balance,\n");
		printf("\nPlease check your balance and try again.\n");
	}
	else if(withdraw %10 != 0)
	{
		system("cls");
        printf("\nYou must enter an amount in multiples of $10\n");
	}
	else
	{
		system("cls");
	    printf("\nThank you, please take your $%d.\n",withdraw);
	    balance-=withdraw;
		printf("\nYour balance is $%d\n",balance);
	}
	printf("\nWould you like to make another transaction\n");
	printf("\n    1=YES    2=NO\n");
	scanf("%d",&myChoice);
	
	if(myChoice==1)
	{
		system("cls");
		chooseTransaction();
	}
	if(myChoice==2)
	{
	    getCard(pin);
	}
	if(myChoice !=1 && myChoice !=2)
	{  
		system("cls");
		printf("Invalid entry\n");
		chooseTransaction();
		
	}
	return 0;
}
int makeDeposit(char *pin)
{
	system("cls");
	printf("\nDeposit amount $");
	scanf("%d",&deposit);
	balance += deposit;
	system("cls");
	printf("\nThank you, your $%d deposit has been confirmed.\n",deposit);
	printf("\nYour balance is $%d\n",balance);
    printf("\nWould you like to make another transaction\n");
	printf("\n    1=YES    2=NO\n");
	scanf("%d",&myChoice);
	
	if(myChoice==1)
	{
		system("cls");
		chooseTransaction();
	}
	if(myChoice==2)
	{
	    getCard(pin);
	}
	if(myChoice!=1 && myChoice !=2)
	{  
		system("cls");
		printf("Invalid entry\n");
		chooseTransaction();
	}
	return 0;
}
int getBalance(char *pin)
{
	system("cls");
	printf("\nYour balance is $%d\n",balance);
	printf("\nWould you like to make another transaction\n");
	printf("\n    1=YES    2=NO\n");
	scanf("%d",&myChoice);
	
	if(myChoice==1)
	{
		system("cls");
		chooseTransaction();
	}
	if(myChoice==2)
	{
	    getCard(pin);
	}
	if(myChoice !=1 && myChoice !=2)
	{  
		system("cls");
		printf("Invalid entry\n");
		chooseTransaction();
	}
}
void chooseTransaction()
{
    printf("\nChoose transaction:\n");
	printf("\n1. Get card\n");
	printf("2. Fast cash\n");
	printf("3. Withdraw\n");
	printf("4. Deposit\n");
	printf("5. Balance\n");
	printf("\nEnter your choice: ");
	scanf("%d",choice);
}
